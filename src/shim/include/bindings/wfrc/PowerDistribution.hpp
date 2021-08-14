#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <frc/PowerDistributionPanel.h>

namespace bindings::wfrc::PowerDistribution {
  inline void generate(wren::ForeignModule* m) {
    auto& cls = m->klass<frc::PowerDistributionPanel>("PowerDistribution"); // TODO: rename back to PowerDistribution after 2022 drops

    cls.ctor<int>();

    cls.func<&frc::PowerDistributionPanel::GetVoltage>("getVoltage");
    cls.func<&frc::PowerDistributionPanel::GetTemperature>("getTemperature");
    cls.func<&frc::PowerDistributionPanel::GetCurrent>("getCurrent");
    cls.func<&frc::PowerDistributionPanel::GetTotalCurrent>("getTotalCurrent");
    cls.func<&frc::PowerDistributionPanel::GetTotalPower>("getTotalPower");
    cls.func<&frc::PowerDistributionPanel::GetTotalEnergy>("getTotalEnergy");
    cls.func<&frc::PowerDistributionPanel::ResetTotalEnergy>("resetTotalEnergy");
  }
} // namespace bindings::wfrc::PowerDistribution