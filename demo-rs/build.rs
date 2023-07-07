use std::env;
use std::fs;
use std::path::{Path, PathBuf};

use walkdir::WalkDir;

type Yes<T> = Result<T, Box<dyn std::error::Error>>;

fn main() -> Yes<()> {
    // if env::var("GITHUB_ACTIONS").is_ok() {
    //     return Ok(());
    // }
    let dir = &env::current_dir()?;
    let src = &dir.parent().unwrap().join("proto");
    let out = &dir.join("gen");
    let names = vec![
        // "googleapis",
        // "grpc-gateway",
        // "common",
        // "demo",
    ];
    protoc_gen_by_tonic(&names, src, out)
}

fn protoc_gen_by_tonic(names: &Vec<&str>, src: &Path, out: &Path) -> Yes<()> {
    let _ = protoc_exec_path_set();
    let (files, paths) = &proto_paths_and_files(names, src)?;
    if let Some(s) = out.to_str() {
        println!("cargo:rustc-env=OUT_DIR='{}'", s);
        fs::create_dir_all(out)?;
    }
    tonic_build::configure()
        .out_dir(out).build_client(false).build_server(true)
        .compile(files, paths)?
    ;
    Ok(())
}

fn proto_paths_and_files(names: &Vec<&str>, src: &Path) -> Yes<(Vec<String>, Vec<PathBuf>)> {
    let proto_paths: Vec<_> = if names.is_empty() {
        fs::read_dir(src)?.into_iter()
            .filter_map(|x| x.ok()).map(|x| x.path()).filter(|x| x.is_dir()).collect()
    } else {
        names.iter().map(|i| src.join(i)).filter(|x| x.is_dir()).collect()
    };
    let proto_files = proto_paths.iter().flat_map(|x| collect_by_ext(x, "proto")).collect();
    Ok((proto_files, proto_paths))
}

fn collect_by_ext(path: &Path, file_ext: &str) -> Vec<String> {
    WalkDir::new(path).into_iter()
        .filter_map(|x| x.ok())
        .filter(|x| x.file_type().is_file())
        .filter(|x| x.path().extension().and_then(|s| s.to_str()) == Some(file_ext))
        .map(|x| x.path().display().to_string())
        .collect()
}

fn protoc_exec_path_set() -> Yes<()> {
    let protoc_path = env::current_dir()?
        .parent().unwrap().join("third-party/build/target/protobuf/bin");
    if protoc_path.exists() {
        let path_var = env::var("PATH").unwrap_or_else(|_| "".to_string());
        if let Some(protoc_str) = protoc_path.to_str() {
            let new_path = format!("{}:{}", protoc_str, path_var);
            env::set_var("PATH", new_path);
        } else {
            eprintln!("Invalid UTF-8 in path: {}", protoc_path.to_string_lossy());
        }
    }
    Ok(())
}
