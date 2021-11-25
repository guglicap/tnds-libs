#pragma once

namespace math {
    constexpr int sign(double x) {
        return x == 0.0 ? 0 : (x > 0.0 ? 1 : -1);
    }
}