#pragma once

#include "phys/vector.h"

namespace phys {
    inline namespace coords {
        struct sph {

            constexpr sph() : r(0), theta(0), phi(0) {};

            constexpr sph(double r, double theta, double phi) : r(r), theta(theta), phi(phi) {};

            double r;
            double theta;
            double phi;
        };

        constexpr auto vecFromSph(const sph v) {
            return vector{
                    v.r * sin(v.theta) * cos(v.phi),
                    v.r * sin(v.theta) * sin(v.phi),
                    v.r * cos(v.theta)
            };
        }

        constexpr auto sphFromVec(const vector v) {
            return sph{
                    v.len(),
                    v.angle_to(z_axis),
                    v.angle_to(x_axis)
            };
        }

        std::ostream &operator<<(std::ostream &os, const sph &v) {
            os << "(" << v.r << ", " << v.theta << " rad, " << v.phi << " rad)";
            return os;
        };

    }
}
