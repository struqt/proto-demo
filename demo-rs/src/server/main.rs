mod struqt;
mod handler;

type Yes<T> = Result<T, Box<dyn std::error::Error>>;

fn main() -> Yes<()> {
    let threads = std::env::var("GRPC_WORKER_THREADS")
        .map(|v| v.parse().unwrap())
        .unwrap_or(2);
    println!("Running with {} threads", threads);
    tokio::runtime::Builder::new_multi_thread()
        .worker_threads(threads)
        .enable_all()
        .build()?
        .block_on(serve())
}

async fn serve() -> Yes<()> {
    let context = &handler::context();
    let address = "127.0.0.1:9090".parse()?;
    let router = handler::server(context);
    println!("Server is listening on {}", address);
    router.serve(address).await?;
    println!("Server is shutting down");
    Ok(())
}
