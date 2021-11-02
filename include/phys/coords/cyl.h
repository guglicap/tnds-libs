#pragma once

#include "phys/vector3d.h"

namespace phys {
    inline namespace coords {
        struct cyl_coords {

            constexpr cyl_coords() : r(0), theta(0), z(0) {};

            constexpr cyl_coords(double r, double theta, double z) : r(r), theta(theta), z(z) {};

            const double r;
            const double theta;
            const double z;
        };

        constexpr auto vec_from_cyl(const cyl_coords v) {
            return vector3d{
                    v.r * cos(v.theta),
                    v.r * sin(v.theta),
                    v.z
            };
        }

        constexpr auto cyl_from_vec(const vector3d v) {
            return cyl_coords{
                    v.len(),
                    v.angle_to(x_axis),
                    v.z()
            };
        }

        std::ostream &operator<<(std::ostream &os, const cyl_coords &v) {
            os << "(" << v.r << ", " << v.theta << ", " << v.z << ")";
            return os;
        };
    }
}
