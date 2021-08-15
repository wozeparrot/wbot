#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <frc/GenericHID.h>
#include <frc/XboxController.h>

namespace bindings::bfrc::XboxController {
  inline double GetX(frc::XboxController& self, int hand) {
    return self.GetX(static_cast<frc::GenericHID::JoystickHand>(hand));
  }

  inline double GetY(frc::XboxController& self, int hand) {
    return self.GetY(static_cast<frc::GenericHID::JoystickHand>(hand));
  }

  inline double GetTriggerAxis(frc::XboxController& self, int hand) {
    return self.GetTriggerAxis(static_cast<frc::GenericHID::JoystickHand>(hand));
  }

  inline bool GetBumper(frc::XboxController& self, int hand) {
    return self.GetBumper(static_cast<frc::GenericHID::JoystickHand>(hand));
  }

  inline bool GetBumperPressed(frc::XboxController& self, int hand) {
    return self.GetBumperPressed(static_cast<frc::GenericHID::JoystickHand>(hand));
  }

  inline bool GetBumperReleased(frc::XboxController& self, int hand) {
    return self.GetBumperReleased(static_cast<frc::GenericHID::JoystickHand>(hand));
  }

  inline bool GetStickButton(frc::XboxController& self, int hand) {
    return self.GetStickButton(static_cast<frc::GenericHID::JoystickHand>(hand));
  }

  inline bool GetStickButtonPressed(frc::XboxController& self, int hand) {
    return self.GetStickButtonPressed(static_cast<frc::GenericHID::JoystickHand>(hand));
  }

  inline bool GetStickButtonReleased(frc::XboxController& self, int hand) {
    return self.GetStickButtonReleased(static_cast<frc::GenericHID::JoystickHand>(hand));
  }

  inline void SetRumble(frc::XboxController& self, int type, double value) {
    return self.SetRumble(static_cast<frc::GenericHID::RumbleType>(type), value);
  }

  inline void generate(wren::ForeignModule* m) {
    auto& cls = m->klass<frc::XboxController, frc::GenericHID>("XboxController");

    cls.ctor<int>();

    cls.funcExt<&GetX>("getX");
    cls.funcExt<&GetY>("getY");
    cls.funcExt<&GetTriggerAxis>("getTriggerAxis");

    cls.funcExt<&GetBumper>("getBumper");
    cls.funcExt<&GetBumperPressed>("getBumperPressed");
    cls.funcExt<&GetBumperReleased>("getBumperReleased");

    cls.funcExt<&GetStickButton>("getStickButton");
    cls.funcExt<&GetStickButtonPressed>("getStickButtonPressed");
    cls.funcExt<&GetStickButtonReleased>("getStickButtonReleased");

    cls.func<&frc::XboxController::GetAButton>("getAButton");
    cls.func<&frc::XboxController::GetAButtonPressed>("getAButtonPressed");
    cls.func<&frc::XboxController::GetAButtonReleased>("getAButtonReleased");

    cls.func<&frc::XboxController::GetBButton>("getBButton");
    cls.func<&frc::XboxController::GetBButtonPressed>("getBButtonPressed");
    cls.func<&frc::XboxController::GetBButtonReleased>("getBButtonReleased");

    cls.func<&frc::XboxController::GetXButton>("getXButton");
    cls.func<&frc::XboxController::GetXButtonPressed>("getXButtonPressed");
    cls.func<&frc::XboxController::GetXButtonReleased>("getXButtonReleased");

    cls.func<&frc::XboxController::GetYButton>("getYButton");
    cls.func<&frc::XboxController::GetYButtonPressed>("getYButtonPressed");
    cls.func<&frc::XboxController::GetYButtonReleased>("getYButtonReleased");

    cls.func<&frc::XboxController::GetBackButton>("getBackButton");
    cls.func<&frc::XboxController::GetBackButtonPressed>("getBackButtonPressed");
    cls.func<&frc::XboxController::GetBackButtonReleased>("getBackButtonReleased");

    cls.func<&frc::XboxController::GetStartButton>("getStartButton");
    cls.func<&frc::XboxController::GetStartButtonPressed>("getStartButtonPressed");
    cls.func<&frc::XboxController::GetStartButtonReleased>("getStartButtonReleased");

    cls.funcExt<&SetRumble>("setRumble");
  }
} // namespace bindings::bfrc::XboxController