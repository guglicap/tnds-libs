#pragma once

#include <functional>

using std::function;

namespace math {
    inline namespace de {
        template<typename Domain>
        class Solver {
        protected:
            typedef function<Domain(double, Domain)> EvolutionFunction;
            const EvolutionFunction f = [](double, Domain v) { return v; };
        public:
            Solver() = default;

            Solver(EvolutionFunction f) : f(f) {};

            virtual Domain Step(double t, Domain state) const = 0;
        };
    }
}
