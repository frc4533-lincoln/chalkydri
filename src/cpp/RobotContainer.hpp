// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/button/CommandXboxController.h>

#include "__generated.hpp"
#include "subsystems/ExampleSubsystem.hpp"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();

 private:
  // Driver controller port
  frc2::CommandXboxController m_driveCtrl { 0 };
  //Operator controller port
  frc2::CommandXboxController m_operCtrl { 1 };

  // The robot's subsystems are defined here...
  ExampleSubsystem m_subsystem;

  const ChalkydriConfig *cfg;

  void ConfigureBindings();
};
