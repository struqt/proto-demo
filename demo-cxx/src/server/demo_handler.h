//
// Created by Kang on 7/3/23.
//

#ifndef DEMO_CXX_DEMO_HANDLER_H
#define DEMO_CXX_DEMO_HANDLER_H

#include <struqt/common/v1/common.grpc.pb.h>
#include <struqt/demo/v1/demo.grpc.pb.h>
#include <struqt/demo/v2/demo.grpc.pb.h>
#include <struqt/demo/v3/demo.grpc.pb.h>

#include <google/protobuf/util/time_util.h>

using namespace ::grpc;

// Handles common version 1 requests.
namespace v1common {
using namespace ::struqt::common::v1;

class CommonServiceImpl final : public CommonService::Service {
public:
  Status GetServerInfo(ServerContext *context,
                       const GetServerInfoRequest *request,
                       GetServerInfoResponse *response) override {
    response->set_server_id(997);
    response->set_status(ServerStatus::SERVER_STATUS_RUNNING);
    response->mutable_timestamp()->CopyFrom(
        google::protobuf::util::TimeUtil::GetCurrentTime());
    return Status::OK;
  }
}; // CommonServiceImpl
} // namespace v1common

// Handles demo version 3 requests.
namespace v3demo {
using namespace ::struqt::demo::v3;
class DemoServiceImpl final : public DemoService::Service {
public:
  Status EchoValue(ServerContext *context, const EchoValueRequest *request,
                   EchoValueResponse *response) override {
    response->mutable_value()->CopyFrom(request->value());
    response->mutable_timestamp()->CopyFrom(
        google::protobuf::util::TimeUtil::GetCurrentTime());
    return Status::OK;
  }
}; // DemoServiceImpl
} // namespace v3demo

// Handles demo version 2 requests.
namespace v2demo {
using namespace ::struqt::demo::v2;
class BasicServiceImpl final : public BasicService::Service {
public:
  ::grpc::Status Echo(::grpc::ServerContext *context,
                      const EchoRequest *request,
                      EchoResponse *response) override {
    response->set_version(2);
    response->set_value(request->value());
    return ::grpc::Status::OK;
  }
}; // BasicServiceImpl
} // namespace v2demo

// Handles demo version 1 requests.
namespace v1demo {
using namespace ::struqt::demo::v1;
class DemoServiceImpl final : public DemoService::Service {
public:
  Status Echo(ServerContext *context, const EchoRequest *request,
              EchoResponse *response) override {
    response->set_version(1);
    response->set_value(request->value());
    return Status::OK;
  }
}; // DemoServiceImpl
class BasicServiceImpl final : public BasicService::Service {
public:
  Status JsonRpc(ServerContext *context, const JsonRpcRequest *request,
                 JsonRpcResponse *response) override {
    return Status::CANCELLED;
  }
}; // BasicServiceImpl
} // namespace v1demo

#endif // DEMO_CXX_DEMO_HANDLER_H
