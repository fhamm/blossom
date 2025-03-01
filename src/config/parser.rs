use serde::Deserialize;
use std::collections::HashMap;
use std::fs;
use std::path::Path;

use crate::constants::BLOSSOM_CONFIG_FILE;

#[derive(Deserialize, Debug)]
pub struct BlossomConfig {
    pub package: PackageConfig,
    pub project: ProjectConfig,
    #[serde(default)]
    pub dependencies: Option<DependenciesConfig>,
}

#[derive(Deserialize, Debug, Default)]
pub struct DependenciesConfig {
    #[serde(default)]
    pub libraries: HashMap<String, String>,
}

#[derive(Deserialize, Debug)]
pub struct PackageConfig {
    pub name: String,
    pub version: Option<String>,
    pub author: Option<String>,
    pub url: Option<String>,
}

#[derive(Deserialize, Debug)]
pub struct ProjectConfig {
    pub root: Option<String>,
    pub output: Option<String>,
    pub entry: Option<String>,
}

impl BlossomConfig {
    pub fn load(directory: &Path) -> Result<Self, String> {
        let config_path = directory.join(BLOSSOM_CONFIG_FILE);
        if !config_path.exists() {
            return Err(format!(
                "No configuration file found in {}",
                directory.display()
            ));
        }

        let content = fs::read_to_string(&config_path)
            .map_err(|e| format!("Failed to read configuration file: {}", e))?;

        toml::from_str(&content).map_err(|e| format!("Failed to parse configuration file: {}", e))
    }
}
