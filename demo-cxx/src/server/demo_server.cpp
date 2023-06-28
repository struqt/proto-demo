//
// Created by Kang on 7/3/23.
//

#include "demo_server.h"
#include "demo_handler.h"

#include <grpcpp/ext/proto_server_reflection_plugin.h>

void RunDemoServer(const std::string &address) {
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  DemoServer demo_server(address);
  demo_server.Serve();
}

template <typename ServiceImpl>
void RegisterService(std::vector<std::unique_ptr<grpc::Service>> &services,
                     grpc::ServerBuilder &builder) {
  static_assert(std::is_base_of<::grpc::Service, ServiceImpl>::value,
                "Must be derived from grpc::Service");
  std::unique_ptr<::grpc::Service> p = std::make_unique<ServiceImpl>();
  builder.RegisterService(p.get());
  services.push_back(std::move(p));
}

void RegisterAllServices(std::vector<std::unique_ptr<grpc::Service>> &services,
                         grpc::ServerBuilder &builder) {
  RegisterService<v1common::CommonServiceImpl>(services, builder);
  RegisterService<v1demo::DemoServiceImpl>(services, builder);
  RegisterService<v1demo::BasicServiceImpl>(services, builder);
  RegisterService<v2demo::BasicServiceImpl>(services, builder);
  RegisterService<v3demo::DemoServiceImpl>(services, builder);
}

DemoServer::DemoServer(const std::string &server_address) {
  std::shared_ptr<grpc::ServerCredentials> credentials;
  credentials = grpc::InsecureServerCredentials();
  builder_.AddListeningPort(server_address, credentials);
  grpc::EnableDefaultHealthCheckService(true);
  RegisterAllServices(services_, builder_);
  server_ = builder_.BuildAndStart();
  if (!server_) {
    std::cerr << "Failed to start server." << std::endl;
    return;
  }
  grpc::HealthCheckServiceInterface *health = server_->GetHealthCheckService();
  if (health) {
    health->SetServingStatus("demo.service", true);
  }
  std::cout << "Server is listening on " << server_address << std::endl;
}
