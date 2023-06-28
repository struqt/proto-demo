package main

import (
	"fmt"
	"github.com/struqt/proto-demo/demo-go/server/cmd"
)

func main() {
	fmt.Println("Starting gRPC gateway server")
	cmd.RunGateway("127.0.0.1:8080")
}
