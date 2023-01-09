#include "lcg.h"
#include "functional"

namespace math
{
    inline namespace rng
    {
        class AcceptReject
        {
        protected:
            typedef std::function<double(double)> PDF;
            PDF f;
            double fMax;
            LinearCongruent rng;

        public:
            AcceptReject(PDF f, double fMax, unsigned long seed) : rng{LinearCongruent{seed}},
                                                                   f{f},
                                                                   fMax{fMax} {};

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