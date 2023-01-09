#include "lcg.h"
#include "cmath"

namespace math
{
    inline namespace rng
    {
        class Exponential
        {
        protected:
            LinearCongruent rng;
            double k;

        public:
            Exponential(double k, unsigned long seed) : k{k},
                                                        rng{LinearCongruent{seed}} {};
            auto NextRand() {
                return -1 / k * log(1 - rng.NextDecimal());
            };
        };
    }
}