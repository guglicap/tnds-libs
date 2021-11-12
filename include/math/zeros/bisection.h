#pragma once

#include <iostream>
#include <optional>
#include <cfloat>
#include "math/zeros/zero_finder.h"

using std::optional;
using std::pair;

namespace math {
    inline namespace zeros {
        template<typename Func>
        class Bisector : public ZeroFinder {
        public:
            Bisector(const Func f) : ZeroFinder(), f(f) {};

            Bisector(const Func f, double precision) : ZeroFinder(), f(f), prec(precision) {};

            Bisector(const Func f, double precision, int maxIterations)
                    : ZeroFinder(), f(f), prec(precision), maxIters(maxIterations) {};

            optional<pair<double, double>> FindZero(double xMin, double xMax) const override {
                if (xMin > xMax) {
                    const auto t = xMax;
                    xMax = xMin;
                    xMin = t;
                }
                auto dx = xMax - xMin;
                auto iter = 0;
                auto xMid = 0.5 * (xMax + xMin);
                while (rangeOk(dx, xMid)) {
                    if (iter > maxIters) {
                        std::cout << "reached max iterations, precision might be smaller than required" << std::endl;
                        break;
                    }
                    const auto yLow = f(xMin);
                    const auto yHigh = f(xMax);
                    if (yLow * yHigh > 0) {
                        std::cout << "invalid range! function has the same sign in range [" << xMin << ", " << xMax
                                  << "]" << std::endl;
                        return std::nullopt;
                    }
                    const auto yMid = f(xMid);
                    if (yLow * yMid < 0) {
                        xMax = xMid;
                    } else {
                        xMin = xMid;
                    }
                    dx = xMax - xMin;
                    xMid = 0.5 * (xMax + xMin);
                }
                return pair{xMid, dx / 2};
            }

        private:
            const Func f;
            const double prec = 1e-9;
            const int maxIters = 100;

            constexpr bool rangeOk(double deltaX, double midX) const {
                if (0.5*deltaX < prec) return false;
                if (0.5*deltaX < maxDoublePrec(midX)) {
                    std::cout << "warning: required precision " << prec << " is greater than maximum double precision"
                              << std::endl;
                    return false;
                }
                return true;
            }

            constexpr double maxDoublePrec(double z) const {
                return DBL_EPSILON * z;
            }
        };
    }
}
