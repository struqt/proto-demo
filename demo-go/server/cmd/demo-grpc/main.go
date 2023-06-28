package main

import (
	"fmt"
	"github.com/struqt/proto-demo/demo-go/server/cmd"
)

func main() {
	fmt.Println("Starting gRPC server")
	cmd.RunGrpcServer()
}
