use crate::finder::SourceFinder;
use blossom_config::BlossomConfig;
use std::path::PathBuf;

mod constants;
mod finder;
mod parser;

use parser::parse;

pub struct Compiler {
    config: BlossomConfig,
    root_path: PathBuf,
}

impl Compiler {
    pub fn new(config: BlossomConfig, root_path: PathBuf) -> Self {
        Self { config, root_path }
    }

    pub fn compile(&self) -> Result<(), String> {
        let sources = SourceFinder::new(&self.config, &self.root_path).find_source_files()?;

        for source_path in sources {
            self.compile_file(&source_path)?;
        }
        Ok(())
    }

    fn compile_file(&self, path: &PathBuf) -> Result<(), String> {
        let source_code = std::fs::read_to_string(path)
            .map_err(|e| format!("Failed to read {}: {}", path.display(), e))?;

        match parse(&source_code) {
            Ok(tokens) => {
                for token in tokens {
                    println!("Rule: {:?}, Value: {}", token.as_rule(), token.as_str());
                }
            }
            Err(error) => {
                eprintln!("Parse error: {}", error);
            }
        }

        Ok(())
    }
}
