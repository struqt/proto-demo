//
// Created by Kang on 7/3/23.
//

#ifndef DEMO_CXX_DEMO_SERVER_H
#define DEMO_CXX_DEMO_SERVER_H

#include <string>

#include <grpcpp/grpcpp.h>

void RunDemoServer(const std::string &address);

class DemoServer {
public:
  // Default destructor
  ~DemoServer() = default;
  // Disable copy assignment operator
  DemoServer &operator=(const DemoServer &) = delete;
  // Disable copy constructor
  DemoServer(const DemoServer &) = delete;
  // Constructor that initializes the gRPC server
  explicit DemoServer(const std::string &server_address);

  // Method to wait for the server to shut down
  void Serve() { return server_->Wait(); }

private:
  grpc::ServerBuilder builder_;
  std::vector<std::unique_ptr<grpc::Service>> services_;
  std::unique_ptr<grpc::Server> server_;
};

#endif // DEMO_CXX_DEMO_SERVER_H
