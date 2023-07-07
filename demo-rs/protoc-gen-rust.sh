#!/usr/bin/env bash
set -euo pipefail
declare -r SELF=$(readlink -f "$0")
declare -r SELF_DIR=${SELF%/*}
echo "Run $SELF"

#export PROTOBUF_LOCATION=$(nix-env -q protobuf --out-path --no-name)
#export PROTOC=$PROTOBUF_LOCATION/bin/protoc
#export PROTOC_INCLUDE=$PROTOBUF_LOCATION/include

pushd "${SELF_DIR}"
cargo build --release --verbose
popd
