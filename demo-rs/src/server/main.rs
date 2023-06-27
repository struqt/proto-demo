mod struqt;
mod handler;

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    let addr = "127.0.0.1:9090".parse().unwrap();
    let ctx = &handler::context();
    println!("Server is listening on {}", addr);
    handler::server(ctx).serve(addr).await?;
    Ok(())
}
