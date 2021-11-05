#pragma once

#include "phys/particle.h"
#include "phys/em/constant.h"
#include <iostream>

namespace phys {
    inline namespace particles {
        struct proton : public particle {
            constexpr proton() : particle(1.6726219e-27, e) {};
            constexpr proton(const vector r) : particle{1.6726219e-27, e, r} {};
        };

        std::ostream &operator<<(std::ostream &os, const proton p) {
            os << "Proton: " << particle(p);
            return os;
        }
    }
}
