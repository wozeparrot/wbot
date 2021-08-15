#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include "bfrc/DriverStation.hpp"
#include "bfrc/GenericHID.hpp"
#include "bfrc/XboxController.hpp"
#include "bfrc/PowerDistribution.hpp"
#include "bfrc/PneumaticsBase.hpp"
#include "bfrc/PneumaticsControlModule.hpp"
#include "bfrc/Solenoid.hpp"
#include "bfrc/DoubleSolenoid.hpp"

namespace bindings::bfrc {
  inline void generate(wren::VM* vm) {
    auto& m = vm->module("ffi/frc");

    DriverStation::generate(&m);
    GenericHID::generate(&m);
    XboxController::generate(&m);

    PowerDistribution::generate(&m);

    PneumaticsBase::generate(&m);
    PneumaticsControlModule::generate(&m);
    Solenoid::generate(&m);
    DoubleSolenoid::generate(&m);
  }
} // namespace bindings::bfrc