#pragma once

#include "math/integral/integral.h"

namespace math {
    inline namespace integral {
        template<typename Func>
        class Midpoint : public Integral {
        public:
            Midpoint(Func f) : Integral(), f(f) {};

            Midpoint(Func f, int nStep) : Integral(), f(f), nStep(nStep) {};

            double Integrate(double a, double b) const override {
                auto res = 0.0;
                auto step = (b - a) / double(nStep);
                for (int i = 0; i < nStep; i++) {
                    res += integrate(a + step * i, a + step * (i + 1));
                }
                return res;
            }

        private:
            const Func f;
            const int nStep = 100;

            constexpr double integrate(double a, double b) const {
                auto xM = (a + b) / 2;
                return f(xM) * (b - a);
            }
        };
    }
}
