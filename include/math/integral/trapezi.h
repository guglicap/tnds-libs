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
            Trapezi(Func f, double reqPrec) : f{f},
                                              reqPrec{reqPrec} {};

            Result Integrate(double a, double b) override
            {
                m_I = integrate(a, b, N);
                for (;;)
                {
                    auto I2 = integrate(a, b, N * 2);
                    auto error = 4.0 / 3.0 * std::abs(m_I - I2);
                    if (error <= reqPrec)
                    {
                        return {m_I, error};
                    }
                    m_I = I2;
                    N *= 2;
                }
            };

        private:
            unsigned int N = 2;
            double m_I = NAN;
            double reqPrec = 0.0;
            Func f;

            double integrate(double a, double b, unsigned int N)
            {
                auto I = 0.0;
                auto h = (b - a) / N;
                for (int i{1}; i <= N-1; i++)
                {
                    I += f(a + i * h);
                }
                I += 0.5 * (f(a) + f(b));
                return I*h;
            }
        };
    }
}