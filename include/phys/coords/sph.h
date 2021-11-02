#pragma once

#include "phys/vector3d.h"

namespace phys {
    inline namespace coords {
        struct sph_coords {

            constexpr sph_coords() : r(0), theta(0), phi(0) {};

            constexpr sph_coords(double r, double theta, double phi) : r(r), theta(theta), phi(phi) {};

            const double r;
            const double theta;
            const double phi;
        };

        constexpr auto vec_from_sph(const sph_coords v) {
            return vector3d{
                    v.r * sin(v.theta) * cos(v.phi),
                    v.r * sin(v.theta) * sin(v.phi),
                    v.r * cos(v.theta)
            };
        }

        constexpr auto sph_from_vec(const vector3d v) {
            return sph_coords{
                    v.len(),
                    v.angle_to(z_axis),
                    v.angle_to(x_axis)
            };
        }

        std::ostream &operator<<(std::ostream &os, const sph_coords &v) {
            os << "(" << v.r << ", " << v.theta << ", " << v.phi << ")";
            return os;
        };

    }
}
