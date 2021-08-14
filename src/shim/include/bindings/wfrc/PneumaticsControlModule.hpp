#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <frc/PneumaticsBase.h>
#include <frc/PneumaticsControlModule.h>

namespace bindings::wfrc::PneumaticsControlModule {
  inline void generate(wren::ForeignModule* m) {
    auto& cls = m->klass<frc::PneumaticsControlModule, frc::PneumaticsBase>("PneumaticsControlModule");

    cls.ctor<int>();

    cls.func<&frc::PneumaticsControlModule::SetClosedLoopControl>("setClosedLoopControl");
    cls.func<&frc::PneumaticsControlModule::GetClosedLoopControl>("getClosedLoopControl");
  }
} // namespace bindings::wfrc::PneumaticsControlModule