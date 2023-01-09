#pragma once

#include "lcg.h"
#include "cmath"

namespace math
{
    namespace rng
    {
        class Gaussian
        {
        protected:
            LinearCongruent rng;
            double x0 = 0.0;
            double sigma = 1.0;

        public:
            Gaussian(unsigned long seed) : rng{LinearCongruent{seed}} {};
            Gaussian(unsigned long seed, double x0, double sigma) : x0{x0},
                                                                    sigma{sigma},
                                                                    rng{LinearCongruent{seed}} {};

            auto NextRand()
            {
                auto s = rng.NextDecimal();
                auto t = rng.NextDecimal();
                auto x = sqrt(-2 * log(1 - s)) * cos(2 * M_PI * t);
                return x0 + x * sigma;
            };
        };
    }
}