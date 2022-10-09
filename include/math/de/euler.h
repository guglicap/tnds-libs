#pragma once

#include "solver.h"

using std::pair;

namespace math {
    inline namespace de {
        template<typename Domain>
        class EulerSolver : public Solver<Domain> {

        private:
            const double dx = 1e-3;

        public:
            EulerSolver() = default;

            EulerSolver(const typename Solver<Domain>::EvolutionFunction f) : Solver<Domain>(f) {};

            EulerSolver(const typename Solver<Domain>::EvolutionFunction f, const double step) : Solver<Domain>(f),
                                                                                                 dx(step) {};

            constexpr Domain Step(double t, Domain x0) const {
                const auto df = this->f(t, x0) * dx;
                return x0 + df;
            }
        };
    }
}
