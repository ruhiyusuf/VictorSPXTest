// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <fmt/core.h>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
}

void Robot::AutonomousPeriodic() {
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {

  reached_max_pressure = (pcm->GetPressureSwitch());
  if (joystick->GetRawButton(1) && !reached_max_pressure){
      lcompressor_victor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 1.0);
      rcompressor_victor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 1.0);
  }
  
  if (joystick->GetRawButtonPressed(3) || reached_max_pressure){
      lcompressor_victor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.0);
      rcompressor_victor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.0);
  }

  if (joystick->GetRawButton(2)) {
    solenoidValve->Set(1);
  } else {
    solenoidValve->Set(0);
  }
  

}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
