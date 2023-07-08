#!/usr/bin/env bash
set -euo pipefail

declare -r SELF=$(readlink -f "$0")
declare -r SELF_DIR=${SELF%/*}
echo "Run $SELF"

cargo_build() {
  local dir="${1}"
  pushd "${dir:?}" || return 1
  cargo build --release --verbose
  ls -lhA "${dir}/target/release"
  popd || return 1
}

go_build() {
  declare -r GO_PROJECT_DIR="${SELF_DIR}/demo-go"
  declare -r GO_OUT_DIR="${GO_PROJECT_DIR}/.go/bin"
  mkdir -p "${GO_OUT_DIR}"
  pushd "${GO_OUT_DIR}" || exit 1
  go build -v ../../server/cmd/demo-grpc
  go build -v ../../server/cmd/demo-gate
  go build -v ../../server/cmd/demo
  ls -lhA
  popd || exit 1
}

cmake_build() {
  declare -r BUILD_TYPE='Release'
  declare -r CMAKE_PROJECT_DIR="${SELF_DIR}/demo-cxx"
  cmake -B "${CMAKE_PROJECT_DIR}/build" -D CMAKE_BUILD_TYPE="${BUILD_TYPE}" -S "${CMAKE_PROJECT_DIR}/"
  cmake --build "${CMAKE_PROJECT_DIR}/build" -j 6 --config "${BUILD_TYPE}"
  ls -lhA "${CMAKE_PROJECT_DIR}/build"
}

"${SELF_DIR}"/third-party/install.sh 'Release'

cargo_build "${SELF_DIR}/demo-rs"

go_build "${SELF_DIR}/demo-go"

cmake_build "${SELF_DIR}/demo-cxx"
