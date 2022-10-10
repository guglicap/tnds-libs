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

        auto HarmOscForcedEvolution(double w2, double alpha, double wForce) {
            return [w2, alpha, wForce](double t, PhaseSpaceVector v) {
                return PhaseSpaceVector{
                        // TODO: force term is an ugly hack for now
                        -w2 * v.Position() - alpha * v.Velocity() + sin(wForce * t) * phys::vector3{1, 0, 0},
                        v.Velocity(),
                };
            };
        }
    }
}
