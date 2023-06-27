pub mod common {
    pub mod v1 {
        // tonic::include_proto!("struqt.common.v1");
        // include!(concat!(env!("OUT_DIR"), "/struqt.common.v1.rs"));
        include!("../../gen/struqt.common.v1.rs");
        use common_service_server::CommonServiceServer as Serv;
        pub use common_service_server::CommonService;
        pub use crate::handler::{Context, common::v1::Handler};

        pub fn service(context: Context) -> Serv<Handler> {
            Serv::new(Handler { context })
        }
    }
}

pub mod demo {
    pub mod v1 {
        include!("../../gen/struqt.demo.v1.rs");
        use basic_service_server::BasicServiceServer as ServB;
        use demo_service_server::DemoServiceServer as ServD;
        pub use basic_service_server::BasicService;
        pub use demo_service_server::DemoService;
        pub use crate::handler::{Context, demo::v1::Handler};

        pub fn service_basic(context: Context) -> ServB<Handler> {
            ServB::new(Handler { context })
        }

        pub fn service(context: Context) -> ServD<Handler> {
            ServD::new(Handler { context })
        }
    }

    pub mod v2 {
        include!("../../gen/struqt.demo.v2.rs");
        use basic_service_server::BasicServiceServer as Service;
        pub use basic_service_server::BasicService;
        pub use crate::handler::{Context, demo::v2::Handler};

        pub fn service(context: Context) -> Service<Handler> {
            Service::new(Handler { context })
        }
    }

    pub mod v3 {
        include!("../../gen/struqt.demo.v3.rs");
        use demo_service_server::DemoServiceServer as Service;
        pub use demo_service_server::DemoService;
        pub use crate::handler::{Context, demo::v3::Handler};

        pub fn service(context: Context) -> Service<Handler> {
            Service::new(Handler { context })
        }
    }
}
