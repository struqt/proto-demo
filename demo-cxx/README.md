# gRPC C++ Demo

## Build with CMake

```shell
cmake -B ./build/release -D CMAKE_BUILD_TYPE=Release && cmake --build ./build/release --config Release
```

## Run gRPC Server

```shell
build/release/demo_cxx_server
```

Test gRPC server with [gRPCurl](https://github.com/fullstorydev/grpcurl)

```shell
grpcurl -import-path ../proto/googleapis -import-path ../proto/common -proto struqt/common/v1/common.proto -plaintext localhost:9090 struqt.common.v1.CommonService/GetServerInfo
```

If gRPC reflection feature is enabled, run this:

```shell
grpcurl -plaintext localhost:9090 struqt.common.v1.CommonService/GetServerInfo
```
