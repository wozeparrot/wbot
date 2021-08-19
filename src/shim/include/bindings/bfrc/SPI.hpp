#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include <frc/SPI.h>

namespace bindings::bfrc::SPI {
    class Port {
    public:
        int OnboardCS0 = 0;
        int OnboardCS1 = 1;
        int OnboardCS2 = 2;
        int OnboardCS3 = 3;
        int MXP = 4;
    };

    inline void generate(wren::ForeignModule* m) {
        // Bind enums
        auto& ecls0 = m->klass<Port>("SPI_Port_");
        ecls0.ctor<>();
        ecls0.varReadonly<&Port::OnboardCS0>("OnboardCS0");
        ecls0.varReadonly<&Port::OnboardCS1>("OnboardCS1");
        ecls0.varReadonly<&Port::OnboardCS2>("OnboardCS2");
        ecls0.varReadonly<&Port::OnboardCS3>("OnboardCS3");
        ecls0.varReadonly<&Port::MXP>("MXP");
        m->append("var SPI_Port = SPI_Port_.new()");
    }
} // namespace bindings::bfrc::SPI