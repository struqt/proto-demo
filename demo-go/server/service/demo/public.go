package demo

import (
	"google.golang.org/grpc"

	v1 "github.com/struqt/proto/struqt/demo/v1"
	v2 "github.com/struqt/proto/struqt/demo/v2"
	v3 "github.com/struqt/proto/struqt/demo/v3"
)

func RegisterService(s grpc.ServiceRegistrar) {

	imp1 := new(implement1)
	v1.RegisterBasicServiceServer(s, imp1)
	v1.RegisterDemoServiceServer(s, imp1)

	imp2 := new(implement2)
	v2.RegisterBasicServiceServer(s, imp2)

	imp3 := new(implement3)
	v3.RegisterDemoServiceServer(s, imp3)
}
