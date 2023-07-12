# Demo Projects of gRPC

[![Main Workflow](https://github.com/struqt/proto-demo/actions/workflows/main.yml/badge.svg)](https://github.com/struqt/proto-demo/actions/workflows/main.yml)
[![Lint](https://github.com/struqt/proto-demo/actions/workflows/lint.yml/badge.svg)](https://github.com/struqt/proto-demo/actions/workflows/lint.yml)

---

## Setup and Build

### Debian

```
apt install -y build-essential autoconf libtool pkg-config
apt install -y cmake ca-certificates libssl-dev
apt install -y golang
```

### macOS

```
brew install git
brew install cmake openssl
brew install rustup
brew install goenv
goenv install 1.19
```

### Build

```
git clone --recurse-submodules https://github.com/struqt/proto-demo.git
./proto-demo/build.sh
```

---

## Performance References

- [grpc.io - Benchmarking](https://grpc.io/docs/guides/benchmarking/)
- [grpc.io - Performance Best Practices](https://grpc.io/docs/guides/performance)
- [github.com - grpc_bench](https://github.com/LesnyRumcajs/grpc_bench)
