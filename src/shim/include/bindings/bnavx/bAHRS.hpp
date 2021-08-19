#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <frc/SPI.h>
#include <AHRS.h>

namespace bindings::bnavx::bAHRS {
    inline AHRS* ctor(int spi_port_id, uint8_t update_rate_hz) {
        return new AHRS(static_cast<frc::SPI::Port>(spi_port_id), update_rate_hz);
    }

    inline void generate(wren::ForeignModule* m) {
        auto& cls = m->klass<AHRS>("AHRS");

        cls.funcStaticExt<&ctor>("new");
    }
} // namespace bindings::bnavx::bAHRS