#pragma once

#include <functional>

using std::function;

namespace math {
    inline namespace de {
        template<typename Domain>
        class Solver {
        protected:
            typedef function<Domain(double, Domain)> Derivative;
            typedef std::pair<double, Domain> State;
            const Derivative f = [](double, Domain v) { return v; };
        public:
            Solver() = default;

            Solver(Derivative f) : f(f) {};

            virtual State Evolve(State state) const = 0;
        };
    }
}
