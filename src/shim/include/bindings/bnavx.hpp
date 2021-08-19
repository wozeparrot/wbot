#pragma once

#include <wrenbind17/wrenbind17.hpp>
namespace wren = wrenbind17;

#include "bnavx/bAHRS.hpp"

namespace bindings::bnavx {
    inline void generate(wren::VM* vm) {
        auto& m = vm->module("ffi/navx");

        bAHRS::generate(&m);
    }
} // namespace bindings::bnavx