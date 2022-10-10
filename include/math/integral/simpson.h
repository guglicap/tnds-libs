#pragma once

#include "math/integral/integral.h"

namespace math {
    inline namespace integral {
        template<typename Func>
        class Simpson : public Integrator {
        public:
            Simpson(Func f) : Integrator(), f(f) {};

            Simpson(Func f, unsigned int N) : Integrator(), f(f), N(N) {};

            std::pair<double, double> Integrate(const double a, const double b) const override {
                const auto h = (b - a) / double(N);
                auto res = 0.0;
                for (int n = 0; n < N; n++) {
                    const auto A = n == 0 ? 1 : (n % 2 == 0 ? 2 : 4);
                    res += A * f(a + n * h);
                }
                res *= h / 3;
                return std::pair{res, h * h * h * h};
            }

        private:
            const Func f;
            const unsigned int N = 10;
        };
    }
}