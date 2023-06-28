pub mod v1 {
    use crate::struqt::common::v1::*;
    use std::time::SystemTime;
    use tonic::{Extensions, Request, Response, Status};
    use tonic::codegen::http::HeaderMap;
    use tonic::metadata::MetadataMap;

    #[tonic::async_trait]
    impl CommonService for Handler {
        async fn get_server_info(&self, request: Request<GetServerInfoRequest>) ->
        Result<Response<GetServerInfoResponse>, Status> {
            let host = format!("demo#{}", self.context.server_id);
            let mut map = HeaderMap::new();
            map.insert("x-host", host.parse().unwrap());
            let message = GetServerInfoResponse {
                server_id: self.context.server_id,
                started_at: Some(prost_types::Timestamp::from(self.context.started_at)),
                status: ServerStatus::Running.into(),
                timestamp: Some(prost_types::Timestamp::from(SystemTime::now())),
            };
            let metadata = MetadataMap::from_headers(map);
            let extensions = Extensions::default();
            let response = Response::from_parts(metadata, message, extensions);
            println!("=== {:?}\n== {:?}", request, response);
            Ok(response)
        }
    }
}
