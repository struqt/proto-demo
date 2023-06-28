pub mod common {
    pub mod v1 {
        // tonic::include_proto!("struqt.common.v1");
        // include!(concat!(env!("OUT_DIR"), "/struqt.common.v1.rs"));
        include!("../../gen/struqt.common.v1.rs");
        use common_service_server::CommonServiceServer as Serv;
        pub use common_service_server::CommonService;
        pub use crate::handler::Context;

        pub struct Handler {
            pub context: Context,
        }

        pub fn service(context: Context) -> Serv<Handler> {
            Serv::new(Handler { context })
        }
    }
}

pub mod demo {
    pub mod v3 {
        include!("../../gen/struqt.demo.v3.rs");
        pub use crate::handler::Context;
        pub use demo_service_server::DemoService;
        use demo_service_server::DemoServiceServer as Service;

        pub struct Handler {
            pub context: Context,
        }

        pub fn service(context: Context) -> Service<Handler> {
            Service::new(Handler { context })
        }
    }

    pub mod v2 {
        include!("../../gen/struqt.demo.v2.rs");
        pub use crate::handler::Context;
        pub use basic_service_server::BasicService;
        use basic_service_server::BasicServiceServer as Service;

        pub struct Handler {
            pub context: Context,
        }

        pub fn service(context: Context) -> Service<Handler> {
            Service::new(Handler { context })
        }
    }

    pub mod v1 {
        include!("../../gen/struqt.demo.v1.rs");
        pub use crate::handler::Context;

        pub struct DemoHandler {
            pub context: Context,
        }

        pub fn service(context: Context) -> demo_service_server::DemoServiceServer<DemoHandler> {
            demo_service_server::DemoServiceServer::new(DemoHandler { context })
        }

        pub use demo_service_server::DemoService;

        pub struct BasicHandler {
            pub context: Context,
        }

        pub fn service_basic(context: Context) -> basic_service_server::BasicServiceServer<BasicHandler> {
            basic_service_server::BasicServiceServer::new(BasicHandler { context })
        }

        pub use basic_service_server::BasicService;
    }
}
