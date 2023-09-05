//! Robot config structures
//!
//! The robot's configuration values are stored in a TOML config file for easy
//! tweaking.
//!
//! ## Motor naming scheme
//!
//! ```text
//! f l d
//! | | \_ drive
//! | \_________ left
//! \_________________ front
//! ```
//!
//!  - **`f` / `b`**: front / back
//!  - **`l` / `r`**: left / right
//!  - **`d` / `s`**: drive / steer

#[repr(C)]
#[derive(Deserialize, Clone, Copy)]
pub struct ChalkydriConfig {
  pub looper_time: f32,
  pub pcm_id: u8,

  /// Left-to-right distance between wheel centers in meters
  pub track_width: f32,
  /// Front-to-back distance between wheel centers in meters
  pub wheel_base: f32,

  /// Wheel diameter in meters
  pub wheel_diameter: f32,

  pub drive_gear_ratio: f32,
  pub steer_gear_ratio: f32,

    pub drive_ctrl: i32,
    pub oper_ctrl: i32,

  pub swerve: ChalkydriSwerveDriveConfig,
}

#[repr(C)]
#[derive(Deserialize, Clone, Copy)]
pub struct ChalkydriSwerveDriveConfig {
    /// Front Left
    pub fl: ChalkydriSwerveModuleConfig,
    /// Front Right
    pub fr: ChalkydriSwerveModuleConfig,
    /// Back Left
    pub bl: ChalkydriSwerveModuleConfig,
    /// Back Right
    pub br: ChalkydriSwerveModuleConfig,
}

#[repr(C)]
#[derive(Deserialize, Clone, Copy)]
pub struct ChalkydriSwerveModuleConfig {
    pub drive: ChalkydriSwerveModuleDriveMotorConfig,
    pub steer: ChalkydriSwerveModuleSteerMotorConfig,
}

#[repr(C)]
#[derive(Deserialize, Clone, Copy)]
pub struct ChalkydriSwerveModuleDriveMotorConfig {
    pub motor_id: isize,
    /// Encoder reversed?
    pub enc_rev: bool,
}

#[repr(C)]
#[derive(Deserialize, Clone, Copy)]
pub struct ChalkydriSwerveModuleSteerMotorConfig {
    pub motor_id: isize,
    /// Encoder reversed?
    pub enc_rev: bool,
    
    /// Absolute encoder ID
    pub abs_enc_id: isize,
    /// Absolute encoder offset
    pub abs_enc_offset: f64,
    /// Absolute encoder reversed?
    pub abs_enc_rev: bool,
}

/// Motor IDs
/*
#[repr(C)]
#[derive(Deserialize, Clone, Copy)]
pub struct ChalkydriMotorConfig {
  /// `Front Left` *Drive* Motor ID
  pub fld: u8,
  /// `Front Right` *Drive* Motor ID
  pub frd: u8,
  /// `Back Left` *Drive* Motor ID
  pub bld: u8,
  /// `Back Right` *Drive* Motor ID
  pub brd: u8,

  /// `Front Left` *Steer* Motor ID
  pub fls: u8,
  /// `Front Right` *Steer* Motor ID
  pub frs: u8,
  /// `Back Left` *Steer* Motor ID
  pub bls: u8,
  /// `Back Right` *Steer* Motor ID
  pub brs: u8,
}
*/

#[repr(C)]
#[derive(Deserialize, Clone, Copy)]
pub struct ChalkydriEncoderConfig {
  /// `Front Left` *Drive* Encoder Reversed
  pub fld_rev: bool,
  /// `Front Right` *Drive* Encoder Reversed
  pub frd_rev: bool,
  /// `Back Left` *Drive* Encoder Reversed
  pub bld_rev: bool,
  /// `Back Right` *Drive* Encoder Reversed
  pub brd_rev: bool,

    /*
  /// `Front Left` *Steer* Encoder Reversed
  pub fls_rev: bool,
  /// `Front Right` *Steer* Encoder Reversed
  pub frs_rev: bool,
  /// `Back Left` *Steer* Encoder Reversed
  pub bls_rev: bool,
  /// `Back Right` *Steer* Encoder Reversed
  pub brs_rev: bool,
    */
}

/// Absolute encoder settings
///
/// ## `rev`
///
/// Whether or not the absolute encoder is reversed
///
/// ## `offset`
///
/// Offsets for swerve modules
///
/// Should be equal to absolute encoder reading when wheel is facing straight
/// forward
#[repr(C)]
#[derive(Deserialize, Clone, Copy)]
pub struct ChalkydriAbsoluteEncoderConfig {
    /*
  /// `Front Left` *Steer* Absoulte Encoder ID
  pub fls: u8,
  /// `Front Right` *Steer* Absolute Encoder ID
  pub frs: u8,
  /// `Back Left` *Steer* Absolute Encoder ID
  pub bls: u8,
  /// `Back Right` *Steer* Absolute Encoder ID
  pub brs: u8,
    */

  /// `Front Left` *Steer* Absolute Encoder Reversed
  pub fls_rev: bool,
  /// `Front Right` *Steer* Absolute Encoder Reversed
  pub frs_rev: bool,
  /// `Back Left` *Steer* Absolute Encoder Reversed
  pub bls_rev: bool,
  /// `Back Right` *Steer* Absolute Encoder Reversed
  pub brs_rev: bool,

  /// `Front Left` *Steer* Absolute Encoder Offset
  pub fls_offset: f32,
  /// `Front Right` *Steer* Absolute Encoder Offset
  pub frs_offset: f32,
  /// `Back Left` *Steer* Absolute Encoder Offset
  pub bls_offset: f32,
  /// `Back Right` *Steer* Absolute Encoder Offset
  pub brs_offset: f32,
}
