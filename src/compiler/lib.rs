use crate::finder::SourceFinder;
use crate::lexer::Lexer;
use blossom_config::BlossomConfig;
use std::path::PathBuf;

mod common;
mod constants;
mod finder;
mod lexer;
mod parser;
mod token;

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
        let content = std::fs::read_to_string(path)
            .map_err(|e| format!("Failed to read {}: {}", path.display(), e))?;

        let mut lexer = Lexer::new(&content);
        let tokens = lexer.tokenize();

        println!("{:#?}", tokens);

        // TODO: Add parser and code generation
        Ok(())
    }
}
