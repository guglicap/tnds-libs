#pragma once

#include "phys/phasespace.h"

namespace phys {
    inline namespace dynamics {
        const auto PendulumEvolution(double l, double g = 9.81) {
            return [l, g](double t, PhaseSpaceVector v) {
                return PhaseSpaceVector{
                        {-g / l * sin(v.Position().x()), 0.0, 0.0},
                        {v.Velocity().x(),               0.0, 0.0}
                };
            };
        };
    }
}
