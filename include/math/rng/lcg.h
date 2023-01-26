#pragma once

namespace math
{
    namespace rng
    {
        class LinearCongruent
        {
        private:
            unsigned long x_prev;
            unsigned long m = 1 << 31; // 2^31
            unsigned long a = 1664525;
            unsigned long c = 1013904223;

        public:
            LinearCongruent(unsigned long seed) : x_prev(seed) {};

            auto NextInt()
            {
                x_prev = (a * x_prev + c) % m;
                return x_prev;
            };

            auto NextDecimal()
            {
                x_prev = (a * x_prev + c) % m;
                return x_prev / double(m);
            }

            auto NextDecimal(double xMin, double xMax)
            {
                auto r = NextDecimal();
                return xMin + (xMax - xMin) * r;
            }
        };
    }
}