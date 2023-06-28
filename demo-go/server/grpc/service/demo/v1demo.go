package demo

import (
	"context"
	"google.golang.org/grpc/codes"
	"google.golang.org/grpc/status"

	v "github.com/struqt/proto/struqt/demo/v1"
)

type v1demo struct {
	v.UnimplementedBasicServiceServer
	v.UnimplementedDemoServiceServer
}

func (*v1demo) JsonRpc(context.Context, *v.JsonRpcRequest) (*v.JsonRpcResponse, error) {
	return nil, status.Errorf(codes.Unimplemented, "method JsonRpc not implemented !!!")
}

func (*v1demo) Echo(_ context.Context, req *v.EchoRequest) (resp *v.EchoResponse, err error) {
	resp = &v.EchoResponse{
		Version: 1,
		Value:   req.GetValue() + " ~",
	}
	return
}
