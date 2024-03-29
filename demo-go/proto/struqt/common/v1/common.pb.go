// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.32.0
// 	protoc        v4.24.3
// source: struqt/common/v1/common.proto

package common

import (
	_ "google.golang.org/genproto/googleapis/api/annotations"
	protoreflect "google.golang.org/protobuf/reflect/protoreflect"
	protoimpl "google.golang.org/protobuf/runtime/protoimpl"
	timestamppb "google.golang.org/protobuf/types/known/timestamppb"
	reflect "reflect"
	sync "sync"
)

const (
	// Verify that this generated code is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(20 - protoimpl.MinVersion)
	// Verify that runtime/protoimpl is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(protoimpl.MaxVersion - 20)
)

type ServerStatus int32

const (
	ServerStatus_SERVER_STATUS_UNSPECIFIED ServerStatus = 0
	ServerStatus_SERVER_STATUS_INITIAL     ServerStatus = 1
	ServerStatus_SERVER_STATUS_STARTING    ServerStatus = 2
	ServerStatus_SERVER_STATUS_RUNNING     ServerStatus = 3
	ServerStatus_SERVER_STATUS_SHUTDOWN    ServerStatus = 4
)

// Enum value maps for ServerStatus.
var (
	ServerStatus_name = map[int32]string{
		0: "SERVER_STATUS_UNSPECIFIED",
		1: "SERVER_STATUS_INITIAL",
		2: "SERVER_STATUS_STARTING",
		3: "SERVER_STATUS_RUNNING",
		4: "SERVER_STATUS_SHUTDOWN",
	}
	ServerStatus_value = map[string]int32{
		"SERVER_STATUS_UNSPECIFIED": 0,
		"SERVER_STATUS_INITIAL":     1,
		"SERVER_STATUS_STARTING":    2,
		"SERVER_STATUS_RUNNING":     3,
		"SERVER_STATUS_SHUTDOWN":    4,
	}
)

func (x ServerStatus) Enum() *ServerStatus {
	p := new(ServerStatus)
	*p = x
	return p
}

func (x ServerStatus) String() string {
	return protoimpl.X.EnumStringOf(x.Descriptor(), protoreflect.EnumNumber(x))
}

func (ServerStatus) Descriptor() protoreflect.EnumDescriptor {
	return file_struqt_common_v1_common_proto_enumTypes[0].Descriptor()
}

func (ServerStatus) Type() protoreflect.EnumType {
	return &file_struqt_common_v1_common_proto_enumTypes[0]
}

func (x ServerStatus) Number() protoreflect.EnumNumber {
	return protoreflect.EnumNumber(x)
}

// Deprecated: Use ServerStatus.Descriptor instead.
func (ServerStatus) EnumDescriptor() ([]byte, []int) {
	return file_struqt_common_v1_common_proto_rawDescGZIP(), []int{0}
}

type GetServerInfoRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields
}

func (x *GetServerInfoRequest) Reset() {
	*x = GetServerInfoRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_struqt_common_v1_common_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *GetServerInfoRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*GetServerInfoRequest) ProtoMessage() {}

func (x *GetServerInfoRequest) ProtoReflect() protoreflect.Message {
	mi := &file_struqt_common_v1_common_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use GetServerInfoRequest.ProtoReflect.Descriptor instead.
func (*GetServerInfoRequest) Descriptor() ([]byte, []int) {
	return file_struqt_common_v1_common_proto_rawDescGZIP(), []int{0}
}

type GetServerInfoResponse struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	ServerId  int32                  `protobuf:"varint,22,opt,name=server_id,json=serverId,proto3" json:"server_id,omitempty"`
	StartedAt *timestamppb.Timestamp `protobuf:"bytes,23,opt,name=started_at,json=startedAt,proto3" json:"started_at,omitempty"`
	Status    ServerStatus           `protobuf:"varint,24,opt,name=status,proto3,enum=struqt.common.v1.ServerStatus" json:"status,omitempty"`
	Timestamp *timestamppb.Timestamp `protobuf:"bytes,25,opt,name=timestamp,proto3" json:"timestamp,omitempty"`
}

func (x *GetServerInfoResponse) Reset() {
	*x = GetServerInfoResponse{}
	if protoimpl.UnsafeEnabled {
		mi := &file_struqt_common_v1_common_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *GetServerInfoResponse) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*GetServerInfoResponse) ProtoMessage() {}

func (x *GetServerInfoResponse) ProtoReflect() protoreflect.Message {
	mi := &file_struqt_common_v1_common_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use GetServerInfoResponse.ProtoReflect.Descriptor instead.
func (*GetServerInfoResponse) Descriptor() ([]byte, []int) {
	return file_struqt_common_v1_common_proto_rawDescGZIP(), []int{1}
}

func (x *GetServerInfoResponse) GetServerId() int32 {
	if x != nil {
		return x.ServerId
	}
	return 0
}

func (x *GetServerInfoResponse) GetStartedAt() *timestamppb.Timestamp {
	if x != nil {
		return x.StartedAt
	}
	return nil
}

func (x *GetServerInfoResponse) GetStatus() ServerStatus {
	if x != nil {
		return x.Status
	}
	return ServerStatus_SERVER_STATUS_UNSPECIFIED
}

func (x *GetServerInfoResponse) GetTimestamp() *timestamppb.Timestamp {
	if x != nil {
		return x.Timestamp
	}
	return nil
}

type Dummy struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	Version    int32  `protobuf:"varint,1,opt,name=version,proto3" json:"version,omitempty"`
	VersionTag string `protobuf:"bytes,2,opt,name=version_tag,json=versionTag,proto3" json:"version_tag,omitempty"`
}

func (x *Dummy) Reset() {
	*x = Dummy{}
	if protoimpl.UnsafeEnabled {
		mi := &file_struqt_common_v1_common_proto_msgTypes[2]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *Dummy) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*Dummy) ProtoMessage() {}

func (x *Dummy) ProtoReflect() protoreflect.Message {
	mi := &file_struqt_common_v1_common_proto_msgTypes[2]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use Dummy.ProtoReflect.Descriptor instead.
func (*Dummy) Descriptor() ([]byte, []int) {
	return file_struqt_common_v1_common_proto_rawDescGZIP(), []int{2}
}

func (x *Dummy) GetVersion() int32 {
	if x != nil {
		return x.Version
	}
	return 0
}

func (x *Dummy) GetVersionTag() string {
	if x != nil {
		return x.VersionTag
	}
	return ""
}

var File_struqt_common_v1_common_proto protoreflect.FileDescriptor

var file_struqt_common_v1_common_proto_rawDesc = []byte{
	0x0a, 0x1d, 0x73, 0x74, 0x72, 0x75, 0x71, 0x74, 0x2f, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2f,
	0x76, 0x31, 0x2f, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x12,
	0x10, 0x73, 0x74, 0x72, 0x75, 0x71, 0x74, 0x2e, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2e, 0x76,
	0x31, 0x1a, 0x1c, 0x67, 0x6f, 0x6f, 0x67, 0x6c, 0x65, 0x2f, 0x61, 0x70, 0x69, 0x2f, 0x61, 0x6e,
	0x6e, 0x6f, 0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x73, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x1a,
	0x1f, 0x67, 0x6f, 0x6f, 0x67, 0x6c, 0x65, 0x2f, 0x61, 0x70, 0x69, 0x2f, 0x66, 0x69, 0x65, 0x6c,
	0x64, 0x5f, 0x62, 0x65, 0x68, 0x61, 0x76, 0x69, 0x6f, 0x72, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f,
	0x1a, 0x1f, 0x67, 0x6f, 0x6f, 0x67, 0x6c, 0x65, 0x2f, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x62, 0x75,
	0x66, 0x2f, 0x74, 0x69, 0x6d, 0x65, 0x73, 0x74, 0x61, 0x6d, 0x70, 0x2e, 0x70, 0x72, 0x6f, 0x74,
	0x6f, 0x22, 0x1c, 0x0a, 0x14, 0x47, 0x65, 0x74, 0x53, 0x65, 0x72, 0x76, 0x65, 0x72, 0x49, 0x6e,
	0x66, 0x6f, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x4a, 0x04, 0x08, 0x01, 0x10, 0x15, 0x22,
	0xfe, 0x01, 0x0a, 0x15, 0x47, 0x65, 0x74, 0x53, 0x65, 0x72, 0x76, 0x65, 0x72, 0x49, 0x6e, 0x66,
	0x6f, 0x52, 0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65, 0x12, 0x23, 0x0a, 0x09, 0x73, 0x65, 0x72,
	0x76, 0x65, 0x72, 0x5f, 0x69, 0x64, 0x18, 0x16, 0x20, 0x01, 0x28, 0x05, 0x42, 0x06, 0xe0, 0x41,
	0x05, 0xe0, 0x41, 0x02, 0x52, 0x08, 0x73, 0x65, 0x72, 0x76, 0x65, 0x72, 0x49, 0x64, 0x12, 0x3e,
	0x0a, 0x0a, 0x73, 0x74, 0x61, 0x72, 0x74, 0x65, 0x64, 0x5f, 0x61, 0x74, 0x18, 0x17, 0x20, 0x01,
	0x28, 0x0b, 0x32, 0x1a, 0x2e, 0x67, 0x6f, 0x6f, 0x67, 0x6c, 0x65, 0x2e, 0x70, 0x72, 0x6f, 0x74,
	0x6f, 0x62, 0x75, 0x66, 0x2e, 0x54, 0x69, 0x6d, 0x65, 0x73, 0x74, 0x61, 0x6d, 0x70, 0x42, 0x03,
	0xe0, 0x41, 0x05, 0x52, 0x09, 0x73, 0x74, 0x61, 0x72, 0x74, 0x65, 0x64, 0x41, 0x74, 0x12, 0x3b,
	0x0a, 0x06, 0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x18, 0x18, 0x20, 0x01, 0x28, 0x0e, 0x32, 0x1e,
	0x2e, 0x73, 0x74, 0x72, 0x75, 0x71, 0x74, 0x2e, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2e, 0x76,
	0x31, 0x2e, 0x53, 0x65, 0x72, 0x76, 0x65, 0x72, 0x53, 0x74, 0x61, 0x74, 0x75, 0x73, 0x42, 0x03,
	0xe0, 0x41, 0x05, 0x52, 0x06, 0x73, 0x74, 0x61, 0x74, 0x75, 0x73, 0x12, 0x3d, 0x0a, 0x09, 0x74,
	0x69, 0x6d, 0x65, 0x73, 0x74, 0x61, 0x6d, 0x70, 0x18, 0x19, 0x20, 0x01, 0x28, 0x0b, 0x32, 0x1a,
	0x2e, 0x67, 0x6f, 0x6f, 0x67, 0x6c, 0x65, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x62, 0x75, 0x66,
	0x2e, 0x54, 0x69, 0x6d, 0x65, 0x73, 0x74, 0x61, 0x6d, 0x70, 0x42, 0x03, 0xe0, 0x41, 0x02, 0x52,
	0x09, 0x74, 0x69, 0x6d, 0x65, 0x73, 0x74, 0x61, 0x6d, 0x70, 0x4a, 0x04, 0x08, 0x01, 0x10, 0x15,
	0x22, 0x42, 0x0a, 0x05, 0x44, 0x75, 0x6d, 0x6d, 0x79, 0x12, 0x18, 0x0a, 0x07, 0x76, 0x65, 0x72,
	0x73, 0x69, 0x6f, 0x6e, 0x18, 0x01, 0x20, 0x01, 0x28, 0x05, 0x52, 0x07, 0x76, 0x65, 0x72, 0x73,
	0x69, 0x6f, 0x6e, 0x12, 0x1f, 0x0a, 0x0b, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x5f, 0x74,
	0x61, 0x67, 0x18, 0x02, 0x20, 0x01, 0x28, 0x09, 0x52, 0x0a, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6f,
	0x6e, 0x54, 0x61, 0x67, 0x2a, 0x9b, 0x01, 0x0a, 0x0c, 0x53, 0x65, 0x72, 0x76, 0x65, 0x72, 0x53,
	0x74, 0x61, 0x74, 0x75, 0x73, 0x12, 0x1d, 0x0a, 0x19, 0x53, 0x45, 0x52, 0x56, 0x45, 0x52, 0x5f,
	0x53, 0x54, 0x41, 0x54, 0x55, 0x53, 0x5f, 0x55, 0x4e, 0x53, 0x50, 0x45, 0x43, 0x49, 0x46, 0x49,
	0x45, 0x44, 0x10, 0x00, 0x12, 0x19, 0x0a, 0x15, 0x53, 0x45, 0x52, 0x56, 0x45, 0x52, 0x5f, 0x53,
	0x54, 0x41, 0x54, 0x55, 0x53, 0x5f, 0x49, 0x4e, 0x49, 0x54, 0x49, 0x41, 0x4c, 0x10, 0x01, 0x12,
	0x1a, 0x0a, 0x16, 0x53, 0x45, 0x52, 0x56, 0x45, 0x52, 0x5f, 0x53, 0x54, 0x41, 0x54, 0x55, 0x53,
	0x5f, 0x53, 0x54, 0x41, 0x52, 0x54, 0x49, 0x4e, 0x47, 0x10, 0x02, 0x12, 0x19, 0x0a, 0x15, 0x53,
	0x45, 0x52, 0x56, 0x45, 0x52, 0x5f, 0x53, 0x54, 0x41, 0x54, 0x55, 0x53, 0x5f, 0x52, 0x55, 0x4e,
	0x4e, 0x49, 0x4e, 0x47, 0x10, 0x03, 0x12, 0x1a, 0x0a, 0x16, 0x53, 0x45, 0x52, 0x56, 0x45, 0x52,
	0x5f, 0x53, 0x54, 0x41, 0x54, 0x55, 0x53, 0x5f, 0x53, 0x48, 0x55, 0x54, 0x44, 0x4f, 0x57, 0x4e,
	0x10, 0x04, 0x32, 0x92, 0x01, 0x0a, 0x0d, 0x43, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x53, 0x65, 0x72,
	0x76, 0x69, 0x63, 0x65, 0x12, 0x80, 0x01, 0x0a, 0x0d, 0x47, 0x65, 0x74, 0x53, 0x65, 0x72, 0x76,
	0x65, 0x72, 0x49, 0x6e, 0x66, 0x6f, 0x12, 0x26, 0x2e, 0x73, 0x74, 0x72, 0x75, 0x71, 0x74, 0x2e,
	0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2e, 0x76, 0x31, 0x2e, 0x47, 0x65, 0x74, 0x53, 0x65, 0x72,
	0x76, 0x65, 0x72, 0x49, 0x6e, 0x66, 0x6f, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x27,
	0x2e, 0x73, 0x74, 0x72, 0x75, 0x71, 0x74, 0x2e, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2e, 0x76,
	0x31, 0x2e, 0x47, 0x65, 0x74, 0x53, 0x65, 0x72, 0x76, 0x65, 0x72, 0x49, 0x6e, 0x66, 0x6f, 0x52,
	0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65, 0x22, 0x1e, 0x82, 0xd3, 0xe4, 0x93, 0x02, 0x18, 0x12,
	0x16, 0x2f, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2f, 0x76, 0x31, 0x2f, 0x73, 0x65, 0x72, 0x76,
	0x65, 0x72, 0x2d, 0x69, 0x6e, 0x66, 0x6f, 0x42, 0x60, 0x0a, 0x1a, 0x63, 0x6f, 0x6d, 0x2e, 0x73,
	0x74, 0x72, 0x75, 0x71, 0x74, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x2e, 0x63, 0x6f, 0x6d, 0x6d,
	0x6f, 0x6e, 0x2e, 0x76, 0x31, 0x5a, 0x2f, 0x67, 0x69, 0x74, 0x68, 0x75, 0x62, 0x2e, 0x63, 0x6f,
	0x6d, 0x2f, 0x73, 0x74, 0x72, 0x75, 0x71, 0x74, 0x2f, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x2f, 0x73,
	0x74, 0x72, 0x75, 0x71, 0x74, 0x2f, 0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2f, 0x76, 0x31, 0x3b,
	0x63, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0xaa, 0x02, 0x10, 0x53, 0x74, 0x72, 0x75, 0x71, 0x74, 0x2e,
	0x43, 0x6f, 0x6d, 0x6d, 0x6f, 0x6e, 0x2e, 0x56, 0x31, 0x62, 0x06, 0x70, 0x72, 0x6f, 0x74, 0x6f,
	0x33,
}

var (
	file_struqt_common_v1_common_proto_rawDescOnce sync.Once
	file_struqt_common_v1_common_proto_rawDescData = file_struqt_common_v1_common_proto_rawDesc
)

func file_struqt_common_v1_common_proto_rawDescGZIP() []byte {
	file_struqt_common_v1_common_proto_rawDescOnce.Do(func() {
		file_struqt_common_v1_common_proto_rawDescData = protoimpl.X.CompressGZIP(file_struqt_common_v1_common_proto_rawDescData)
	})
	return file_struqt_common_v1_common_proto_rawDescData
}

var file_struqt_common_v1_common_proto_enumTypes = make([]protoimpl.EnumInfo, 1)
var file_struqt_common_v1_common_proto_msgTypes = make([]protoimpl.MessageInfo, 3)
var file_struqt_common_v1_common_proto_goTypes = []interface{}{
	(ServerStatus)(0),             // 0: struqt.common.v1.ServerStatus
	(*GetServerInfoRequest)(nil),  // 1: struqt.common.v1.GetServerInfoRequest
	(*GetServerInfoResponse)(nil), // 2: struqt.common.v1.GetServerInfoResponse
	(*Dummy)(nil),                 // 3: struqt.common.v1.Dummy
	(*timestamppb.Timestamp)(nil), // 4: google.protobuf.Timestamp
}
var file_struqt_common_v1_common_proto_depIdxs = []int32{
	4, // 0: struqt.common.v1.GetServerInfoResponse.started_at:type_name -> google.protobuf.Timestamp
	0, // 1: struqt.common.v1.GetServerInfoResponse.status:type_name -> struqt.common.v1.ServerStatus
	4, // 2: struqt.common.v1.GetServerInfoResponse.timestamp:type_name -> google.protobuf.Timestamp
	1, // 3: struqt.common.v1.CommonService.GetServerInfo:input_type -> struqt.common.v1.GetServerInfoRequest
	2, // 4: struqt.common.v1.CommonService.GetServerInfo:output_type -> struqt.common.v1.GetServerInfoResponse
	4, // [4:5] is the sub-list for method output_type
	3, // [3:4] is the sub-list for method input_type
	3, // [3:3] is the sub-list for extension type_name
	3, // [3:3] is the sub-list for extension extendee
	0, // [0:3] is the sub-list for field type_name
}

func init() { file_struqt_common_v1_common_proto_init() }
func file_struqt_common_v1_common_proto_init() {
	if File_struqt_common_v1_common_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_struqt_common_v1_common_proto_msgTypes[0].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*GetServerInfoRequest); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_struqt_common_v1_common_proto_msgTypes[1].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*GetServerInfoResponse); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_struqt_common_v1_common_proto_msgTypes[2].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*Dummy); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
	}
	type x struct{}
	out := protoimpl.TypeBuilder{
		File: protoimpl.DescBuilder{
			GoPackagePath: reflect.TypeOf(x{}).PkgPath(),
			RawDescriptor: file_struqt_common_v1_common_proto_rawDesc,
			NumEnums:      1,
			NumMessages:   3,
			NumExtensions: 0,
			NumServices:   1,
		},
		GoTypes:           file_struqt_common_v1_common_proto_goTypes,
		DependencyIndexes: file_struqt_common_v1_common_proto_depIdxs,
		EnumInfos:         file_struqt_common_v1_common_proto_enumTypes,
		MessageInfos:      file_struqt_common_v1_common_proto_msgTypes,
	}.Build()
	File_struqt_common_v1_common_proto = out.File
	file_struqt_common_v1_common_proto_rawDesc = nil
	file_struqt_common_v1_common_proto_goTypes = nil
	file_struqt_common_v1_common_proto_depIdxs = nil
}
