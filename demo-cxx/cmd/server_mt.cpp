
#include <iostream>
#include <memory>
#include <string>
#include <thread>

#include <google/protobuf/util/time_util.h>
#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>

#include <struqt/common/v1/common.grpc.pb.h>

using grpc::Server;
using grpc::ServerAsyncResponseWriter;
using grpc::ServerBuilder;
using grpc::ServerCompletionQueue;
using grpc::ServerContext;
using grpc::Status;

class ServerImpl final {
public:
  ~ServerImpl() {
    server_->Shutdown();
    // Always shutdown the completion queue after the server.
    for (auto &cq : cq_)
      cq->Shutdown();
  }

  // There is no shutdown handling in this code.
  void Run() {
    std::string server_address("127.0.0.1:9090");
    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service_);
    // auto parallelism = std::atoi(std::getenv("GRPC_SERVER_CPUS"));
    const int parallelism = 8;
    // Get hold of the completion queue used for the asynchronous communication
    // with the gRPC runtime.
    for (int i = 0; i < parallelism; i++) {
      cq_.emplace_back(builder.AddCompletionQueue());
    }
    // Finally assemble the server.
    server_ = builder.BuildAndStart();
    std::cout << "Server listening on " << server_address << std::endl;
    // Proceed to the server's main loop.
    for (int i = 0; i < parallelism; i++) {
      server_threads_.emplace_back([this, i] { this->HandleRpcs(i); });
    }
    std::this_thread::sleep_until(
        std::chrono::time_point<std::chrono::system_clock>::max());
  }

private:
  std::vector<std::unique_ptr<ServerCompletionQueue>> cq_;
  std::unique_ptr<Server> server_;
  std::vector<std::thread> server_threads_;
  ::struqt::common::v1::CommonService::AsyncService service_;

  // This can be run in multiple threads if needed.
  void HandleRpcs(int i) {
    // Spawn a new CallData instance to serve new clients.
    new CallData(&service_, cq_[i].get());
    CallData *tag; // uniquely identifies a request.
    bool ok;
    while (true) {
      // Block waiting to read the next event from the completion queue. The
      // event is uniquely identified by its tag, which in this case is the
      // memory address of a CallData instance.
      // The return value of Next should always be checked. This return value
      // tells us whether there is any kind of event or cq_ is shutting down.
      GPR_ASSERT(cq_[i]->Next((void **)(&tag), &ok));
      // GPR_ASSERT(ok);
      // std::cout << i << std::endl;
      tag->Proceed();
    }
  }

  // Class encompassing the state and logic needed to serve a request.
  class CallData {
  public:
    // Take in the "service" instance (in this case representing an asynchronous
    // server) and the completion queue "cq" used for asynchronous communication
    // with the gRPC runtime.
    explicit CallData(
        ::struqt::common::v1::CommonService::AsyncService *service,
        ServerCompletionQueue *cq)
        : service_(service), cq_(cq), responder_(&ctx_), status_(CREATE) {
      // Invoke the serving logic right away.
      Proceed();
    }

    void Proceed() {
      if (status_ == CREATE) {
        // Make this instance progress to the PROCESS state.
        status_ = PROCESS;
        // As part of the initial CREATE state, we *request* that the system
        // start processing SayHello requests. In this request, "this" acts are
        // the tag uniquely identifying the request (so that different CallData
        // instances can serve different requests concurrently), in this case
        // the memory address of this CallData instance.
        service_->RequestGetServerInfo( //
            &ctx_, &request_, &responder_, cq_, cq_, this);
      } else if (status_ == PROCESS) {
        // Spawn a new CallData instance to serve new clients while we process
        // the one for this CallData. The instance will deallocate itself as
        // part of its FINISH state.
        new CallData(service_, cq_);

        // The actual processing.
        //*reply_.mutable_response() = std::move(*request_.mutable_request());

        auto response = &reply_;
        response->set_server_id(997);
        response->set_status(
            ::struqt::common::v1::ServerStatus::SERVER_STATUS_RUNNING);
        response->mutable_timestamp()->CopyFrom(
            google::protobuf::util::TimeUtil::GetCurrentTime());

        // And we are done! Let the gRPC runtime know we've finished, using the
        // memory address of this instance as the uniquely identifying tag for
        // the event.
        status_ = FINISH;
        responder_.Finish(reply_, Status::OK, this);
      } else {
        GPR_ASSERT(status_ == FINISH);
        // Once in the FINISH state, deallocate ourselves (CallData).
        delete this;
      }
    }

  private:
    // The means of communication with the gRPC runtime for an asynchronous
    // server.
    ::struqt::common::v1::CommonService::AsyncService *service_;
    // The producer-consumer queue where for asynchronous server notifications.
    ServerCompletionQueue *cq_;
    // Context for the rpc, allowing to tweak aspects of it such as the use
    // of compression, authentication, as well as to send metadata back to the
    // client.
    ServerContext ctx_;

    // What we get from the client.
    ::struqt::common::v1::GetServerInfoRequest request_;
    // What we send back to the client.
    ::struqt::common::v1::GetServerInfoResponse reply_;

    // The means to get back to the client.
    ServerAsyncResponseWriter<::struqt::common::v1::GetServerInfoResponse>
        responder_;

    // Let's implement a tiny state machine with the following states.
    enum CallStatus { CREATE, PROCESS, FINISH };
    CallStatus status_; // The current serving state.

  }; // class CallData
};

int main() {
  ServerImpl server;
  server.Run();
  return 0;
}
