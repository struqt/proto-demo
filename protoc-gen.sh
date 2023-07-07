#!/usr/bin/env bash
set -euo pipefail

declare -r SELF=$(readlink -f "$0")
declare -r SELF_DIR=${SELF%/*}
echo "Run $SELF"

protoc_gen_all() {
  "$SELF_DIR"/demo-cxx/protoc-gen-cxx.sh
  "$SELF_DIR"/demo-go/protoc-gen-go.sh
  "$SELF_DIR"/demo-rs/protoc-gen-rust.sh
}

protoc_gen() {
  local module_name=${1:-proto}
  local sync_file="${SELF_DIR}/protoc-gen.sync"
  local commit_sha_old=''
  if [ -f "${sync_file}" ]; then
    commit_sha_old="$(cat "${sync_file}")"
  fi
  local commit_sha_new
  commit_sha_new="$(git submodule status "${module_name}" | awk '{ print $1 }')"
  commit_sha_new=${commit_sha_new#+}
  echo "${commit_sha_old} ===> ${commit_sha_new}"
  git submodule status "${module_name}"
  if [ "${commit_sha_old}" == "${commit_sha_new}" ]; then
    echo "Ignored. No changes."
    return
  fi
  protoc_gen_all
  echo "${commit_sha_new}" >"${sync_file}"
}

protoc_gen 'proto'
