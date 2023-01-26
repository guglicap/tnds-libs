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
        class Bisection : public ZeroFinder {
        public:
            Bisection(const Func f) : ZeroFinder(), f(f) {};

            Bisection(const Func f, double precision) : ZeroFinder(), f(f), prec(precision) {};

            Bisection(const Func f, double precision, int maxIterations)
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
                        std::cout << "warning: reached max iterations, precision might be smaller than required"
                                  << std::endl;
                        break;
                    }
                    const auto yLow = f(xMin);
                    const auto yHigh = f(xMax);
                    if (yLow == 0.0 || yHigh == 0.0) {
                        return pair{yLow == 0.0 ? xMin : xMax, 0};
                    }
                    if (yLow * yHigh > 0) { // TODO: use sign function
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
                    iter++;
                }
                return pair{xMid, dx / 2};
            }

        private:
            Func f;
            double prec = 1e-9;
            int maxIters = 100;

            bool rangeOk(double deltaX, double midX) const {
                if (0.5 * deltaX < prec) return false;
                const auto dPrec = maxDoublePrec(midX);
                if (0.5 * deltaX < dPrec) {
                    if (prec != 0) {
                        std::cout << "warning: required precision " << prec
                                  << " is greater than maximum double precision: "
                                  << dPrec << std::endl;
                    }
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
