package demo

import (
	"context"
	v "github.com/struqt/proto/struqt/demo/v2"
)

type implement2 struct {
	v.UnimplementedBasicServiceServer
}

func (*implement2) Echo(_ context.Context, req *v.EchoRequest) (resp *v.EchoResponse, err error) {
	resp = &v.EchoResponse{
		Version: 2,
		Value:   req.GetValue() + " ~ ~",
	}
	return
}

func (*implement2) JsonRpc(context.Context, *v.JsonRpcRequest) (resp *v.JsonRpcResponse, _ error) {
	resp = &v.JsonRpcResponse{}
	return
}
