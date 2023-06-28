package main

import (
	"github.com/struqt/proto-demo/demo-go/server"
	"github.com/struqt/proto-demo/demo-go/server/gateway"
	"github.com/struqt/proto-demo/demo-go/server/grpc"
)

func main() {
	if server.IsGateway() {
		gateway.Start("localhost:8080")
	} else {
		grpc.Start()
	}
}
