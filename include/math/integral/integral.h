#pragma once

namespace math {
    inline namespace integral {
        class Integral {
        public:
            Integral() = default;

            virtual double Integrate(double a, double b) const = 0;
        };
    }
}
