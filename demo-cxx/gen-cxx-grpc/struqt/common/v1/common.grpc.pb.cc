// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: struqt/common/v1/common.proto

#include "struqt/common/v1/common.pb.h"
#include "struqt/common/v1/common.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace struqt {
namespace common {
namespace v1 {

static const char* CommonService_method_names[] = {
  "/struqt.common.v1.CommonService/GetServerInfo",
};

std::unique_ptr< CommonService::Stub> CommonService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< CommonService::Stub> stub(new CommonService::Stub(channel, options));
  return stub;
}

CommonService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GetServerInfo_(CommonService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status CommonService::Stub::GetServerInfo(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest& request, ::struqt::common::v1::GetServerInfoResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::struqt::common::v1::GetServerInfoRequest, ::struqt::common::v1::GetServerInfoResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetServerInfo_, context, request, response);
}

void CommonService::Stub::async::GetServerInfo(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest* request, ::struqt::common::v1::GetServerInfoResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::struqt::common::v1::GetServerInfoRequest, ::struqt::common::v1::GetServerInfoResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetServerInfo_, context, request, response, std::move(f));
}

void CommonService::Stub::async::GetServerInfo(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest* request, ::struqt::common::v1::GetServerInfoResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetServerInfo_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::struqt::common::v1::GetServerInfoResponse>* CommonService::Stub::PrepareAsyncGetServerInfoRaw(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::struqt::common::v1::GetServerInfoResponse, ::struqt::common::v1::GetServerInfoRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetServerInfo_, context, request);
}

::grpc::ClientAsyncResponseReader< ::struqt::common::v1::GetServerInfoResponse>* CommonService::Stub::AsyncGetServerInfoRaw(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetServerInfoRaw(context, request, cq);
  result->StartCall();
  return result;
}

CommonService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      CommonService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< CommonService::Service, ::struqt::common::v1::GetServerInfoRequest, ::struqt::common::v1::GetServerInfoResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](CommonService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::struqt::common::v1::GetServerInfoRequest* req,
             ::struqt::common::v1::GetServerInfoResponse* resp) {
               return service->GetServerInfo(ctx, req, resp);
             }, this)));
}

CommonService::Service::~Service() {
}

::grpc::Status CommonService::Service::GetServerInfo(::grpc::ServerContext* context, const ::struqt::common::v1::GetServerInfoRequest* request, ::struqt::common::v1::GetServerInfoResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace struqt
}  // namespace common
}  // namespace v1

