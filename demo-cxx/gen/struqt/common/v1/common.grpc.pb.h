// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: struqt/common/v1/common.proto
#ifndef GRPC_struqt_2fcommon_2fv1_2fcommon_2eproto__INCLUDED
#define GRPC_struqt_2fcommon_2fv1_2fcommon_2eproto__INCLUDED

#include "struqt/common/v1/common.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/proto_utils.h>
#include <grpcpp/impl/rpc_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/status.h>
#include <grpcpp/support/stub_options.h>
#include <grpcpp/support/sync_stream.h>

namespace struqt {
namespace common {
namespace v1 {

class CommonService final {
 public:
  static constexpr char const* service_full_name() {
    return "struqt.common.v1.CommonService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status GetServerInfo(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest& request, ::struqt::common::v1::GetServerInfoResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::struqt::common::v1::GetServerInfoResponse>> AsyncGetServerInfo(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::struqt::common::v1::GetServerInfoResponse>>(AsyncGetServerInfoRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::struqt::common::v1::GetServerInfoResponse>> PrepareAsyncGetServerInfo(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::struqt::common::v1::GetServerInfoResponse>>(PrepareAsyncGetServerInfoRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void GetServerInfo(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest* request, ::struqt::common::v1::GetServerInfoResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void GetServerInfo(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest* request, ::struqt::common::v1::GetServerInfoResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::struqt::common::v1::GetServerInfoResponse>* AsyncGetServerInfoRaw(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::struqt::common::v1::GetServerInfoResponse>* PrepareAsyncGetServerInfoRaw(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status GetServerInfo(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest& request, ::struqt::common::v1::GetServerInfoResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::struqt::common::v1::GetServerInfoResponse>> AsyncGetServerInfo(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::struqt::common::v1::GetServerInfoResponse>>(AsyncGetServerInfoRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::struqt::common::v1::GetServerInfoResponse>> PrepareAsyncGetServerInfo(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::struqt::common::v1::GetServerInfoResponse>>(PrepareAsyncGetServerInfoRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void GetServerInfo(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest* request, ::struqt::common::v1::GetServerInfoResponse* response, std::function<void(::grpc::Status)>) override;
      void GetServerInfo(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest* request, ::struqt::common::v1::GetServerInfoResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::struqt::common::v1::GetServerInfoResponse>* AsyncGetServerInfoRaw(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::struqt::common::v1::GetServerInfoResponse>* PrepareAsyncGetServerInfoRaw(::grpc::ClientContext* context, const ::struqt::common::v1::GetServerInfoRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_GetServerInfo_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status GetServerInfo(::grpc::ServerContext* context, const ::struqt::common::v1::GetServerInfoRequest* request, ::struqt::common::v1::GetServerInfoResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_GetServerInfo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_GetServerInfo() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_GetServerInfo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetServerInfo(::grpc::ServerContext* /*context*/, const ::struqt::common::v1::GetServerInfoRequest* /*request*/, ::struqt::common::v1::GetServerInfoResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetServerInfo(::grpc::ServerContext* context, ::struqt::common::v1::GetServerInfoRequest* request, ::grpc::ServerAsyncResponseWriter< ::struqt::common::v1::GetServerInfoResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_GetServerInfo<Service > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_GetServerInfo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_GetServerInfo() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::struqt::common::v1::GetServerInfoRequest, ::struqt::common::v1::GetServerInfoResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::struqt::common::v1::GetServerInfoRequest* request, ::struqt::common::v1::GetServerInfoResponse* response) { return this->GetServerInfo(context, request, response); }));}
    void SetMessageAllocatorFor_GetServerInfo(
        ::grpc::MessageAllocator< ::struqt::common::v1::GetServerInfoRequest, ::struqt::common::v1::GetServerInfoResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::struqt::common::v1::GetServerInfoRequest, ::struqt::common::v1::GetServerInfoResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_GetServerInfo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetServerInfo(::grpc::ServerContext* /*context*/, const ::struqt::common::v1::GetServerInfoRequest* /*request*/, ::struqt::common::v1::GetServerInfoResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* GetServerInfo(
      ::grpc::CallbackServerContext* /*context*/, const ::struqt::common::v1::GetServerInfoRequest* /*request*/, ::struqt::common::v1::GetServerInfoResponse* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_GetServerInfo<Service > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_GetServerInfo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_GetServerInfo() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_GetServerInfo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetServerInfo(::grpc::ServerContext* /*context*/, const ::struqt::common::v1::GetServerInfoRequest* /*request*/, ::struqt::common::v1::GetServerInfoResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_GetServerInfo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_GetServerInfo() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_GetServerInfo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetServerInfo(::grpc::ServerContext* /*context*/, const ::struqt::common::v1::GetServerInfoRequest* /*request*/, ::struqt::common::v1::GetServerInfoResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetServerInfo(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_GetServerInfo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_GetServerInfo() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->GetServerInfo(context, request, response); }));
    }
    ~WithRawCallbackMethod_GetServerInfo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetServerInfo(::grpc::ServerContext* /*context*/, const ::struqt::common::v1::GetServerInfoRequest* /*request*/, ::struqt::common::v1::GetServerInfoResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* GetServerInfo(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_GetServerInfo : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_GetServerInfo() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::struqt::common::v1::GetServerInfoRequest, ::struqt::common::v1::GetServerInfoResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::struqt::common::v1::GetServerInfoRequest, ::struqt::common::v1::GetServerInfoResponse>* streamer) {
                       return this->StreamedGetServerInfo(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_GetServerInfo() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status GetServerInfo(::grpc::ServerContext* /*context*/, const ::struqt::common::v1::GetServerInfoRequest* /*request*/, ::struqt::common::v1::GetServerInfoResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedGetServerInfo(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::struqt::common::v1::GetServerInfoRequest,::struqt::common::v1::GetServerInfoResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_GetServerInfo<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_GetServerInfo<Service > StreamedService;
};

}  // namespace v1
}  // namespace common
}  // namespace struqt


#endif  // GRPC_struqt_2fcommon_2fv1_2fcommon_2eproto__INCLUDED