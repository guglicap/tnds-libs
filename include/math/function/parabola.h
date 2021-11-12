#pragma once

namespace math {
    inline namespace function {
        constexpr auto parabola(double a, double b, double c) {
            return [a, b, c](const double x) {
                return a * x * x + b * x + c;
            };
        }
    }

}
