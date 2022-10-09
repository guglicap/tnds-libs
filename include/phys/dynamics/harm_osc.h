#pragma once

#include "phys/phasespace.h"

namespace phys {
    inline namespace dynamics {
        const auto HarmOscEvolution = [](double t, PhaseSpaceVector v) {
            return PhaseSpaceVector{
                    v.Position() * -0.6,
                    v.Velocity(),
            };
        };
    }
}
