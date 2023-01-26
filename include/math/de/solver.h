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
            Derivative f;
        public:
            Solver(Derivative f) : f(f) {};

            virtual State Evolve(State state) const = 0;

            State EvolveFor(const double duration, State state) const {
                const auto t0 = state.first;
                auto &t = state.first;
                while (t - t0 < duration) {
                    state = Evolve(state);
                }
                return state;
            }
        };
    }
}
