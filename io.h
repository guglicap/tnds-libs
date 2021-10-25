#ifndef ESERCIZIO3_1_IO_H

#include <iostream>
#include <vector>
#include <fstream>

namespace io {
    template<typename T>
    std::vector <T> Read(std::istream &in) {
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
    std::vector <T> Read(std::istream &in, unsigned int N) {
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
    std::vector <T> ReadFile(const char *filename, unsigned int N) {
        std::ifstream ifile(filename);

        if (!ifile) {
            std::cerr << "file '" << filename << "' not found." << std::endl;
            exit(-2);
        }

        std::vector <T> data = Read<T>(ifile, N);

        ifile.close();
        return data;
    }

    template <typename T> void Print(std::vector<T> data, std::ostream& out = &std::cout) {
        for (auto v: data) {
            out << v << std::endl;
        }
    }

    template <typename T> void PrintFile(std::vector<T> data, const char* filename) {
        std::ofstream ofile(filename);
        if (!ofile) {
            std::cerr << "couldn't open file '" << filename << "'" << std::endl;
            exit(-3);
        }
        Print(data, ofile);
    }
}
#define ESERCIZIO3_1_IO_H

#endif //ESERCIZIO3_1_IO_H
