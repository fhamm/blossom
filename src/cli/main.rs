mod cli;
mod commands;

use clap::Parser;
use cli::CLI;

fn main() {
    let cli = CLI::parse();
    if let Err(e) = cli.execute() {
        eprintln!("Error: {}", e);
        std::process::exit(1);
    }
}
