#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <frc/RobotState.h>

namespace bindings::wfrc::RobotState {
  inline void generate(wren::ForeignModule* m) {
    auto& cls = m->klass<frc::RobotState>("RobotState");

    cls.funcStatic<&frc::RobotState::IsEnabled>("isEnabled");
    cls.funcStatic<&frc::RobotState::IsDisabled>("isDisabled");
    cls.funcStatic<&frc::RobotState::IsEStopped>("isEStopped");
    cls.funcStatic<&frc::RobotState::IsAutonomous>("isAutonomous");
    cls.funcStatic<&frc::RobotState::IsOperatorControl>("isTeleop"); // TODO: rename back to teleop after 2022 drops
    cls.funcStatic<&frc::RobotState::IsTest>("isTest");
  }
} // namespace bindings::wfrc::RobotState