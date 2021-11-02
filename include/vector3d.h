#pragma once

#include <cmath>
#include <iostream>

using std::sqrt, std::sin, std::cos, std::acos;

namespace phys {

    struct cyl_coords {

        constexpr cyl_coords() : r(0), theta(0), z(0) {};

        constexpr cyl_coords(double r, double theta, double z) : r(r), theta(theta), z(z) {};

        const double r;
        const double theta;
        const double z;
    };

    struct sph_coords {

        constexpr sph_coords() : r(0), theta(0), phi(0) {};

        constexpr sph_coords(double r, double theta, double phi) : r(r), theta(theta), phi(phi) {};

        const double r;
        const double theta;
        const double phi;
    };

    // vector3d represents a position in 3d space, expressed with respect to a cartesian coordinate system.
    class vector3d {
    public:
        constexpr vector3d(): m_x(0), m_y(0), m_z(0) {};

        constexpr vector3d(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {};

        constexpr vector3d

        add(const vector3d v) const {
            return vector3d{
                    m_x + v.m_x,
                    m_y + v.m_y,
                    m_z + v.m_z
            };
        };

        constexpr vector3d

        mul(const double v) const {
            return vector3d{
                    m_x * v,
                    m_y * v,
                    m_z * v,
            };
        };

        constexpr vector3d

        sub(const vector3d v) const { return add(mul(-1)); };

        constexpr vector3d

        div(const double v) const { return mul(1 / v); };

        constexpr auto dot(const vector3d v) const { return m_x * v.m_x + m_y * v.m_y + m_z * v.m_z; }

        constexpr auto len() const { return sqrt(this->dot(*this)); }

        constexpr auto angle_to(const vector3d v) const {
            return acos(this->dot(v) / (v.len() * this->len()));
        }

        constexpr vector3d normalize() const { return *this / this->len(); }

        constexpr auto x() const { return m_x; };

        constexpr auto y() const { return m_y; };

        constexpr auto z() const { return m_z; };

    private:
        const double m_x, m_y, m_z;
    };

    constexpr auto x_axis = vector3d{1, 0, 0};
    constexpr auto y_axis = vector3d{0, 1, 0};
    constexpr auto z_axis = vector3d{0, 0, 1};

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
                v.angle_to(x_axis),
                v.angle_to(z_axis)
        };
    }

    std::ostream &operator<<(std::ostream &os, const vector3d &v) {
        os << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
        return os;
    };

    std::ostream &operator<<(std::ostream &os, const cyl_coords &v) {
        os << "(" << v.r << ", " << v.theta << ", " << v.z << ")";
        return os;
    };

    std::ostream &operator<<(std::ostream &os, const sph_coords &v) {
        os << "(" << v.r << ", " << v.theta << ", " << v.phi << ")";
        return os;
    };

    constexpr vector3d operator+(const vector3d lhs, const vector3d rhs) {
        return lhs.add(rhs);
    }

    constexpr vector3d operator-(const vector3d lhs, const vector3d rhs) {
        return lhs.sub(rhs);
    }

    constexpr vector3d operator*(const double l, const vector3d v) {
        return v.mul(l);
    }

    constexpr vector3d operator*(const vector3d v, const double l) {
        return l*v;
    }

    constexpr double operator*(const vector3d lhs, const vector3d rhs) {
        return lhs.dot(rhs);
    }

    constexpr vector3d operator/(const vector3d lhs, const double rhs) {
        return lhs.div(rhs);
    }
}
