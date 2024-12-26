use std::path::PathBuf;

use blossom_compiler::Compiler;
use blossom_config::BlossomConfig;

pub fn execute(directory: &PathBuf) -> Result<(), String> {
    let config = BlossomConfig::load(directory)?;
    let absolute_path = directory
        .canonicalize()
        .map_err(|e| format!("Failed to get absolute path: {}", e))?;
    let compiler = Compiler::new(config, absolute_path);
    compiler.compile()?;
    Ok(())
}
