package main

import (
	"github.com/struqt/proto-demo/demo-go/server/gateway"
)

func main() {
	gateway.Start("localhost:8080")
}
