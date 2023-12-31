# gRPC Rust Demo

## Start gRPC Server

```shell
cargo run --release --bin demo-rs-server
```

## Test with [gRPCurl](https://github.com/fullstorydev/grpcurl)

```shell
grpcurl -plaintext -import-path ../proto/googleapis -import-path ../proto/common -proto struqt/common/v1/common.proto 127.0.0.1:9090 struqt.common.v1.CommonService/GetServerInfo | jq
```

## Test with [cURL](https://curl.se)

**Firstly, confirm that the corresponding gRPC gateway server has been started**

```shell
curl 127.0.0.1:8080/common/v1/server-info -s | jq
```
