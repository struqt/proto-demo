pub mod v2 {
    use tonic::{Request, Response, Status};
    use crate::struqt::demo::v2::*;

    pub struct Handler {
        pub context: Context,
    }

    #[tonic::async_trait]
    impl BasicService for Handler {
        async fn echo(&self, request: Request<EchoRequest>) -> Result<Response<EchoResponse>, Status> {
            Ok(Response::new(EchoResponse {
                version: 2,
                value: request.get_ref().value.clone(),
            }))
        }

        async fn json_rpc(&self, _request: Request<JsonRpcRequest>) -> Result<Response<JsonRpcResponse>, Status> {
            todo!()
        }
    }
}
