package common

import (
	v1 "github.com/struqt/proto/struqt/common/v1"
	"google.golang.org/grpc"
)

func Register(s grpc.ServiceRegistrar) {
	v1.RegisterCommonServiceServer(s, new(v1common))
}
