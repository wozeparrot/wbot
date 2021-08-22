#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include "bfrc/bDriverStation.hpp"
#include "bfrc/bGenericHID.hpp"
#include "bfrc/bPowerDistribution.hpp"
#include "bfrc/bPneumaticsBase.hpp"
#include "bfrc/bPneumaticsControlModule.hpp"
#include "bfrc/bSolenoid.hpp"
#include "bfrc/bDoubleSolenoid.hpp"
#include "bfrc/bSpeedController.hpp"
#include "bfrc/bSPI.hpp"

namespace bindings::bfrc {
    inline void generate(wren::VM* vm) {
        auto& m = vm->module("ffi/frc");

        bDriverStation::generate(&m);
        bGenericHID::generate(&m);

        bPowerDistribution::generate(&m);

        bPneumaticsBase::generate(&m);
        bPneumaticsControlModule::generate(&m);
        bSolenoid::generate(&m);
        bDoubleSolenoid::generate(&m);

        bSpeedController::generate(&m);

        bSPI::generate(&m);
    }
} // namespace bindings::bfrc