package grpc

import (
	"context"
	"fmt"
	"net"
	"os"

	log "github.com/golang/glog"
	"github.com/struqt/proto-demo/demo-go/server"
	"github.com/struqt/proto-demo/demo-go/server/grpc/service/common"
	"github.com/struqt/proto-demo/demo-go/server/grpc/service/demo"
	"google.golang.org/grpc"
	"google.golang.org/grpc/reflection"
)

func Start() {
	defer log.Flush()
	ctx := context.Background()
	if err := serve(ctx, server.Network(), server.Address()); err != nil {
		log.Fatal(err)
	}
	// grpcurl -plaintext -d '{"value":"hi"}' 127.0.0.1:9090 struqt.demo.v1.DemoService.Echo
	// grpcurl -plaintext -d '{"value":"hi"}' 127.0.0.1:9090 struqt.demo.v2.BasicService.Echo
	// grpcurl -plaintext -d '{"value":"hi"}' 127.0.0.1:9090 struqt.demo.v3.DemoService.EchoValue
	// grpcurl -plaintext -d '{"value":[{},[],false,null,0.5,"hello"]}' 127.0.0.1:9090 struqt.demo.v3.DemoService.EchoValue | jq
}

func register(s grpc.ServiceRegistrar) {
	common.Register(s)
	demo.Register(s)
}

func serve(ctx context.Context, network, address string) error {
	if err := removeSockFile(network, address); err != nil {
		return err
	}
	l, err := net.Listen(network, address)
	if err != nil {
		return err
	}
	defer func() {
		err := l.Close()
		if err != nil {
			log.Errorf("Failed to close %s %s: %v", network, address, err)
			return
		}
		_ = removeSockFile(network, address)
	}()
	s := grpc.NewServer()
	reflection.Register(s)
	register(s)
	go func() {
		<-ctx.Done()
		log.Info("shutdown")
		s.GracefulStop()
	}()
	fmt.Printf("Starting gRPC server: --> %s://%s\n", "grpc", address)
	return s.Serve(l)
}

func removeSockFile(network, address string) error {
	if "unix" == network && fileExists(address) {
		if err := os.Remove(address); err != nil {
			log.Errorf("Failed to remove %s: %v", address, err)
			return err
		}
	}
	return nil
}

func fileExists(filename string) bool {
	if _, err := os.Stat(filename); os.IsNotExist(err) {
		return false
	}
	return true
}
