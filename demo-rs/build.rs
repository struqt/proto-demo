fn main() -> Result<(), Box<dyn std::error::Error>> {
    let proto_files: Vec<String> = vec![
        "common/v1/common",
        "demo/v1/demo",
        "demo/v2/demo",
        "demo/v3/demo",
        "demo/v3/messages",
    ].into_iter()
        .map(|file| format!("struqt/{}.proto", file))
        .collect();

    let proto_dirs: Vec<String> = vec![
        "googleapis",
        "grpc-gateway",
        "common",
        "demo",
    ].into_iter()
        .map(|dir| format!("../proto/{}", dir))
        .collect();

    let out_dir = std::env::current_dir()?.join("gen");
    if let Some(s) = out_dir.to_str() {
        println!("cargo:rustc-env=OUT_DIR='{}'", s);
        std::fs::create_dir_all(&out_dir)?;
    }

    let protoc_path = std::env::current_dir()?
        .join("../third-party/build/target/protobuf/bin");
    if protoc_path.exists() {
        let path_var = std::env::var("PATH").unwrap_or_else(|_| String::from(""));
        if let Some(protoc_str) = protoc_path.to_str() {
            let new_path = format!("{}:{}", protoc_str, path_var);
            std::env::set_var("PATH", new_path);
        } else {
            eprintln!("Invalid UTF-8 in path: {}", protoc_path.to_string_lossy());
        }
    }

    tonic_build::configure()
        .out_dir(&out_dir)
        .build_client(false)
        .build_server(true)
        .compile(&proto_files, &proto_dirs)
        ?;
    Ok(())
}
