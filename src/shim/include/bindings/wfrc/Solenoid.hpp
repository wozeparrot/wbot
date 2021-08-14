// For some reason the Solenoid class refuses to work properly when bound.
// So this exists to wrap the DoubleSolenoid class to work as a single solenoid.

#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <frc/PneumaticsBase.h>
#include <frc/DoubleSolenoid.h>

namespace bindings::wfrc::Solenoid {
  class Solenoid {
  public:
    Solenoid(std::shared_ptr<frc::PneumaticsBase> module, int channel) : sol(module, channel, channel) {}

    void Set(bool on) {
      on ? sol.Set(frc::DoubleSolenoid::kForward) : sol.Set(frc::DoubleSolenoid::kOff);
    }

    bool Get() {
      return sol.Get() > 0 ? true : false;
    }

    void Toggle() {
      Get() ? Set(false) : Set(true);
    }
  private:
    frc::DoubleSolenoid sol;
  };

  inline void generate(wren::ForeignModule* m) {
    auto& cls = m->klass<Solenoid>("Solenoid");

    cls.ctor<std::shared_ptr<frc::PneumaticsBase>, int>();

    cls.func<&Solenoid::Set>("set");
    cls.func<&Solenoid::Get>("get");
    cls.func<&Solenoid::Toggle>("toggle");
  }
} // namespace bindings::wfrc::Solenoid