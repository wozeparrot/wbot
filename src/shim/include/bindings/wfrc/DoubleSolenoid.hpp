#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <frc/PneumaticsBase.h>
#include <frc/DoubleSolenoid.h>

namespace bindings::wfrc::DoubleSolenoid {
  inline void Set(frc::DoubleSolenoid& self, int value) {
    self.Set(static_cast<frc::DoubleSolenoid::Value>(value));
  }

  inline int Get(frc::DoubleSolenoid& self) {
    return static_cast<int>(self.Get());
  }

  inline void generate(wren::ForeignModule* m) {
    auto& cls = m->klass<frc::DoubleSolenoid>("DoubleSolenoid");

    cls.ctor<frc::PneumaticsBase&, int, int>();

    cls.funcExt<&Set>("set");
    cls.funcExt<&Get>("get");
    cls.func<&frc::DoubleSolenoid::Toggle>("toggle");
  }
} // namespace bindings::wfrc::DoubleSolenoid