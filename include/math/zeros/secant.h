#pragma once

#include <iostream>
#include <optional>
#include <cfloat>
#include <tuple>
#include "math/zeros/zero_finder.h"
#include "math/sign.h"

using std::optional;
using std::pair;
using std::cout, std::endl;

namespace math {
    inline namespace zeros {
        template<typename Func>
        class Secant : public ZeroFinder {
        public:
            Secant(const Func f) : ZeroFinder(), f(f) {};

            Secant(const Func f, double precision) : ZeroFinder(), f(f), precision(precision) {};

            Secant(const Func f, double precision, int maxIterations)
                    : ZeroFinder(), f(f), precision(precision), maxIters(maxIterations) {};

            optional<pair<double, double>> FindZero(double a, double b) const override {
                if (a > b) {
                    const auto t = b;
                    b = a;
                    a = t;
                }
                if (f(a) == 0.0) {
                    return std::pair{a, 0.0};
                }
                if (f(b) == 0.0) {
                    return std::pair{b, 0.0};
                }

                prev = a;
                double xZero = (b - a) / 2;
                auto iter = 0;
                while (precisionOk(xZero)) {
                    if (iter > maxIters) {
                        cout << "warning: reached maxIters, precision might be smaller than required" << endl;
                        break;
                    }
                    cout << "prev: " << prev << " ";
                    prev = xZero;
                    xZero = findSecantZero(a, b);
                    cout << "new: " << xZero << endl;
                    if (f(xZero) == 0.0) {
                        cout << "found zero!" << endl;
                        return std::pair{xZero, 0.0};
                    }
                    std::tie(a, b) = newRange(a, b, xZero);
                    cout << "new range: [ " << a << ", " << b << " ]" << endl;
                    iter++;
                }
                return std::pair{(xZero + prev) / 2, (xZero - prev) / 2};
            }

        private:
            const Func f;
            const double precision = 1e-9;
            mutable double prev;
            const int maxIters = 100;

            bool precisionOk(double xZero) const {
                auto zeroRange = std::abs(xZero - prev);
                if (0.5 * zeroRange < precision) {
                    cout << "range is small enough: prev " << prev << " zero: " << xZero << endl;
                    return false;
                }
                const auto dPrec = maxDoublePrec(xZero);
                if (0.5 * zeroRange < dPrec) {
                    if (precision != 0) {
                        std::cout << "warning: required precision " << precision
                                  << " is greater than maximum double precision: "
                                  << dPrec << std::endl;
                    }
                    return false;
                }
                return true;
            }

            constexpr pair<double, double> newRange(double a, double b, double xZero) const {
                auto yA = f(a);
                auto yZero = f(xZero);
                if (sign(yA) * sign(yZero) < 0) {
                    std::cout << "new range [ " << a << ", " << xZero << " ]" << std::endl;
                    return {a, xZero};
                }
                return {xZero, b};
            }

            constexpr double maxDoublePrec(double z) const {
                return DBL_EPSILON * z;
            }

            constexpr double findSecantZero(double a, double b) const {
                auto yA = f(a);
                auto yB = f(b);
                return a + ((b - a) * yA) / (yA - yB);
            }
        };
    }
}
