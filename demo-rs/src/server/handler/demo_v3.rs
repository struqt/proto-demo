pub mod v3 {
    use tonic::{Request, Response, Status};
    use crate::struqt::demo::v3::*;

    pub struct Handler {
        pub context: Context,
    }

    #[tonic::async_trait]
    impl DemoService for Handler {
        async fn echo_value(&self, request: Request<EchoValueRequest>) -> Result<Response<EchoValueResponse>, Status> {
            use std::time::SystemTime;
            let now = prost_types::Timestamp::from(SystemTime::now());
            Ok(Response::new(EchoValueResponse {
                value: request.get_ref().value.clone(),
                timestamp: Some(now),
                pb3_message: Some(Proto3Message::default()),
            }))
        }
    }
}
