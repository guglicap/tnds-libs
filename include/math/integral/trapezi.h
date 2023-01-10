#pragma once
#include "integral.h"
#include <cmath>

namespace math
{
    inline namespace integral
    {
        template <typename Func>
        class Trapezi : public Integrator
        {
        public:
            Trapezi(Func f) : f{f} {};
            Trapezi(Func f, double reqPrec) : f{f},
                                              reqPrec{reqPrec} {};

            Result Integrate(double a, double b) override
            {
                if (N == 1)
                {
                    m_I = 0.5 * (f(b) + f(a)) * (b - a);
                }
                double prec;
                do
                {
                    N *= 2;
                    auto h = (b - a) / double(N);
                    auto next_I = 0.0;
                    for (int i{0}; i < N; i++)
                    {
                        auto c = a + i * h;
                        auto d = a + (i + 1) * h;
                        next_I += 0.5 * (f(c) + f(d)) * (d - c);
                    }
                    prec = next_I - m_I;
                    m_I = next_I;
                } while (prec >= reqPrec);
                return {m_I, prec};
            };

        private:
            unsigned int N = 1;
            double m_I = NAN;
            double reqPrec = 0.0;
            const Func f;
        };
    }
}