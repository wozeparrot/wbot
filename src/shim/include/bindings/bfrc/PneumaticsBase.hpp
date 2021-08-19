#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <frc/PneumaticsBase.h>

namespace bindings::bfrc::PneumaticsBase {
    inline void generate(wren::ForeignModule* m) {
        auto& cls = m->klass<frc::PneumaticsBase>("PneumaticsBase");
    }
} // namespace bindings::bfrc::PneumaticsBase