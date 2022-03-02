#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <frc/SpeedController.h>

namespace bindings::bfrc::bSpeedController {
    inline void generate(wren::ForeignModule* m) {
        auto& cls = m->klass<frc::SpeedController>("SpeedController");
    }
} // namespace bindings::bfrc::bSpeedController
