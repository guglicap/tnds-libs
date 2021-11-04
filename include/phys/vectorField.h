#pragma once

#include "phys/vector.h"
#include "concepts"

namespace phys {

    template <typename T>
    concept VectorFunc = requires(T f, vector v) {
        { f(v) } -> std::convertible_to<vector>;
    };

    template <VectorFunc T>
    class vectorField {
    public:

        vectorField(T f) : f(f) {};

        vector fieldAt(vector pos) const {
            return f(pos);
        };

    private:
        T f;
    };

    template <VectorFunc T>
    auto operator+(const vectorField<T> &lhs, const vectorField<T> &rhs) {
        return vectorField{
                [lhs,rhs](const vector r) { return lhs.fieldAt(r) + rhs.fieldAt(r); }
        };
    }
}
