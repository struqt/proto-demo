
#include <absl/flags/flag.h>
#include <absl/flags/parse.h>

#include "demo_server.h"

ABSL_FLAG(std::string, address, "localhost:9090", "Listen address");
ABSL_FLAG(std::string, run, "demo", "Server run type name");

int main(int argc, char **argv) {
  ::absl::ParseCommandLine(argc, argv);
  auto run = ::absl::GetFlag(FLAGS_run);
  auto address = ::absl::GetFlag(FLAGS_address);
  if (std::equal(run.begin(), run.end(), "demo")) {
    RunDemoServer(address);
  }
  return 0;
}
