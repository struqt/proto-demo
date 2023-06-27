pub mod v1 {
    use tonic::{Request, Response, Status};
    use crate::struqt::common::v1::*;

    pub struct Handler {
        pub context: Context,
    }

    #[tonic::async_trait]
    impl CommonService for Handler {
        async fn get_server_info(&self, _request: Request<GetServerInfoRequest>) ->
        Result<Response<GetServerInfoResponse>, Status> {
            Ok(Response::new(GetServerInfoResponse {
                server_id: self.context.server_id,
                started_at: Some(prost_types::Timestamp::from(self.context.started_at)),
                status: ServerStatus::Running.into(),
            }))
        }
    }
}
