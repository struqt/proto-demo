module github.com/struqt/proto-demo/demo-go/server

go 1.21

require github.com/struqt/proto v1.0.0

replace github.com/struqt/proto => ../proto

require (
	github.com/golang/glog v1.2.0
	github.com/grpc-ecosystem/grpc-gateway/v2 v2.19.0
	github.com/rs/zerolog v1.31.0
	google.golang.org/genproto/googleapis/rpc v0.0.0-20240125205218-1f4bbc51befe
	google.golang.org/grpc v1.61.0
	google.golang.org/protobuf v1.32.0
	gopkg.in/natefinch/lumberjack.v2 v2.2.1
)

require (
	github.com/golang/protobuf v1.5.3 // indirect
	github.com/mattn/go-colorable v0.1.13 // indirect
	github.com/mattn/go-isatty v0.0.20 // indirect
	golang.org/x/net v0.20.0 // indirect
	golang.org/x/sys v0.16.0 // indirect
	golang.org/x/text v0.14.0 // indirect
	google.golang.org/genproto v0.0.0-20240125205218-1f4bbc51befe // indirect
	google.golang.org/genproto/googleapis/api v0.0.0-20240125205218-1f4bbc51befe // indirect
)
