#pragma once

#include "phys/vector.h"

namespace phys {
    inline namespace coords {
        struct cyl {

            constexpr cyl() : r(0), theta(0), z(0) {};

            constexpr cyl(double r, double theta, double z) : r(r), theta(theta), z(z) {};

            double r;
            double theta;
            double z;
        };

        constexpr auto vecFromCyl(const cyl v) {
            return vector{
                    v.r * cos(v.theta),
                    v.r * sin(v.theta),
                    v.z
            };
        }

        constexpr auto cylFromVec(const vector v) {
            return cyl{
                    v.len(),
                    v.angle_to(x_axis),
                    v.z()
            };
        }

        std::ostream &operator<<(std::ostream &os, const cyl &v) {
            os << "(" << v.r << ", " << v.theta << " rad, " << v.z << ")";
            return os;
        };
    }
}
