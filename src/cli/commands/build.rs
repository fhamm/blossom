use std::path::PathBuf;

use blossom_compiler::compile;
use blossom_config::BlossomConfig;

pub fn execute(directory: &PathBuf) -> Result<(), String> {
    let config = BlossomConfig::load(directory)?;

    // Need to retrieve all the files
    compile(&config);
    Ok(())
}
