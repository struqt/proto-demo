#!/bin/bash
set -eo pipefail

declare -r GRPC_PATH='../third-party/build/target/grpc/bin'
declare -r PROTOC_PATH='../third-party/build/target/protobuf/bin'

protoc_gen_cxx() {
  local dir="./gen-cxx"
  mkdir -p "${dir}" "${dir}-grpc"
  ${PROTOC_PATH:?}/protoc \
    --cpp_out="${dir}" \
    --grpc_out="${dir}-grpc" \
    --plugin=protoc-gen-grpc="${GRPC_PATH:?}/grpc_cpp_plugin" \
    --proto_path=../proto/googleapis \
    --proto_path=../proto/grpc-gateway \
    --proto_path=../proto/common \
    --proto_path=../proto/demo \
    google/api/annotations.proto \
    google/api/field_behavior.proto \
    google/api/http.proto \
    google/api/httpbody.proto \
    protoc-gen-openapiv2/options/openapiv2.proto \
    protoc-gen-openapiv2/options/annotations.proto \
    struqt/demo/v1/demo.proto \
    struqt/demo/v2/demo.proto \
    struqt/demo/v3/demo.proto \
    struqt/demo/v3/messages.proto \
    struqt/common/v1/common.proto
}

protoc_gen_cxx
