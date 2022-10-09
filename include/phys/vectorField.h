#pragma once

#include "phys/vector3.h"

namespace phys {

    template <typename T>
    class vectorField {
    public:

        vectorField(T f) : f(f) {};

        vector fieldAt(vector pos) const {
            return f(pos);
        };

    private:
        T f;
    };

    template <typename T>
    auto operator+(const vectorField<T> &lhs, const vectorField<T> &rhs) {
        return vectorField{
                [lhs,rhs](const vector r) { return lhs.fieldAt(r) + rhs.fieldAt(r); }
        };
    }
}
