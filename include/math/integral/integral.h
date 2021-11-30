#pragma once

namespace math {
    inline namespace integral {
        class Integrator {
        public:
            Integrator() = default;

            virtual double Integrate(double a, double b) const = 0;
        };
    }
}
