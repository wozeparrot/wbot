#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <frc/PneumaticsBase.h>
#include <frc/DoubleSolenoid.h>

namespace bindings::bfrc::bDoubleSolenoid {
    class Value {
    public:
        int Off = 0;
        int Forward = 1;
        int Reverse = 2;
    };

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

        // Bind enums
        auto& ecls0 = m->klass<Value>("DoubleSolenoid_Value_");
        ecls0.ctor<>();
        ecls0.varReadonly<&Value::Off>("Off");
        ecls0.varReadonly<&Value::Forward>("Forward");
        ecls0.varReadonly<&Value::Reverse>("Reverse");
        m->append("var DoubleSolenoid_Value = DoubleSolenoid_Value_.new()");
    }
} // namespace bindings::bfrc::bDoubleSolenoid