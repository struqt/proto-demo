//
// Created by Kang on 7/3/23.
//

#include <grpcpp/grpcpp.h>
#include <iostream>
#include <memory>
#include <utility>

#include <struqt/common/v1/common.grpc.pb.h>

namespace v1common {
using namespace struqt::common::v1;

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

void PrintResponse(GetServerInfoResponse &resp) {
  // Process the response
  std::cout << "Server ID: " << resp.server_id() << std::endl;
  std::cout << "Started at: " << resp.started_at().DebugString() << std::endl;
  std::cout << "Status: " << resp.status() << std::endl;
  std::cout << "Timestamp: " << resp.timestamp().DebugString() << std::endl;
}

void PrintError(Status &status) {
  std::cout << "RPC failed ----------" << std::endl;
  std::cout << "error_code:    " << status.error_code() << std::endl;
  std::cout << "error_message: " << status.error_message() << std::endl;
  std::cout << "error_details: " << status.error_details() << std::endl;
}

void Test(std::shared_ptr<grpc::Channel> ch) {
  auto common = CommonService::NewStub(std::move(ch));
  ClientContext context;
  GetServerInfoRequest req;
  GetServerInfoResponse resp;
  auto status = common->GetServerInfo(&context, req, &resp);
  if (status.ok()) {
    // PrintResponse(resp);
  } else {
    PrintError(status);
    PrintResponse(resp);
  }
}
} // namespace v1common

int main() {
  // Create a gRPC channel and a client
  std::string server_address = "localhost:9090";

  grpc::ChannelArguments channel_args;
  channel_args.SetMaxReceiveMessageSize(1024 * 1024 * 16);
  channel_args.SetInt("grpc.keepalive_time_ms", 10000);
  channel_args.SetInt("grpc.keepalive_timeout_ms", 5000);
  channel_args.SetInt("grpc.keepalive_permit_without_calls", 1);
  // Enable automatic retries
  channel_args.SetInt("grpc.enable_retries", 1);
  channel_args.SetInt("grpc.max_reconnect_backoff_ms", 10000);

  auto ch = grpc::CreateCustomChannel(
      server_address, grpc::InsecureChannelCredentials(), channel_args);

  auto timeout = std::chrono::system_clock::now() + std::chrono::seconds(10);
  while (true) {
    if (ch->WaitForConnected(timeout)) {
      std::cout << ch->GetState(true) << std::endl;
      for (int i = 0; i < 5; ++i) {
        v1common::Test(ch);
      }
      break;
    }
    std::cout << ch->GetState(true) << std::endl;
  }
}
