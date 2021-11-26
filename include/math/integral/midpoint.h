#pragma once

#define INTEGRAL_MIDPOINT_DEFAULT_NSTEP 1000
#include "math/integral/integral.h"

namespace math {
    inline namespace integral {
        template<typename Func>
        class Midpoint : public Integral {
        public:
            Midpoint(Func f) : Integral(), f(f) {};

            Midpoint(Func f, unsigned int nStep) : Integral(), f(f), nStep(nStep) {};

            double Integrate(double a, double b) const override {
                auto res = 0.0;
                const auto step = (b - a) / double(nStep);
                for (unsigned int i = 0; i < nStep; i++) {
                    res += integrate(a + step * i, a + step * (i + 1));
                }
                return res;
            }

        private:
            const Func f;
            const unsigned int nStep = INTEGRAL_MIDPOINT_DEFAULT_NSTEP;

            constexpr double integrate(double a, double b) const {
                const auto xM = (a + b) / 2;
                return f(xM) * (b - a);
            }
        };
    }
}
