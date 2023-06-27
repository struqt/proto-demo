package cmd

import "flag"

var (
	IsGateway = flag.Bool("gateway", false, "Whether start as a gRPC gateway server")

	//network = flag.String("network", "unix", `one of "tcp" or "unix". Must be consistent to -endpoint`)
	//address = flag.String("address", "/tmp/go.sock", "address of the gRPC service")
	network = flag.String("network", "tcp", `one of "tcp" or "unix". Must be consistent to -endpoint`)
	address = flag.String("address", "localhost:9090", "endpoint of the gRPC service")

	openAPIDir = flag.String("openapi_dir", "./api/struqt", "path to the directory which contains OpenAPI definitions")
)

func init() {
	flag.Parse()
}
