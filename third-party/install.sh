#!/bin/bash
set -euo pipefail

declare -rx BUILD_TYPE="${1:-RelWithDebInfo}"
declare -rx GRPC_VERSION="${2:-1.56}"

declare -r SELF=$(readlink -f "$0")
declare -r SELF_DIR=${SELF%/*}

echo "Run ${SELF} --- ${BUILD_TYPE:?} ${GRPC_VERSION:?}"

function cmake_build() {
  local NAME="${1}"
  local PROJECT="${2}"
  local SHARED_PREFIX="$SELF_DIR/build/target/${NAME:?}"
  local CMAKE_OUT="$SELF_DIR/build/cmake/${NAME:?}"
  if [ -d "${SHARED_PREFIX}/lib" ]; then
    echo "Installed to ${SHARED_PREFIX}"
    return
  fi
  cmake -S "$SELF_DIR/${PROJECT:?}" -B "${CMAKE_OUT}" \
    -D BUILD_SHARED_LIBS=OFF \
    -D CMAKE_BUILD_TYPE="${BUILD_TYPE:?}" \
    -D CMAKE_INSTALL_PREFIX="${SHARED_PREFIX}" \
    "${@:3}"
  pushd "${CMAKE_OUT}"
  make -j 6 install
  echo "Installed to ${SHARED_PREFIX} OK"
  popd
}

function cmake_build_grpc() {
  local t="$SELF_DIR/build/target"
  cmake_build 'c-ares' 'grpc/third_party/cares/cares'
  cmake_build 're2' 'grpc/third_party/re2' -D CMAKE_POSITION_INDEPENDENT_CODE=TRUE
  cmake_build 'abseil-cpp' 'grpc/third_party/abseil-cpp' \
    -D CMAKE_POSITION_INDEPENDENT_CODE=TRUE \
    -D ABSL_PROPAGATE_CXX_STD=ON
  cmake_build 'protobuf' 'grpc/third_party/protobuf' \
    -D CMAKE_PREFIX_PATH="$t/abseil-cpp" \
    -D protobuf_BUILD_TESTS=OFF \
    -D protobuf_INSTALL=ON \
    -D protobuf_ABSL_PROVIDER=package
  cmake_build 'grpc' 'grpc' \
    -D CMAKE_PREFIX_PATH="$t/c-ares;$t/re2;$t/abseil-cpp;$t/protobuf" \
    -D gRPC_BUILD_TESTS=OFF \
    -D gRPC_INSTALL=ON \
    -D gRPC_SSL_PROVIDER=module    \
    -D gRPC_ZLIB_PROVIDER=module   \
    -D gRPC_CARES_PROVIDER=package \
    -D gRPC_RE2_PROVIDER=package   \
    -D gRPC_ABSL_PROVIDER=package  \
    -D gRPC_PROTOBUF_PROVIDER=package
}

if [ ! -d "${SELF_DIR}/grpc" ]; then
  git -c advice.detachedHead=false clone -j 6 \
    --recurse-submodules --shallow-submodules --depth 10 -b "v${GRPC_VERSION}.x" \
    https://github.com/grpc/grpc "${SELF_DIR}/grpc"
fi

cmake_build_grpc
