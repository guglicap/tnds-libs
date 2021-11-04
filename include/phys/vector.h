#pragma once

#include <cmath>
#include <iostream>

using std::sqrt, std::sin, std::cos, std::acos;

namespace phys {

    // vector represents a position in 3d space, expressed with respect to a cartesian coordinate system.
    class vector {
    public:
        constexpr vector() = default;

        constexpr vector(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {};

        constexpr vector

        add(const vector v) const {
            return vector{
                    m_x + v.m_x,
                    m_y + v.m_y,
                    m_z + v.m_z
            };
        };

        constexpr vector

        mul(const double v) const {
            return vector{
                    m_x * v,
                    m_y * v,
                    m_z * v,
            };
        };

        constexpr vector

        sub(const vector v) const { return add(v.mul(-1)); };

        constexpr vector

        div(const double v) const { return mul(1 / v); };

        constexpr auto dot(const vector v) const { return m_x * v.m_x + m_y * v.m_y + m_z * v.m_z; }

        constexpr auto len() const { return sqrt(this->dot(*this)); }

        constexpr auto angle_to(const vector v) const {
            return acos(this->dot(v) / (v.len() * this->len()));
        }

        constexpr vector normalize() const { return this->div(this->len()); }

        constexpr auto x() const { return m_x; };

        constexpr auto y() const { return m_y; };

        constexpr auto z() const { return m_z; };

    private:
        const double m_x = 0.0, m_y = 0.0, m_z = 0.0;
    };

    constexpr auto x_axis = vector{1, 0, 0};
    constexpr auto y_axis = vector{0, 1, 0};
    constexpr auto z_axis = vector{0, 0, 1};

    std::ostream &operator<<(std::ostream &os, const vector &v) {
        os << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
        return os;
    };

    constexpr vector operator+(const vector lhs, const vector rhs) {
        return lhs.add(rhs);
    }

    constexpr vector operator-(const vector lhs, const vector rhs) {
        return lhs.sub(rhs);
    }

    constexpr vector operator*(const double l, const vector v) {
        return v.mul(l);
    }

    constexpr vector operator*(const vector v, const double l) {
        return l * v;
    }

    constexpr double operator*(const vector lhs, const vector rhs) {
        return lhs.dot(rhs);
    }

    constexpr vector operator/(const vector lhs, const double rhs) {
        return lhs.div(rhs);
    }
}
