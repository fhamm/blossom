use crate::constants::BLOSSOM_EXTENSION;
use blossom_config::BlossomConfig;
use std::fs;
use std::path::{Path, PathBuf};

pub struct SourceFinder<'a> {
    config: &'a BlossomConfig,
    root_path: &'a PathBuf,
}

impl<'a> SourceFinder<'a> {
    pub fn new(config: &'a BlossomConfig, root_path: &'a PathBuf) -> Self {
        Self { config, root_path }
    }

    pub fn find_source_files(&self) -> Result<Vec<PathBuf>, String> {
        let root_path = self.config.project.root.as_deref().unwrap_or(".");
        let root = Path::new(root_path);

        if !root.exists() {
            return Err(format!("Root directory '{}' does not exist", root_path));
        }

        let mut files = Vec::new();
        self.visit_dirs(&mut files)?;
        Ok(files)
    }

    fn visit_dirs(&self, files: &mut Vec<PathBuf>) -> Result<(), String> {
        let project_root = self.config.project.root.as_deref().unwrap_or(".");
        let root_dir = self.root_path.join(project_root);

        for entry in fs::read_dir(&root_dir).map_err(|e| e.to_string())? {
            let path = entry.map_err(|e| e.to_string())?.path();
            if path.is_dir() {
                self.visit_dirs(files)?;
            } else if let Some(extension) = path.extension() {
                if extension == BLOSSOM_EXTENSION {
                    files.push(path);
                }
            }
        }
        Ok(())
    }
}
