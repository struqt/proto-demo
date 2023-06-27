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
        .map(|dir| format!("../proto/buf/{}", dir))
        .collect();

    let mut out_dir = std::env::current_dir()?;
    out_dir.push("gen");
    // println!("cargo:rustc-env=GEN_OUT_DIR=../../gen");
    println!("cargo:rustc-env=OUT_DIR='{}'", &out_dir.to_string_lossy());
    std::fs::create_dir_all(&out_dir)?;

    tonic_build::configure()
        .out_dir(&out_dir)
        .build_client(false)
        .build_server(true)
        .compile(&proto_files, &proto_dirs)
        ?;
    Ok(())
}
