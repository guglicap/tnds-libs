#pragma once

#include <iostream>
#include <vector>
#include <fstream>

namespace io {
    template<typename T>
    std::vector <T> Read(const std::istream &in) {
        std::vector <T> data;
        while (true) {
            T v;
            in >> v;
            if (!in) break;
            data.push_back(v);
        }
        return data;
    }

    template<typename T>
    std::vector <T> Read(const std::istream &in, unsigned const int N) {
        std::vector <T> data;
        for (int i = 0; i < N; i++) {
            T v;
            in >> v;
            if (!in) break;
            data.push_back(v);
        }
        return data;
    }

    template<typename T>
    std::vector <T> ReadFile(const char *filename) {
        std::ifstream ifile(filename);

        if (!ifile) {
            std::cerr << "file '" << filename << "' not found." << std::endl;
            exit(-2);
        }

        std::vector <T> data = Read<T>(ifile);

        ifile.close();
        return data;
    }

    template<typename T>
    std::vector <T> ReadFile(const char *filename, unsigned const int N) {
        const std::ifstream ifile(filename);

        if (!ifile) {
            std::cerr << "file '" << filename << "' not found." << std::endl;
            exit(-2);
        }

        const std::vector <T> data = Read<T>(ifile, N);

        ifile.close();
        return data;
    }

    template <typename T> void Print(const std::vector<T> data, const std::ostream& out = std::cout) {
        for (const auto v: data) {
            out << v << std::endl;
        }
    }

    template <typename T> void PrintFile(const std::vector<T> data, const char* filename) {
        const std::ofstream ofile{filename};
        if (!ofile) {
            std::cerr << "couldn't open file '" << filename << "'" << std::endl;
            exit(-3);
        }
        Print(data, ofile);
    }
}