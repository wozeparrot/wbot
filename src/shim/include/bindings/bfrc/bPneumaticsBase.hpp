#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <frc/PneumaticsBase.h>

namespace bindings::bfrc::bPneumaticsBase {
    class ModuleType {
    public:
        int CTRE = 0;
        int Rev = 1;
    };

    inline void generate(wren::ForeignModule* m) {
        auto& cls = m->klass<frc::PneumaticsBase>("PneumaticsBase");

        // Bind enums
        auto& ecls0 = m->klass<ModuleType>("Pneumatics_ModuleType_");
        ecls0.ctor<>();
        ecls0.varReadonly<&ModuleType::CTRE>("CTRE");
        ecls0.varReadonly<&ModuleType::Rev>("Rev");
        m->append("var Pneumatics_ModuleType = Pneumatics_ModuleType_.new()");
    }
} // namespace bindings::bfrc::bPneumaticsBase
