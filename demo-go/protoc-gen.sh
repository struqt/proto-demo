#!/bin/bash
set -eo pipefail

declare -rx BUF_DIR='../proto'

protoc_gen() {
  local module=$1
  local depends=$2
  pushd "${BUF_DIR:?}/${module}"
  export -f protoc_gen_go
  find 'struqt' -name "*.proto" -type f -exec bash -c 'protoc_gen_go "$0" "$1"' {} "${depends}" \;
  popd
}

protoc_gen_go() {
  local file=$1
  local dir="../../demo-go/proto"
  # echo "- $(pwd)"
  echo "- ${file:?}"
  mkdir -p "${dir}"
  # shellcheck disable=SC2086
  protoc \
    --go_out "${dir}" --go_opt paths=source_relative \
    --go-grpc_out "${dir}" --go-grpc_opt paths=source_relative \
    --openapiv2_out "${dir}" --openapiv2_opt logtostderr=true \
    --grpc-gateway_out "${dir}" \
    --grpc-gateway_opt logtostderr=true \
    --grpc-gateway_opt paths=source_relative \
    --grpc-gateway_opt generate_unbound_methods=true \
    --proto_path '../googleapis' \
    --proto_path '../grpc-gateway' \
    --proto_path '.' ${2} "${file}"
}

source protoc-setup.sh
export PATH="$PATH:$GOPATH/bin:$PROTOC_PATH/bin"

protoc --version
protoc-gen-go --version
protoc-gen-go-grpc --version
protoc-gen-grpc-gateway --version
protoc-gen-openapiv2 --version

##
protoc_gen common
protoc_gen demo '--proto_path ../common'
