#pragma once

#include <iostream>
#include "phys/vector.h"
#include "phys/vectorField.h"
#include "phys/em/constant.h"

namespace phys {
    class particle {

    public:
        constexpr particle(double m, double q) : m_m(m), m_q(q) {};

        constexpr particle(double m, double q, phys::vector r) : m_m(m), m_q(q), m_r(r) {};

        constexpr particle() = default;

        constexpr auto m() const { return m_m; }

        constexpr auto r() const { return m_r; }

        constexpr auto q() const { return m_q; }

        auto electric_field() const {
            return vectorField{[*this](const vector pos) -> vector {
                const auto r = pos - m_r;
                return r.normalize() * m_q / (4 * M_PI * phys::em::epsilon0) / pow(r.len(), 2);
            }};
        }

    protected:
        const double m_m = 0.0;
        const double m_q = 0.0;
        const phys::vector m_r = vector{0, 0, 0};
    };

    std::ostream &operator<<(std::ostream &os, const particle p) {
        os << "m: " << p.m() << " q: " << p.q() << " r: " << p.r();
        return os;
    }
}
