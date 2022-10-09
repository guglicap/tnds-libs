#pragma once
#include <tuple>

namespace math {
    inline namespace integral {
        class Integrator {
        public:
            Integrator() = default;

            virtual std::pair<double, double> Integrate(double a, double b) const = 0;
        };
    }
}
