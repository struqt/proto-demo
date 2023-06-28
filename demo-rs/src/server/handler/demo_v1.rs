pub mod v1 {
    use tonic::{Request, Response, Status};
    use crate::struqt::demo::v1::*;

    #[tonic::async_trait]
    impl DemoService for DemoHandler {
        async fn echo(&self, request: Request<EchoRequest>) -> Result<Response<EchoResponse>, Status> {
            Ok(Response::new(EchoResponse {
                version: 1,
                value: request.get_ref().value.clone(),
            }))
        }
    }

    #[tonic::async_trait]
    impl BasicService for BasicHandler {
        async fn json_rpc(&self, _request: Request<JsonRpcRequest>) -> Result<Response<JsonRpcResponse>, Status> {
            todo!()
        }
    }
}
