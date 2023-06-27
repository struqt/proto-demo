pub mod common;

pub mod demo {
    include!("demo_v1.rs");
    include!("demo_v2.rs");
    include!("demo_v3.rs");
}

use std::sync::Arc;
use std::time::SystemTime;

pub type Context = Arc<ServerContext>;

pub struct ServerContext {
    server_id: i32,
    started_at: SystemTime,
    // db_pool ...
}

pub fn context() -> Arc<ServerContext> {
    let context = ServerContext {
        server_id: 999,
        started_at: SystemTime::now(),
    };
    Arc::new(context)
}

pub fn server(c: &Arc<ServerContext>) -> tonic::transport::server::Router {
    use crate::struqt::*;
    tonic::transport::Server::builder()
        .add_service(common::v1::service(c.clone()))
        .add_service(demo::v1::service_basic(c.clone()))
        .add_service(demo::v1::service(c.clone()))
        .add_service(demo::v2::service(c.clone()))
        .add_service(demo::v3::service(c.clone()))
}
