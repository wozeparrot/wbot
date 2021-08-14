#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <frc/PneumaticsBase.h>
#include <frc/Solenoid.h>

namespace bindings::wfrc::Solenoid {
  inline void generate(wren::ForeignModule* m) {
    auto& cls = m->klass<frc::Solenoid>("Solenoid");

    cls.ctor<frc::PneumaticsBase&, int>();

    cls.func<&frc::Solenoid::Set>("set");
    cls.func<&frc::Solenoid::Get>("get");
    cls.func<&frc::Solenoid::Toggle>("toggle");
  }
} // namespace bindings::wfrc::Solenoid