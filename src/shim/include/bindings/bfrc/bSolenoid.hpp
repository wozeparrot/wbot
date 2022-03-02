// For some reason the Solenoid class refuses to work properly when bound.
// So this exists to wrap the DoubleSolenoid class to work as a single solenoid.

#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <frc/Solenoid.h>
#include <frc/PneumaticsModuleType.h>

namespace bindings::bfrc::bSolenoid {
    inline frc::Solenoid* ctor(int module, int moduleType, int channel) {
        return new frc::Solenoid(module, static_cast<frc::PneumaticsModuleType>(moduleType), channel);
    }

    inline void generate(wren::ForeignModule* m) {
        auto& cls = m->klass<frc::Solenoid>("Solenoid");

        cls.funcStaticExt<&ctor>("new");

        cls.func<&frc::Solenoid::Set>("set");
        cls.func<&frc::Solenoid::Get>("get");
        cls.func<&frc::Solenoid::Toggle>("toggle");
    }
} // namespace bindings::bfrc::bSolenoid
