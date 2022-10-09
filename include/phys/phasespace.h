#pragma once

#include "phys/vector3.h"

namespace phys {
    class PhaseSpaceVector {
    public:
        PhaseSpaceVector() = default;

        constexpr PhaseSpaceVector(vector3 vel, vector3 pos) : vel(vel), pos(pos) {};

        friend constexpr PhaseSpaceVector operator*(const PhaseSpaceVector &v, double l);

        friend constexpr PhaseSpaceVector operator*(double l, const PhaseSpaceVector &v);

        constexpr auto operator+(const PhaseSpaceVector &other) const {
            return PhaseSpaceVector{vel + other.vel, pos + other.pos};
        }

        constexpr auto Velocity() const {
            return vel;
        }

        constexpr auto Position() const {
            return pos;
        }

    protected:
        vector3 vel = {0, 0, 0};
        vector3 pos = {0, 0, 0};
    };

    constexpr PhaseSpaceVector operator*(const PhaseSpaceVector &v, const double l) {
        return PhaseSpaceVector{v.vel * l, v.pos * l};
    }

    constexpr PhaseSpaceVector operator*(const double l, const PhaseSpaceVector &v) {
        return PhaseSpaceVector{v.vel * l, v.pos * l};
    }

}
