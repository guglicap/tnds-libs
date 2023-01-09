#pragma once
#include "cmath"

namespace math
{
    const auto Gaussian(double mean, double sigma) {
        return [mean, sigma] (double x) {
            return 1.0 / sqrt(2.0*M_PI) / sigma * exp(- (x-mean) * (x-mean) / (2*sigma*sigma));
        };
    };
}
