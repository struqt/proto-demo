
#include <absl/flags/flag.h>
#include <absl/flags/parse.h>
#include <absl/strings/str_format.h>

#include "demo_server.h"

ABSL_FLAG(std::string, run, "demo", "Server run type name");
ABSL_FLAG(uint16_t, port, 9090, "Server port for the service");

int main(int argc, char **argv) {
  ::absl::ParseCommandLine(argc, argv);
  auto run = ::absl::GetFlag(FLAGS_run);
  auto port = ::absl::GetFlag(FLAGS_port);
  auto address = ::absl::StrFormat("127.0.0.1:%d", port);
  if (std::equal(run.begin(), run.end(), "demo")) {
    RunDemoServer(address);
  }
  return 0;
}
