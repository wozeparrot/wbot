#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <frc/PowerDistribution.h>

namespace bindings::bfrc::bPowerDistribution {
    class ModuleType {
    public:
        int Auto = 0;
        int CTRE = 1;
        int Rev = 2;
    };

    inline frc::PowerDistribution* ctor(int module, int moduleType) {
        return new frc::PowerDistribution(module, static_cast<frc::PowerDistribution::ModuleType>(moduleType));
    }

    inline void generate(wren::ForeignModule* m) {
        auto& cls = m->klass<frc::PowerDistribution>("PowerDistribution");

        cls.funcStaticExt<&ctor>("new");

        cls.func<&frc::PowerDistribution::GetVoltage>("getVoltage");
        cls.func<&frc::PowerDistribution::GetTemperature>("getTemperature");
        cls.func<&frc::PowerDistribution::GetCurrent>("getCurrent");
        cls.func<&frc::PowerDistribution::GetTotalCurrent>("getTotalCurrent");
        cls.func<&frc::PowerDistribution::GetTotalPower>("getTotalPower");
        cls.func<&frc::PowerDistribution::GetTotalEnergy>("getTotalEnergy");
        cls.func<&frc::PowerDistribution::ResetTotalEnergy>("resetTotalEnergy");

        // Bind enums
        auto& ecls0 = m->klass<ModuleType>("PowerDistribution_ModuleType_");
        ecls0.ctor<>();
        ecls0.varReadonly<&ModuleType::Auto>("Auto");
        ecls0.varReadonly<&ModuleType::CTRE>("CTRE");
        ecls0.varReadonly<&ModuleType::Rev>("Rev");
        m->append("var PowerDistribution_ModuleType = PowerDistribution_ModuleType_.new()");
    }
} // namespace bindings::bfrc::bPowerDistribution