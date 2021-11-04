#pragma once

#include "phys/particle.h"
#include <iostream>

namespace phys {
    inline namespace particles {
        class electron : public particle {
        public:
            constexpr electron() : particle(9.10938e-31, -1.60217e-19) {};
        };

        std::ostream &operator<<(std::ostream &os, const electron p) {
            os << "Electron: " << static_cast<particle>(p);
            return os;
        }
    }
}
