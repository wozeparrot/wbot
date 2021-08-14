#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <frc/GenericHID.h>

namespace bindings::wfrc::GenericHID {
  class RumbleType {
  public:
    int Left = 0;
    int Right = 1;
  };

  class JoystickHand {
  public:
    int Left = 0;
    int Right = 1;
  };

  inline void SetRumble(frc::GenericHID& self, int type, double value) {
    return self.SetRumble(static_cast<frc::GenericHID::RumbleType>(type), value);
  }

  inline void generate(wren::ForeignModule* m) {
    auto& cls = m->klass<frc::GenericHID>("GenericHID");

    cls.func<&frc::GenericHID::GetRawButton>("getRawButton");
    cls.func<&frc::GenericHID::GetRawButtonPressed>("getRawButtonPressed");
    cls.func<&frc::GenericHID::GetRawButtonReleased>("getRawButtonReleased");

    cls.func<&frc::GenericHID::GetRawAxis>("getRawAxis");

    cls.funcExt<&SetRumble>("setRumble");

    // Bind enums
    auto& ecls0 = m->klass<RumbleType>("GenericHID_RumbleType_");
    ecls0.ctor<>();
    ecls0.varReadonly<&RumbleType::Left>("Left");
    ecls0.varReadonly<&RumbleType::Right>("Right");
    m->append("var GenericHID_RumbleType = GenericHID_RumbleType_.new()");

    auto& ecls1 = m->klass<JoystickHand>("GenericHID_JoystickHand_");
    ecls1.ctor<>();
    ecls1.varReadonly<&JoystickHand::Left>("Left");
    ecls1.varReadonly<&JoystickHand::Right>("Right");
    m->append("var GenericHID_JoystickHand = GenericHID_JoystickHand_.new()");
  }
} // namespace bindings::wfrc::GenericHID