#pragma once

#include "phys/particle.h"
#include <iostream>

namespace phys {
    inline namespace particles {
        struct electron : public particle {
            constexpr electron() : particle{9.10938e-31, -e} {};
            constexpr electron(const vector r) : particle{9.10938e-31, -e, r} {};
        };

        std::ostream &operator<<(std::ostream &os, const electron p) {
            os << "Electron: " << particle(p);
            return os;
        }
    }
}
