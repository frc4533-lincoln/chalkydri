#![warn(clippy::all)]

#[macro_use]
extern crate serde;
extern crate toml;

mod config;

use std::{fs::File, io::Read};

pub use config::*;

/// Load configuration values from `chalkydri.toml`
#[no_mangle]
pub extern fn chalkydri_config() -> *const ChalkydriConfig {
    // Open the config file
    let mut f = File::open("chalkydri.toml").expect("couldn't open required 'chalkydri.toml'");

    // Read into a buffer
    let mut buf = String::new();
    f.read_to_string(&mut buf).unwrap();

    // Parse config
    &toml::from_str(buf.as_str()).expect("failed to parse required 'chalkydri.toml'")
}

