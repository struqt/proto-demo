#!/bin/bash
set -eo pipefail

install_protobuf_macos() {
  if command -v 'brew' >/dev/null 2>&1; then
    brew install protobuf
  else
    echo "Homebrew not found. Please install protobuf manually."
    return 1
  fi
}

install_protobuf_linux() {
  local package_manager
  if command -v 'apt' >/dev/null 2>&1; then
    package_manager='apt'
  elif command -v 'yum' >/dev/null 2>&1; then
    package_manager='yum'
  else
    echo "Supported package manager not found. Please install protobuf-compiler manually."
    return 1
  fi
  sudo "${package_manager}" install -y protobuf-compiler
}

install_protobuf() {
  if command -v 'protoc' >/dev/null 2>&1; then
    echo "Installed: $(which protoc) -- $(protoc --version)"
    return 0
  fi
  local os_type
  os_type=$(uname)
  case "$os_type" in
  Darwin*)
    install_protobuf_macos
    ;;
  Linux*)
    install_protobuf_linux
    ;;
  *)
    echo "Unknown operating system. Please install protobuf-compiler or protobuf manually."
    return 1
    ;;
  esac
  protoc --version
}

go_install_bin() {
  local cmd_name=$1
  local version_tag=$2
  local src_path=$3
  local cmd_path="$GOPATH/bin/${cmd_name:?}"
  local package="${src_path:?}@${version_tag:?}"
  if [ ! -f "$cmd_path" ]; then
    go install "$package"
    echo "Installed OK: $package"
  else echo "Installed: $package"; fi
}

declare -rx PROTOC_PATH="$PWD/../demo-cxx/third-party/build/target/protobuf"
if [ ! -d "${PROTOC_PATH}" ]; then
  install_protobuf
fi

declare -rx GOPATH="$PWD/.go"
declare -rx GO111MODULE='on'

go_install_bin sqlc v1.18.0 github.com/kyleconroy/sqlc/cmd/sqlc
go_install_bin buf v1.21.0 github.com/bufbuild/buf/cmd/buf
go_install_bin protoc-gen-go v1.30.0 google.golang.org/protobuf/cmd/protoc-gen-go
go_install_bin protoc-gen-go-grpc v1.3.0 google.golang.org/grpc/cmd/protoc-gen-go-grpc
go_install_bin protoc-gen-grpc-gateway v2.16.0 github.com/grpc-ecosystem/grpc-gateway/v2/protoc-gen-grpc-gateway
go_install_bin protoc-gen-openapiv2 v2.16.0 github.com/grpc-ecosystem/grpc-gateway/v2/protoc-gen-openapiv2
echo 'Installation finished'
