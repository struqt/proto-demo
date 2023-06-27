package demo

import (
	"context"
	"google.golang.org/grpc/codes"
	"google.golang.org/grpc/status"

	v "github.com/struqt/proto/struqt/demo/v1"
)

type implement1 struct {
	v.UnimplementedBasicServiceServer
	v.UnimplementedDemoServiceServer
}

func (*implement1) JsonRpc(context.Context, *v.JsonRpcRequest) (*v.JsonRpcResponse, error) {
	return nil, status.Errorf(codes.Unimplemented, "method JsonRpc not implemented !!!")
}

func (*implement1) Echo(_ context.Context, req *v.EchoRequest) (resp *v.EchoResponse, err error) {
	resp = &v.EchoResponse{
		Version: 1,
		Value:   req.GetValue() + " ~",
	}
	return
}
