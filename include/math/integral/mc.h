#pragma once

#include "integral.h"
#include "math/rng/lcg.h"
#include <cmath>

namespace math
{
    inline namespace integral
    {
        template <typename Func>
        class MonteCarloHoM : public Integrator
        {
        private:
            Func f;
            double fMax;
            unsigned int N = 1000;
            rng::LinearCongruent rng;

        public:
            MonteCarloHoM(Func f, double fMax, unsigned long seed) : f{f},
                                                                     fMax{fMax},
                                                                     rng{rng::LinearCongruent{seed}} {};

            MonteCarloHoM(Func f, double fMax, unsigned long seed, unsigned int N) : f{f},
                                                                                     fMax{fMax},
                                                                                     N{N},
                                                                                     rng{rng::LinearCongruent{seed}} {};

            Result Integrate(double a, double b) override
            {
                unsigned int nHit = 0;
                auto xMean = 0.0;
                auto xSqMean = 0.0;
                for (int i = 0; i < N; i++)
                {
                    auto x = rng.NextDecimal(a, b);
                    xMean += x / N;
                    xSqMean += x * x / N;
                    auto y = rng.NextDecimal(0, fMax);
                    if (y >= f(x))
                        continue;
                    nHit++;
                }
                const auto aTot = (b - a) * fMax;
                return Result{
                    aTot * nHit / double(N),
                    sqrt(xSqMean - xMean * xMean) * aTot / sqrt(double(N)),
                };
            }
        };

        template <typename Func>
        class MonteCarloMean : public Integrator
        {
        private:
            Func f;
            unsigned int N = 1000;
            rng::LinearCongruent rng;

        public:
            MonteCarloMean(Func f, unsigned long seed) : f{f},
                                                         rng{rng::LinearCongruent{seed}} {};

            MonteCarloMean(Func f, unsigned long seed, unsigned int N) : f{f},
                                                                         N{N},
                                                                         rng{rng::LinearCongruent{seed}} {};

            Result Integrate(double a, double b) override
            {
                double yMean = 0.0;
                double ySqMean = 0.0;
                for (int i = 0; i < N; i++)
                {
                    auto x = rng.NextDecimal(a, b);
                    auto y = f(x);
                    yMean += y / double(N);
                    ySqMean += y * y / double(N);
                }
                return Result{
                    (b - a) * yMean,
                    sqrt(ySqMean - yMean * yMean) * (b - a) / sqrt(N),
                };
            }
        };

    }
}