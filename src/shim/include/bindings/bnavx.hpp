#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include "bnavx/AHRS.hpp"

namespace bindings::bnavx {
    inline void generate(wren::VM* vm) {
        auto& m = vm->module("ffi/navx");

        AHRS::generate(&m);
    }
} // namespace bindings::bnavx