package cmd

import (
	"context"
	"net"
	"os"

	log "github.com/golang/glog"
	"google.golang.org/grpc"
	"google.golang.org/grpc/reflection"

	"github.com/struqt/proto-demo/demo-go/server/service/demo"
)

func RunGrpcServer() {
	defer log.Flush()
	ctx := context.Background()
	if err := serve(ctx, *network, *address); err != nil {
		log.Fatal(err)
	}
	// grpcurl -plaintext -d '{"value":"hi"}' 127.0.0.1:9090 struqt.demo.v1.DemoService.Echo
	// grpcurl -plaintext -d '{"value":"hi"}' 127.0.0.1:9090 struqt.demo.v2.BasicService.Echo
	// grpcurl -plaintext -d '{"value":"hi"}' 127.0.0.1:9090 struqt.demo.v3.DemoService.EchoValue
	// grpcurl -plaintext -d '{"value":[{},[],false,null,0.5,"hello"]}' 127.0.0.1:9090 struqt.demo.v3.DemoService.EchoValue | jq
}

func serve(ctx context.Context, network, address string) error {
	if "unix" == network && fileExists(address) {
		if err := os.Remove(address); err != nil {
			log.Errorf("Failed to remove %s: %v", address, err)
			return err
		}
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
		if "unix" == network && fileExists(address) {
			if err := os.Remove(address); err != nil {
				log.Errorf("Failed to remove %s: %v", address, err)
			}
		}
	}()
	s := grpc.NewServer()
	demo.RegisterService(s)
	//basic.RegisterGrpc(s)
	reflection.Register(s)
	go func() {
		<-ctx.Done()
		log.Info("shutdown")
		s.GracefulStop()
	}()
	log.Warningf("%s %s", network, address)
	return s.Serve(l)
}

func fileExists(filename string) bool {
	if _, err := os.Stat(filename); os.IsNotExist(err) {
		return false
	}
	return true
}
