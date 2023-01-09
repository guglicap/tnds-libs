#pragma once

#include "lcg.h"
#include "functional"

namespace math
{
    namespace rng
    {
        template <typename Func>
        class AcceptReject
        {
        protected:
            Func f;
            double fMax;
            LinearCongruent rng;

        public:
            AcceptReject(Func f, double fMax, unsigned long seed) : f{f},
                                                                    fMax{fMax},
                                                                    rng{LinearCongruent{seed}} {};

            auto NextRand(double xMin, double xMax)
            {
                double x{};
                for (;;)
                {
                    x = rng.NextDecimal(xMin, xMax);
                    auto yTarget = f(x);
                    auto y = rng.NextDecimal(0, fMax);
                    if (y <= yTarget)
                        break;
                };
                return x;
            };
        };
    }
}