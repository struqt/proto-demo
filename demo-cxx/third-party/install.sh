#!/bin/bash
set -eo pipefail

declare -rx CMAKE_BUILD_TYPE="$1"

function cmake_build() {
  local NAME="${1}"
  local PROJECT="${2}"
  local SHARED_PREFIX="$PWD/build/target/${NAME:?}"
  local CMAKE_OUT="$PWD/build/cmake/${NAME:?}"
  local BUILD_TYPE='RelWithDebInfo'
  if [ 'Release' == "${CMAKE_BUILD_TYPE}" ]; then
    BUILD_TYPE='Release'
  fi
  echo "$0 -- BUILD_TYPE: ${BUILD_TYPE}"
  if [ -d "${SHARED_PREFIX}/lib" ]; then
    echo "Installed to ${SHARED_PREFIX}"
    return
  fi
  cmake -S "${PROJECT:?}" -B "${CMAKE_OUT}" \
    -D BUILD_SHARED_LIBS=OFF \
    -D CMAKE_BUILD_TYPE="${BUILD_TYPE:-RelWithDebInfo}" \
    -D CMAKE_INSTALL_PREFIX="${SHARED_PREFIX}" \
    "${@:3}"
  pushd "${CMAKE_OUT}"
  make -j 6 install
  echo "Installed to ${SHARED_PREFIX} OK"
  popd
}

function cmake_build_all() {
  local t="$PWD/build/target"
  cmake_build 'abseil-cpp' 'grpc/third_party/abseil-cpp' \
    -D CMAKE_POSITION_INDEPENDENT_CODE=TRUE \
    -D ABSL_PROPAGATE_CXX_STD=ON
  cmake_build 'zlib' 'grpc/third_party/zlib' -D CMAKE_MACOSX_RPATH=OFF
  cmake_build 'c-ares' 'grpc/third_party/cares/cares'
  cmake_build 're2' 'grpc/third_party/re2' -D CMAKE_POSITION_INDEPENDENT_CODE=TRUE
  cmake_build 'protobuf' 'grpc/third_party/protobuf' \
    -D CMAKE_PREFIX_PATH="$t/zlib;$t/abseil-cpp" \
    -D protobuf_BUILD_TESTS=OFF \
    -D protobuf_ABSL_PROVIDER=package
  cmake_build 'grpc' 'grpc' \
    -D CMAKE_PREFIX_PATH="$t/zlib;$t/c-ares;$t/re2;$t/abseil-cpp;$t/protobuf" \
    -D gRPC_BUILD_TESTS=OFF \
    -D gRPC_INSTALL=ON \
    -D gRPC_SSL_PROVIDER=package \
    -D gRPC_ZLIB_PROVIDER=package \
    -D gRPC_CARES_PROVIDER=package \
    -D gRPC_RE2_PROVIDER=package \
    -D gRPC_ABSL_PROVIDER=package \
    -D gRPC_PROTOBUF_PROVIDER=package
}

if [ ! -d ./grpc ]; then
  git -c advice.detachedHead=false clone -j 6 \
    --recurse-submodules --shallow-submodules --depth 10 \
    -b v1.56.x https://github.com/grpc/grpc
fi

cmake_build_all