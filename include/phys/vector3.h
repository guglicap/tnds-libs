#pragma once

#include <cmath>
#include <iostream>

using std::sqrt, std::sin, std::cos, std::acos;

namespace phys {


    // vector3 represents a position in 3d space, expressed with respect to a cartesian coordinate system.
    class vector3 {
    public:
        constexpr vector3() = default;

        constexpr vector3(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {};

        constexpr vector3

        add(const vector3 v) const {
            return vector3{
                    m_x + v.m_x,
                    m_y + v.m_y,
                    m_z + v.m_z
            };
        };

        constexpr vector3

        mul(const double v) const {
            return vector3{
                    m_x * v,
                    m_y * v,
                    m_z * v,
            };
        };

        constexpr vector3

        sub(const vector3 v) const { return add(v.mul(-1)); };

        constexpr vector3

        div(const double v) const { return mul(1 / v); };

        constexpr auto dot(const vector3 v) const { return m_x * v.m_x + m_y * v.m_y + m_z * v.m_z; }

        constexpr auto len() const { return sqrt(this->dot(*this)); }

        constexpr auto angle_to(const vector3 v) const {
            return acos(this->dot(v) / (v.len() * this->len()));
        }

        constexpr vector3 normalize() const { return this->div(this->len()); }

        constexpr auto x() const { return m_x; };

        constexpr auto y() const { return m_y; };

        constexpr auto z() const { return m_z; };

    private:
        double m_x = 0.0, m_y = 0.0, m_z = 0.0;
    };

    typedef vector3 vector; // backwards compatibility

    constexpr auto x_axis = vector3{1, 0, 0};
    constexpr auto y_axis = vector3{0, 1, 0};
    constexpr auto z_axis = vector3{0, 0, 1};

    std::ostream &operator<<(std::ostream &os, const vector3 &v) {
        os << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
        return os;
    };

    constexpr vector3 operator+(const vector3 lhs, const vector3 rhs) {
        return lhs.add(rhs);
    }

    constexpr vector3 operator-(const vector3 lhs, const vector3 rhs) {
        return lhs.sub(rhs);
    }

    constexpr vector3 operator*(const double l, const vector3 v) {
        return v.mul(l);
    }

    constexpr vector3 operator*(const vector3 v, const double l) {
        return l * v;
    }

    constexpr double operator*(const vector3 lhs, const vector3 rhs) {
        return lhs.dot(rhs);
    }

    constexpr vector3 operator/(const vector3 lhs, const double rhs) {
        return lhs.div(rhs);
    }
}

