//
// Created by goo on 10/25/21.
//

#ifndef ESERCIZIO3_1_STATS_H
#define ESERCIZIO3_1_STATS_H

#include <vector>
#include <algorithm>

namespace stats {
    template<typename T> double media(std::vector<T> data) {
        double res;
        for (auto v: data) {
            res += v / data.size();
        }
        return res;
    }

    template<typename T> double varianza(std::vector<T> data, double media) {
        double res;
        for (auto v: data) {
            res += (v - media) * (v - media);
        }
        if (data.size() == 1) return res; // TODO: check
        return res / (data.size() - 1);
    }

    template<typename T> double varianza(std::vector<T> data) {
        double m = media(data);
        return varianza(data, m);
    }

    template <typename T> double mediana(std::vector<T> data) {
        std::sort(data.begin(), data.end());
        int n = data.size();
        if (n % 2 == 1) return data[n/2];
        return 0.5 * (data[n/2 - 1] + data[n/2]); // * * * * -> media 1 2 ; size = 2
    }
}

#endif //ESERCIZIO3_1_STATS_H
