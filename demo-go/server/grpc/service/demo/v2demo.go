package demo

import (
	"context"
	v "github.com/struqt/proto/struqt/demo/v2"
)

type v2demo struct {
	v.UnimplementedBasicServiceServer
}

func (*v2demo) Echo(_ context.Context, req *v.EchoRequest) (resp *v.EchoResponse, err error) {
	resp = &v.EchoResponse{
		Version: 2,
		Value:   req.GetValue() + " ~ ~",
	}
	return
}

func (*v2demo) JsonRpc(context.Context, *v.JsonRpcRequest) (resp *v.JsonRpcResponse, _ error) {
	resp = &v.JsonRpcResponse{}
	return
}
