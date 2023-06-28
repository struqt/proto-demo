package common

import (
	"context"
	v "github.com/struqt/proto/struqt/common/v1"

	"google.golang.org/protobuf/types/known/timestamppb"
)

type v1common struct {
	v.UnsafeCommonServiceServer
}

func (*v1common) GetServerInfo(_ context.Context, _ *v.GetServerInfoRequest) (*v.GetServerInfoResponse, error) {
	return &v.GetServerInfoResponse{
		ServerId:  998,
		StartedAt: nil,
		Status:    v.ServerStatus_SERVER_STATUS_RUNNING,
		Timestamp: timestamppb.Now(),
	}, nil
}
