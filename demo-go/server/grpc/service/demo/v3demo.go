package demo

import (
	"context"
	"google.golang.org/protobuf/types/known/timestamppb"

	v "github.com/struqt/proto/struqt/demo/v3"
)

type v3demo struct {
	v.UnimplementedDemoServiceServer
}

func (*v3demo) EchoValue(_ context.Context, req *v.EchoValueRequest) (*v.EchoValueResponse, error) {
	return &v.EchoValueResponse{
		Value:     req.GetValue(),
		Timestamp: timestamppb.Now(),
	}, nil
}
