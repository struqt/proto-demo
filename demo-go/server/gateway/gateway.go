package gateway

import (
	"context"
	"fmt"
	"net"
	"net/http"

	gw "github.com/grpc-ecosystem/grpc-gateway/v2/runtime"
	_ "google.golang.org/genproto/googleapis/rpc/errdetails"
	"google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure"

	v1common "github.com/struqt/proto/struqt/common/v1"
	v1demo "github.com/struqt/proto/struqt/demo/v1"
	v2demo "github.com/struqt/proto/struqt/demo/v2"
	v3demo "github.com/struqt/proto/struqt/demo/v3"
)

// newGateway returns a new gateway server which translates HTTP into gRPC.
func newGateway(ctx context.Context, conn *grpc.ClientConn, opts []gw.ServeMuxOption) (http.Handler, error) {
	mux := gw.NewServeMux(opts...)
	type Fn func(context.Context, *gw.ServeMux, *grpc.ClientConn) error
	for _, f := range []Fn{
		v1common.RegisterCommonServiceHandler,
		v1demo.RegisterDemoServiceHandler,
		v1demo.RegisterBasicServiceHandler,
		v2demo.RegisterBasicServiceHandler,
		v3demo.RegisterDemoServiceHandler,
	} {
		if err := f(ctx, mux, conn); err != nil {
			return nil, err
		}
	}
	return mux, nil
}

func dial(ctx context.Context, network, addr string) (*grpc.ClientConn, error) {
	switch network {
	case "tcp":
		return dialTCP(ctx, addr)
	case "unix":
		return dialUnix(ctx, addr)
	default:
		return nil, fmt.Errorf("unsupported network type %q", network)
	}
}

// dialTCP creates a client connection via TCP.
// "addr" must be a valid TCP address with a port number.
func dialTCP(ctx context.Context, addr string) (*grpc.ClientConn, error) {
	return grpc.DialContext(ctx, addr, grpc.WithTransportCredentials(insecure.NewCredentials()))
}

// dialUnix creates a client connection via a unix domain socket.
// "addr" must be a valid path to the socket.
func dialUnix(ctx context.Context, addr string) (*grpc.ClientConn, error) {
	d := func(ctx context.Context, addr string) (net.Conn, error) {
		return (&net.Dialer{}).DialContext(ctx, "unix", addr)
	}
	return grpc.DialContext(ctx, addr, grpc.WithTransportCredentials(insecure.NewCredentials()), grpc.WithContextDialer(d))
}
