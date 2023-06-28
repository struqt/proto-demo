package gateway

import (
	"context"
	"fmt"
	"net/http"
	"path"
	"strings"

	"github.com/golang/glog"
	gate "github.com/grpc-ecosystem/grpc-gateway/v2/runtime"
)

// Endpoint describes a gRPC endpoint
type endpoint struct {
	Network, Addr string
}

// Options is a set of options to be passed to Run
type options struct {
	// Addr is the address to listen
	Addr string
	// GRPCServer defines an endpoint of a gRPC service
	GRPCServer endpoint
	// OpenAPIDir is a path to a directory from which the server
	// serves OpenAPI specs.
	OpenAPIDir string
	// Mux is a list of options to be passed to the gRPC-Gateway multiplexer
	Mux []gate.ServeMuxOption
}

// Run starts an HTTP server and blocks while running if successful.
// The server will be shutdown when "ctx" is canceled.
func run(ctx context.Context, opts options) error {
	ctx, cancel := context.WithCancel(ctx)
	defer cancel()

	conn, err := dial(ctx, opts.GRPCServer.Network, opts.GRPCServer.Addr)
	if err != nil {
		return err
	}

	go func() {
		<-ctx.Done()
		if err := conn.Close(); err != nil {
			glog.Errorf("Failed to close a client connection to the gRPC server: %v", err)
		}
	}()

	handler := gate.NewServeMux(opts.Mux...)
	if err = serviceHandler(ctx, conn, handler); err != nil {
		return err
	}

	mux := http.NewServeMux()
	mux.Handle("/", handler)
	mux.HandleFunc("/healthz", healthHandler(conn))
	mux.HandleFunc("/openapiv2/", openApiHandler(opts.OpenAPIDir))

	s := &http.Server{
		Addr:    opts.Addr,
		Handler: allowCORS(mux),
	}

	go func() {
		<-ctx.Done()
		glog.Infof("Shutting down the http server")
		if err := s.Shutdown(context.Background()); err != nil {
			glog.Errorf("Failed to shutdown http server: %v", err)
		}
	}()

	fmt.Printf("Starting gRPC gateway server: --> %s://%s --> %s://%s\n",
		"http", opts.Addr, "grpc", opts.GRPCServer.Addr)
	if err := s.ListenAndServe(); err != http.ErrServerClosed {
		glog.Errorf("Failed to listen and serve: %v", err)
		return err
	}
	return nil
}

// allowCORS allows Cross Origin Resoruce Sharing from any origin.
// Don't do this without consideration in production systems.
func allowCORS(h http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		if origin := r.Header.Get("Origin"); origin != "" {
			w.Header().Set("Access-Control-Allow-Origin", origin)
			if r.Method == "OPTIONS" && r.Header.Get("Access-Control-Request-Method") != "" {
				preflightHandler(w, r)
				return
			}
		}
		//ctx := r.Context()
		//log.Info(r.URL, r.Header["User-Agent"], ctx)
		h.ServeHTTP(w, r)
	})
}

// preflightHandler adds the necessary headers in order to serve
// CORS from any origin using the methods "GET", "HEAD", "POST", "PUT", "DELETE"
// We insist, don't do this without consideration in production systems.
func preflightHandler(w http.ResponseWriter, r *http.Request) {
	headers := []string{"Content-Type", "Accept", "Authorization"}
	w.Header().Set("Access-Control-Allow-Headers", strings.Join(headers, ","))
	methods := []string{"GET", "HEAD", "POST", "PUT", "DELETE"}
	w.Header().Set("Access-Control-Allow-Methods", strings.Join(methods, ","))
	glog.Infof("preflight request for %s", r.URL.Path)
}

// openApiHandler returns OpenAPI specification files located under "/openapiv2/"
func openApiHandler(dir string) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		if !strings.HasSuffix(r.URL.Path, ".swagger.json") {
			glog.Errorf("Not Found: %s", r.URL.Path)
			http.NotFound(w, r)
			return
		}
		glog.Infof("Serving %s", r.URL.Path)
		p := strings.TrimPrefix(r.URL.Path, "/openapiv2/")
		p = path.Join(dir, p)
		http.ServeFile(w, r, p)
	}
}
