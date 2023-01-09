#pragma once
#include <tuple>

namespace math
{
    inline namespace integral
    {
        class Integrator
        {
        protected:
            typedef std::pair<double, double> Result; // integral, precision

        public:
            Integrator() = default;
            virtual Result Integrate(double a, double b) = 0;
        };
    }
}
