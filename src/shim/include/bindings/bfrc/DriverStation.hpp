#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <units/time.h>
#include <frc/DriverStation.h>

namespace bindings::bfrc::DriverStation {
  class Alliance {
  public:
    int Red = 0;
    int Blue = 1;
    int Invalid = 2;
  };

  class MatchType {
  public:
    int None = 0;
    int Practice = 1;
    int Qualification = 2;
    int Elimination = 3;
  };

  static int GetMatchType() {
    return static_cast<int>(frc::DriverStation::GetMatchType());
  }

  static int GetAlliance() {
    return static_cast<int>(frc::DriverStation::GetAlliance());
  }

  static void WaitForData(double ms) {
    frc::DriverStation::WaitForData(static_cast<units::second_t>(ms));
  }

  inline void generate(wren::ForeignModule* m) {
    auto& cls = m->klass<frc::DriverStation>("DriverStation");

    cls.funcStatic<&frc::DriverStation::GetStickButton>("getStickButton");
    cls.funcStatic<&frc::DriverStation::GetStickButtonPressed>("getStickButtonPressed");
    cls.funcStatic<&frc::DriverStation::GetStickButtonReleased>("getStickButtonReleased");
    cls.funcStatic<&frc::DriverStation::GetStickAxis>("getStickAxis");
    cls.funcStatic<&frc::DriverStation::GetStickPOV>("getStickPOV");
    cls.funcStatic<&frc::DriverStation::GetStickButtons>("getStickButtons");
    cls.funcStatic<&frc::DriverStation::GetStickAxisCount>("getStickAxisCount");
    cls.funcStatic<&frc::DriverStation::GetStickPOVCount>("getStickPOVCount");
    cls.funcStatic<&frc::DriverStation::GetStickButtonCount>("getStickButtonCount");
    cls.funcStatic<&frc::DriverStation::GetJoystickType>("getJoystickType");
    cls.funcStatic<&frc::DriverStation::GetJoystickName>("getJoystickName");
    cls.funcStatic<&frc::DriverStation::GetJoystickAxisType>("getJoystickAxisType");
    cls.funcStatic<&frc::DriverStation::IsJoystickConnected>("isJoystickConnected");

    cls.funcStatic<&frc::DriverStation::IsEnabled>("isEnabled");
    cls.funcStatic<&frc::DriverStation::IsDisabled>("isDisabled");
    cls.funcStatic<&frc::DriverStation::IsEStopped>("isEStopped");
    cls.funcStatic<&frc::DriverStation::IsAutonomous>("isAutonomous");
    cls.funcStatic<&frc::DriverStation::IsAutonomousEnabled>("isAutonomousEnabled");
    cls.funcStatic<&frc::DriverStation::IsOperatorControl>("isTeleop"); // TODO: rename back to teleop after 2022 drops
    cls.funcStatic<&frc::DriverStation::IsOperatorControlEnabled>("isTeleopEnabled"); // TODO: rename back to teleop after 2022 drops
    cls.funcStatic<&frc::DriverStation::IsTest>("isTest");
    cls.funcStatic<&frc::DriverStation::IsDSAttached>("isDSAttached");
    cls.funcStatic<&frc::DriverStation::IsNewControlData>("isNewControlData");
    cls.funcStatic<&frc::DriverStation::IsFMSAttached>("isFMSAttached");

    cls.funcStatic<&frc::DriverStation::GetGameSpecificMessage>("getGameSpecificMessage");
    cls.funcStatic<&frc::DriverStation::GetEventName>("getEventName");
    cls.funcStaticExt<&GetMatchType>("getMatchType");
    cls.funcStatic<&frc::DriverStation::GetMatchNumber>("getMatchNumber");
    cls.funcStatic<&frc::DriverStation::GetReplayNumber>("getReplayNumber");
    cls.funcStaticExt<&GetAlliance>("getAlliance");
    cls.funcStatic<&frc::DriverStation::GetLocation>("getLocation");

    cls.funcStaticExt<&WaitForData>("waitForData");
    cls.funcStatic<&frc::DriverStation::WakeupWaitForData>("wakeupWaitForData");

    cls.funcStatic<&frc::DriverStation::GetMatchTime>("getMatchTime");
    cls.funcStatic<&frc::DriverStation::GetBatteryVoltage>("getBatteryVoltage");

    // Bind enums
    auto& ecls0 = m->klass<Alliance>("DriverStation_Alliance_");
    ecls0.ctor<>();
    ecls0.varReadonly<&Alliance::Red>("Red");
    ecls0.varReadonly<&Alliance::Blue>("Blue");
    ecls0.varReadonly<&Alliance::Invalid>("Invalid");
    m->append("var DriverStation_Alliance = DriverStation_Alliance_.new()");

    auto& ecls1 = m->klass<MatchType>("DriverStation_MatchType_");
    ecls1.ctor<>();
    ecls1.varReadonly<&MatchType::None>("None");
    ecls1.varReadonly<&MatchType::Practice>("Practice");
    ecls1.varReadonly<&MatchType::Qualification>("Qualification");
    ecls1.varReadonly<&MatchType::Elimination>("Elimination");
    m->append("var DriverStation_MatchType = DriverStation_MatchType_.new()");
  }
} // namespace bindings::bfrc::DriverStation