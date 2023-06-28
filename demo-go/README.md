# gRPC Golang Demo

## Generate Source Code

```shell
./protoc-gen.sh
```

## Run gRPC Server

Start gRPC Server

```shell
go run ./server/cmd/demo-grpc
```

Test gRPC server with [gRPCurl](https://github.com/fullstorydev/grpcurl)

```shell
grpcurl -plaintext -import-path ../proto/googleapis -import-path ../proto/common -proto struqt/common/v1/common.proto 127.0.0.1:9090 struqt.common.v1.CommonService/GetServerInfo | jq
```

## Run gRPC Gateway Server

Start:

```shell
go run ./server/cmd/demo-gate
```

Test gateway server with [cURL](https://curl.se)

**Firstly, confirm that the corresponding gRPC gateway server has been started**

```shell
curl 127.0.0.1:8080/common/v1/server-info -s | jq
```
