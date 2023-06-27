#[allow(clippy::derive_partial_eq_without_eq)]
#[derive(Clone, PartialEq, ::prost::Message)]
pub struct EchoValueRequest {
    #[prost(message, optional, tag = "1")]
    pub value: ::core::option::Option<::prost_types::Value>,
}
#[allow(clippy::derive_partial_eq_without_eq)]
#[derive(Clone, PartialEq, ::prost::Message)]
pub struct EchoValueResponse {
    #[prost(message, optional, tag = "1")]
    pub value: ::core::option::Option<::prost_types::Value>,
    #[prost(message, optional, tag = "2")]
    pub timestamp: ::core::option::Option<::prost_types::Timestamp>,
    #[prost(message, optional, tag = "3")]
    pub pb3_message: ::core::option::Option<Proto3Message>,
}
#[allow(clippy::derive_partial_eq_without_eq)]
#[derive(Clone, PartialEq, ::prost::Message)]
pub struct Proto3Message {
    /// Next number: 49
    #[prost(message, optional, boxed, tag = "41")]
    pub nested: ::core::option::Option<::prost::alloc::boxed::Box<Proto3Message>>,
    #[prost(float, tag = "42")]
    pub float_value: f32,
    #[prost(double, tag = "43")]
    pub double_value: f64,
    #[prost(int64, tag = "3")]
    pub int64_value: i64,
    #[prost(int32, tag = "4")]
    pub int32_value: i32,
    #[prost(uint64, tag = "5")]
    pub uint64_value: u64,
    #[prost(uint32, tag = "6")]
    pub uint32_value: u32,
    #[prost(bool, tag = "7")]
    pub bool_value: bool,
    #[prost(string, tag = "8")]
    pub string_value: ::prost::alloc::string::String,
    #[prost(bytes = "vec", tag = "9")]
    pub bytes_value: ::prost::alloc::vec::Vec<u8>,
    #[prost(string, repeated, tag = "10")]
    pub repeated_value: ::prost::alloc::vec::Vec<::prost::alloc::string::String>,
    #[prost(message, repeated, tag = "44")]
    pub repeated_message: ::prost::alloc::vec::Vec<u64>,
    #[prost(enumeration = "EnumValue", tag = "11")]
    pub enum_value: i32,
    #[prost(enumeration = "EnumValue", repeated, tag = "12")]
    pub repeated_enum: ::prost::alloc::vec::Vec<i32>,
    #[prost(message, optional, tag = "13")]
    pub timestamp_value: ::core::option::Option<::prost_types::Timestamp>,
    #[prost(message, optional, tag = "14")]
    pub duration_value: ::core::option::Option<::prost_types::Duration>,
    #[prost(message, optional, tag = "15")]
    pub field_mask_value: ::core::option::Option<::prost_types::FieldMask>,
    #[prost(message, optional, tag = "17")]
    pub wrapper_double_value: ::core::option::Option<f64>,
    #[prost(message, optional, tag = "18")]
    pub wrapper_float_value: ::core::option::Option<f32>,
    #[prost(message, optional, tag = "19")]
    pub wrapper_int64_value: ::core::option::Option<i64>,
    #[prost(message, optional, tag = "20")]
    pub wrapper_int32_value: ::core::option::Option<i32>,
    #[prost(message, optional, tag = "21")]
    pub wrapper_u_int64_value: ::core::option::Option<u64>,
    #[prost(message, optional, tag = "22")]
    pub wrapper_u_int32_value: ::core::option::Option<u32>,
    #[prost(message, optional, tag = "23")]
    pub wrapper_bool_value: ::core::option::Option<bool>,
    #[prost(message, optional, tag = "24")]
    pub wrapper_string_value: ::core::option::Option<::prost::alloc::string::String>,
    #[prost(message, optional, tag = "25")]
    pub wrapper_bytes_value: ::core::option::Option<::prost::alloc::vec::Vec<u8>>,
    #[prost(map = "string, string", tag = "26")]
    pub map_value: ::std::collections::HashMap<
        ::prost::alloc::string::String,
        ::prost::alloc::string::String,
    >,
    #[prost(map = "string, int32", tag = "27")]
    pub map_value2: ::std::collections::HashMap<::prost::alloc::string::String, i32>,
    #[prost(map = "int32, string", tag = "28")]
    pub map_value3: ::std::collections::HashMap<i32, ::prost::alloc::string::String>,
    #[prost(map = "string, int64", tag = "29")]
    pub map_value4: ::std::collections::HashMap<::prost::alloc::string::String, i64>,
    #[prost(map = "int64, string", tag = "30")]
    pub map_value5: ::std::collections::HashMap<i64, ::prost::alloc::string::String>,
    #[prost(map = "string, uint32", tag = "31")]
    pub map_value6: ::std::collections::HashMap<::prost::alloc::string::String, u32>,
    #[prost(map = "uint32, string", tag = "32")]
    pub map_value7: ::std::collections::HashMap<u32, ::prost::alloc::string::String>,
    #[prost(map = "string, uint64", tag = "33")]
    pub map_value8: ::std::collections::HashMap<::prost::alloc::string::String, u64>,
    #[prost(map = "uint64, string", tag = "34")]
    pub map_value9: ::std::collections::HashMap<u64, ::prost::alloc::string::String>,
    #[prost(map = "string, float", tag = "35")]
    pub map_value10: ::std::collections::HashMap<::prost::alloc::string::String, f32>,
    #[prost(map = "string, double", tag = "37")]
    pub map_value12: ::std::collections::HashMap<::prost::alloc::string::String, f64>,
    #[prost(map = "string, bool", tag = "39")]
    pub map_value14: ::std::collections::HashMap<::prost::alloc::string::String, bool>,
    #[prost(map = "bool, string", tag = "40")]
    pub map_value15: ::std::collections::HashMap<bool, ::prost::alloc::string::String>,
    #[prost(map = "string, message", tag = "45")]
    pub map_value16: ::std::collections::HashMap<::prost::alloc::string::String, u64>,
    #[prost(message, optional, tag = "47")]
    pub struct_value_value: ::core::option::Option<::prost_types::Value>,
    #[prost(message, optional, tag = "48")]
    pub struct_value: ::core::option::Option<::prost_types::Struct>,
    #[prost(oneof = "proto3_message::OneofValue", tags = "1, 2")]
    pub oneof_value: ::core::option::Option<proto3_message::OneofValue>,
    #[prost(oneof = "proto3_message::NestedOneofValue", tags = "46")]
    pub nested_oneof_value: ::core::option::Option<proto3_message::NestedOneofValue>,
}
/// Nested message and enum types in `Proto3Message`.
pub mod proto3_message {
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Clone, PartialEq, ::prost::Oneof)]
    pub enum OneofValue {
        #[prost(bool, tag = "1")]
        OneofBoolValue(bool),
        #[prost(string, tag = "2")]
        OneofStringValue(::prost::alloc::string::String),
    }
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Clone, PartialEq, ::prost::Oneof)]
    pub enum NestedOneofValue {
        #[prost(message, tag = "46")]
        NestedOneofValueOne(::prost::alloc::boxed::Box<super::Proto3Message>),
    }
}
#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash, PartialOrd, Ord, ::prost::Enumeration)]
#[repr(i32)]
pub enum EnumValue {
    Unspecified = 0,
    X = 1,
    Y = 2,
    Z = 3,
}
impl EnumValue {
    /// String value of the enum field names used in the ProtoBuf definition.
    ///
    /// The values are not transformed in any way and thus are considered stable
    /// (if the ProtoBuf definition does not change) and safe for programmatic use.
    pub fn as_str_name(&self) -> &'static str {
        match self {
            EnumValue::Unspecified => "ENUM_VALUE_UNSPECIFIED",
            EnumValue::X => "ENUM_VALUE_X",
            EnumValue::Y => "ENUM_VALUE_Y",
            EnumValue::Z => "ENUM_VALUE_Z",
        }
    }
    /// Creates an enum from field names used in the ProtoBuf definition.
    pub fn from_str_name(value: &str) -> ::core::option::Option<Self> {
        match value {
            "ENUM_VALUE_UNSPECIFIED" => Some(Self::Unspecified),
            "ENUM_VALUE_X" => Some(Self::X),
            "ENUM_VALUE_Y" => Some(Self::Y),
            "ENUM_VALUE_Z" => Some(Self::Z),
            _ => None,
        }
    }
}
/// Generated server implementations.
pub mod demo_service_server {
    #![allow(unused_variables, dead_code, missing_docs, clippy::let_unit_value)]
    use tonic::codegen::*;
    /// Generated trait containing gRPC methods that should be implemented for use with DemoServiceServer.
    #[async_trait]
    pub trait DemoService: Send + Sync + 'static {
        async fn echo_value(
            &self,
            request: tonic::Request<super::EchoValueRequest>,
        ) -> std::result::Result<
            tonic::Response<super::EchoValueResponse>,
            tonic::Status,
        >;
    }
    #[derive(Debug)]
    pub struct DemoServiceServer<T: DemoService> {
        inner: _Inner<T>,
        accept_compression_encodings: EnabledCompressionEncodings,
        send_compression_encodings: EnabledCompressionEncodings,
        max_decoding_message_size: Option<usize>,
        max_encoding_message_size: Option<usize>,
    }
    struct _Inner<T>(Arc<T>);
    impl<T: DemoService> DemoServiceServer<T> {
        pub fn new(inner: T) -> Self {
            Self::from_arc(Arc::new(inner))
        }
        pub fn from_arc(inner: Arc<T>) -> Self {
            let inner = _Inner(inner);
            Self {
                inner,
                accept_compression_encodings: Default::default(),
                send_compression_encodings: Default::default(),
                max_decoding_message_size: None,
                max_encoding_message_size: None,
            }
        }
        pub fn with_interceptor<F>(
            inner: T,
            interceptor: F,
        ) -> InterceptedService<Self, F>
        where
            F: tonic::service::Interceptor,
        {
            InterceptedService::new(Self::new(inner), interceptor)
        }
        /// Enable decompressing requests with the given encoding.
        #[must_use]
        pub fn accept_compressed(mut self, encoding: CompressionEncoding) -> Self {
            self.accept_compression_encodings.enable(encoding);
            self
        }
        /// Compress responses with the given encoding, if the client supports it.
        #[must_use]
        pub fn send_compressed(mut self, encoding: CompressionEncoding) -> Self {
            self.send_compression_encodings.enable(encoding);
            self
        }
        /// Limits the maximum size of a decoded message.
        ///
        /// Default: `4MB`
        #[must_use]
        pub fn max_decoding_message_size(mut self, limit: usize) -> Self {
            self.max_decoding_message_size = Some(limit);
            self
        }
        /// Limits the maximum size of an encoded message.
        ///
        /// Default: `usize::MAX`
        #[must_use]
        pub fn max_encoding_message_size(mut self, limit: usize) -> Self {
            self.max_encoding_message_size = Some(limit);
            self
        }
    }
    impl<T, B> tonic::codegen::Service<http::Request<B>> for DemoServiceServer<T>
    where
        T: DemoService,
        B: Body + Send + 'static,
        B::Error: Into<StdError> + Send + 'static,
    {
        type Response = http::Response<tonic::body::BoxBody>;
        type Error = std::convert::Infallible;
        type Future = BoxFuture<Self::Response, Self::Error>;
        fn poll_ready(
            &mut self,
            _cx: &mut Context<'_>,
        ) -> Poll<std::result::Result<(), Self::Error>> {
            Poll::Ready(Ok(()))
        }
        fn call(&mut self, req: http::Request<B>) -> Self::Future {
            let inner = self.inner.clone();
            match req.uri().path() {
                "/struqt.demo.v3.DemoService/EchoValue" => {
                    #[allow(non_camel_case_types)]
                    struct EchoValueSvc<T: DemoService>(pub Arc<T>);
                    impl<
                        T: DemoService,
                    > tonic::server::UnaryService<super::EchoValueRequest>
                    for EchoValueSvc<T> {
                        type Response = super::EchoValueResponse;
                        type Future = BoxFuture<
                            tonic::Response<Self::Response>,
                            tonic::Status,
                        >;
                        fn call(
                            &mut self,
                            request: tonic::Request<super::EchoValueRequest>,
                        ) -> Self::Future {
                            let inner = Arc::clone(&self.0);
                            let fut = async move { (*inner).echo_value(request).await };
                            Box::pin(fut)
                        }
                    }
                    let accept_compression_encodings = self.accept_compression_encodings;
                    let send_compression_encodings = self.send_compression_encodings;
                    let max_decoding_message_size = self.max_decoding_message_size;
                    let max_encoding_message_size = self.max_encoding_message_size;
                    let inner = self.inner.clone();
                    let fut = async move {
                        let inner = inner.0;
                        let method = EchoValueSvc(inner);
                        let codec = tonic::codec::ProstCodec::default();
                        let mut grpc = tonic::server::Grpc::new(codec)
                            .apply_compression_config(
                                accept_compression_encodings,
                                send_compression_encodings,
                            )
                            .apply_max_message_size_config(
                                max_decoding_message_size,
                                max_encoding_message_size,
                            );
                        let res = grpc.unary(method, req).await;
                        Ok(res)
                    };
                    Box::pin(fut)
                }
                _ => {
                    Box::pin(async move {
                        Ok(
                            http::Response::builder()
                                .status(200)
                                .header("grpc-status", "12")
                                .header("content-type", "application/grpc")
                                .body(empty_body())
                                .unwrap(),
                        )
                    })
                }
            }
        }
    }
    impl<T: DemoService> Clone for DemoServiceServer<T> {
        fn clone(&self) -> Self {
            let inner = self.inner.clone();
            Self {
                inner,
                accept_compression_encodings: self.accept_compression_encodings,
                send_compression_encodings: self.send_compression_encodings,
                max_decoding_message_size: self.max_decoding_message_size,
                max_encoding_message_size: self.max_encoding_message_size,
            }
        }
    }
    impl<T: DemoService> Clone for _Inner<T> {
        fn clone(&self) -> Self {
            Self(Arc::clone(&self.0))
        }
    }
    impl<T: std::fmt::Debug> std::fmt::Debug for _Inner<T> {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            write!(f, "{:?}", self.0)
        }
    }
    impl<T: DemoService> tonic::server::NamedService for DemoServiceServer<T> {
        const NAME: &'static str = "struqt.demo.v3.DemoService";
    }
}
