use clap::Parser;

mod struqt;
mod handler;

type Yes<T> = Result<T, Box<dyn std::error::Error>>;

#[derive(Parser, Debug)]
#[command(author, version, about, long_about = None)]
struct Args {
    /// Address to listen
    #[arg(short, long, default_value_t = String::from("127.0.0.1:9090"))]
    address: String,
}


fn main() -> Yes<()> {
    let args = Args::parse();
    let threads = std::env::var("GRPC_WORKER_THREADS")
        .map(|v| v.parse().unwrap())
        .unwrap_or(2);
    println!("Running with {} threads", threads);
    tokio::runtime::Builder::new_multi_thread()
        .worker_threads(threads)
        .enable_all()
        .build()?
        .block_on(serve(&args.address))
}

async fn serve(address: &str) -> Yes<()> {
    let context = &handler::context();
    let address = address.parse()?;
    let router = handler::server(context);
    println!("Server is listening on {}", address);
    router.serve(address).await?;
    println!("Server is shutting down");
    Ok(())
}
