#pragma once

#define INTEGRAL_MIDPOINT_DEFAULT_NSTEP 1000

#include "math/integral/integral.h"

namespace math {
    inline namespace integral {
        template<typename Func>
        class Midpoint : public Integrator {
        public:
            Midpoint(Func f) : Integrator(), f(f) {};

            Midpoint(Func f, unsigned int N) : Integrator(), f(f), N(N) {};

            Result Integrate(double a, double b) const override {
                auto res = 0.0;
                const auto h = (b - a) / double(N);
                for (unsigned int n = 0; n < N - 1; n++) {
                    const auto xM = (a + n * h + (n + 1) * h) / 2;
                    res += f(xM);
                }
                res *= h;
                return std::pair{res, h * h};
            }

        private:
            const Func f;
            const unsigned int N = INTEGRAL_MIDPOINT_DEFAULT_NSTEP;
        };
    }
}
