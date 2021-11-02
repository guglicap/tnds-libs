#include <vector>
#include <algorithm>
#include <numeric>

#pragma once

namespace stats {
    template<typename T>
    constexpr double media(const std::vector<T> data) {
        const auto N = data.size();
        const auto f = [N](double acc, double v) {
            return acc + v / N;
        };
        return std::accumulate(data.begin(), data.end(), 0.0, f);
    }

    template<typename T>
    double varianza(std::vector<T> data, double media) {
        double res;
        for (auto v: data) {
            res += (v - media) * (v - media);
        }
        if (data.size() == 1) return res; // TODO: check
        return res / (data.size() - 1);
    }

    template<typename T>
    double varianza(std::vector<T> data) {
        double m = media(data);
        return varianza(data, m);
    }

    template<typename T>
    double mediana(std::vector<T> data) {
        std::sort(data.begin(), data.end());
        int n = data.size();
        if (n % 2 == 1) return data[n / 2];
        return 0.5 * (data[n / 2 - 1] + data[n / 2]); // * * * * -> media 1 2 ; size = 2
    }
}