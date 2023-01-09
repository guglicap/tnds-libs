#pragma once

#include "phys/vectorField.h"
#include "phys/vector3.h"
#include "phys/em/constant.h"
#include "phys/particle.h"

namespace phys {
    inline namespace em {

        constexpr vector electric_field(const vector pos, const particle p) {
            const auto r = pos - p.r();
            return p.q() / (4 * M_PI * epsilon0) / pow(r.len(), 2) * r.normalize();
        }


        auto electricFieldFrom(const particle p) {
            return vectorField{[p](vector pos) { return electric_field(pos, p); }};
        }

    }
}

