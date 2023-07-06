#!/usr/bin/env bash
set -euo pipefail

declare -r SELF=$(readlink -f "$0")
declare -r SELF_DIR=${SELF%/*}
declare -r PROJECT_DIR=${SELF_DIR%/*}
echo "$SELF"

declare -r GRPC_PATH="${PROJECT_DIR}/third-party/build/target/grpc/bin"
declare -r PROTOC_PATH="${PROJECT_DIR}/third-party/build/target/protobuf/bin"
declare -r PROTO_FILE_PATH="${PROJECT_DIR}/proto"
PROTO_MOD_NAMES=()
#PROTO_MOD_NAMES+=("googleapis")
#PROTO_MOD_NAMES+=("grpc-gateway")
#PROTO_MOD_NAMES+=("common")
#PROTO_MOD_NAMES+=("demo")

protoc_gen() {
  local dir_array
  local line
  pushd "${PROTO_FILE_PATH:?}"
  if [ ${#PROTO_MOD_NAMES[@]} -eq 0 ]; then
    dir_array=()
    while IFS= read -r line; do
      if [ "$line" != "." ]; then dir_array+=("$line"); fi
    done < <(find . -maxdepth 1 -type d | cut -d/ -f2)
  else
    dir_array=("${PROTO_MOD_NAMES[@]}")
  fi
  local proto_files=()
  for dir in "${dir_array[@]}"; do
    pushd "$dir"
    while IFS= read -r line; do
      proto_files+=("$line")
    done < <(find . -maxdepth 99 -name "*.proto" | cut -d/ -f2-)
    popd
  done
  popd
  local proto_paths=()
  local dir
  for dir in "${dir_array[@]}"; do
    proto_paths+=("--proto_path=${PROTO_FILE_PATH}/$dir")
  done
  "${PROTOC_PATH:?}"/protoc \
    "${@}" \
    "${proto_paths[@]}" \
    "${proto_files[@]}"
}

protoc_gen_grpc_cxx() {
  [ "${1:-}" ] || return 1
  local cpp_out_dir=${1}
  local grpc_out_dir=${2:-${cpp_out_dir}}
  mkdir -p "${cpp_out_dir}" "${grpc_out_dir}"
  protoc_gen \
    --cpp_out="${cpp_out_dir}" \
    --grpc_out="${grpc_out_dir}" \
    --plugin=protoc-gen-grpc="${GRPC_PATH:?}/grpc_cpp_plugin"
}

protoc_gen_grpc_cxx "${SELF_DIR}/gen-cxx" "${SELF_DIR}/gen-cxx-grpc"
