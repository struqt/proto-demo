#include <absl/flags/flag.h>
#include <absl/flags/parse.h>
#include <absl/strings/str_format.h>

#include <google/protobuf/stubs/common.h>
#include <grpcpp/grpcpp.h>

#include <struqt/common/v1/common.pb.h>

ABSL_FLAG(uint16_t, port, 50051, "Server port for the service");

int main(int argc, char **argv) {

  absl::ParseCommandLine(argc, argv);
  int port = absl::GetFlag(FLAGS_port);
  std::string server_address = absl::StrFormat("0.0.0.0:%d", port);
  std::cout << "abseil   " << server_address << std::endl;

  const std::string &ver =
      google::protobuf::internal::VersionString(GOOGLE_PROTOBUF_VERSION);
  std::cout << "Protobuf " << ver << std::endl;
  std::cout << "gRPC     " << grpc::Version() << std::endl;

  struqt::common::v1::Dummy dummy;
  dummy.set_version(123);
  std::cout << "message  " << dummy.DebugString();

  return 0;
}
