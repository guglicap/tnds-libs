#pragma once

#include "solver.h"

using std::pair;

namespace math {
    inline namespace de {
        template<typename Domain>
        class EulerSolver : public Solver<Domain> {

        private:
            const double h = 1e-3;

        public:
            EulerSolver() = default;

            EulerSolver(const typename Solver<Domain>::Derivative f) : Solver<Domain>(f) {};

            EulerSolver(const typename Solver<Domain>::Derivative f, const double h) : Solver<Domain>(f),
                                                                                       h(h) {};

            typename Solver<Domain>::State Evolve(typename Solver<Domain>::State state) const {
                const auto [t, x0] = state;
                const auto df = this->f(t, x0) * h;
                return {t + h, x0 + df};
            }
        };
    }
}
