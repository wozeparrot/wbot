#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include "wfrc/DriverStation.hpp"
#include "wfrc/GenericHID.hpp"
#include "wfrc/XboxController.hpp"
#include "wfrc/PowerDistribution.hpp"
#include "wfrc/PneumaticsBase.hpp"
#include "wfrc/PneumaticsControlModule.hpp"
#include "wfrc/Solenoid.hpp"
#include "wfrc/DoubleSolenoid.hpp"

namespace bindings::wfrc {
  inline void generate(wren::VM* vm) {
    auto& m = vm->module("wpilib/frc");

    DriverStation::generate(&m);
    GenericHID::generate(&m);
    XboxController::generate(&m);

    PowerDistribution::generate(&m);

    PneumaticsBase::generate(&m);
    PneumaticsControlModule::generate(&m);
    Solenoid::generate(&m);
    DoubleSolenoid::generate(&m);
    
    std::cout << m.str() << std::endl;
  }
} // namespace bindings::wfrc