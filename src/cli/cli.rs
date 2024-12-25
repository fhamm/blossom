use clap::{Parser, Subcommand};
use std::path::PathBuf;

#[derive(Parser)]
#[command(name = "blossom")]
#[command(about = "Blossom Language Compiler")]
pub struct CLI {
    #[command(subcommand)]
    command: Commands,
}

#[derive(Subcommand)]
pub enum Commands {
    Build {
        #[arg(default_value = ".")]
        directory: PathBuf,
    },
    Run {
        #[arg(default_value = ".")]
        directory: PathBuf,
    },
    Test {
        #[arg(default_value = ".")]
        directory: PathBuf,
    },
    Lint {
        #[arg(default_value = ".")]
        directory: PathBuf,
    },
}

impl CLI {
    pub fn execute(self) -> Result<(), String> {
        match self.command {
            Commands::Build { directory } => crate::commands::build::execute(&directory),
            Commands::Run { directory } => crate::commands::run::execute(&directory),
            Commands::Test { directory } => crate::commands::test::execute(&directory),
            Commands::Lint { directory } => crate::commands::lint::execute(&directory),
        }
    }
}
