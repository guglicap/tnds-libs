#pragma once

#define INTEGRAL_MIDPOINT_DEFAULT_NSTEP 2

#include "math/integral/integral.h"

namespace math {
    inline namespace integral {
        template<typename Func>
        class Midpoint : public Integrator {
        public:
            Midpoint(Func f) : Integrator(), f{f} {};

            Midpoint(Func f, unsigned int N) : Integrator(), f{f}, N{N} {};

            Midpoint(Func f, double reqPrec) : Integrator(), f{f}, reqPrec{reqPrec} {};

            Result Integrate(double a, double b) override {
                for (;;) {
                    auto res = integrate(a, b);
                    if (std::isnan(reqPrec)) {
                        return res;
                    }
                    auto res2 = integrate(a, b, N*2);
                    auto prec = 4/3 * std::abs(res2.first - res.first) / res.first;
                    if (prec <= reqPrec) {
                        return {res.first, prec};
                    }
                    N++;
                }
            }

            unsigned int GetN() {
                return N;
            }

        private:
            const Func f;
            const double reqPrec = NAN;
            unsigned int N = INTEGRAL_MIDPOINT_DEFAULT_NSTEP;

            Result integrate(double a, double b) {
                auto res = 0.0;
                const auto h = (b - a) / double(N);
                for (unsigned int n = 0; n < N; n++) {
                    const auto xM = a + (n + 0.5) * h;
                    res += f(xM);
                }
                res *= h;
                return {res, h * h};
            }

            Result integrate(double a, double b, unsigned int N) {
                auto res = 0.0;
                const auto h = (b - a) / double(N);
                for (unsigned int n = 0; n < N; n++) {
                    const auto xM = a + (n + 0.5) * h;
                    res += f(xM);
                }
                res *= h;
                return {res, h * h};
            }
        };
    }
}
