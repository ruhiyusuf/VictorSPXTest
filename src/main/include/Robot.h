// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <ctre/Phoenix.h>
#include <frc/Joystick.h>
#include <frc/PneumaticsControlModule.h>
#include <frc/Solenoid.h>


class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;

  bool reached_max_pressure = false;

  VictorSPX * lcompressor_victor = new VictorSPX(2);
  VictorSPX * rcompressor_victor = new VictorSPX(3);
  frc::Joystick * joystick = new frc::Joystick(0);
  frc::PneumaticsControlModule * pcm = new frc::PneumaticsControlModule(20);

  frc::Solenoid * solenoidValve = new frc::Solenoid(20, frc::PneumaticsModuleType::CTREPCM, 1);



};
