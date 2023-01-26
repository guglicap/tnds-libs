#pragma once

#include "solver.h"

namespace math {
    inline namespace de {
        template<typename Domain>
        class RungeKuttaSolver : public Solver<Domain> {
        private:
            double h = 0.1;
        public:
            RungeKuttaSolver(const typename Solver<Domain>::Derivative f) : Solver<Domain>(f) {};

            RungeKuttaSolver(const typename Solver<Domain>::Derivative f, double step) : Solver<Domain>(f),
                                                                                         h(step) {};

            typename Solver<Domain>::State Evolve(typename Solver<Domain>::State x) const {
                const auto [t, state] = x;
                const auto k1 = this->f(t, state);
                const auto k2 = this->f(t + h / 2, state + h / 2 * k1);
                const auto k3 = this->f(t + h / 2, state + h / 2 * k2);
                const auto k4 = this->f(t + h, state + h * k3);
                return {t + h, state + (k1 + 2 * k2 + 2 * k3 + k4) * (h / 6.0)};
            }
        };
    }
}
