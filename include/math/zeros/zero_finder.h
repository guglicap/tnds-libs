#pragma once
#include <optional>
#include <tuple>

namespace math {
    inline namespace zeros {
        class ZeroFinder {
        public:
            ZeroFinder() = default;
            ~ZeroFinder() {;};

            virtual std::optional<std::pair<double, double>> FindZero(double xMin, double xMax) const = 0;
        };
    }
}
