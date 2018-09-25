#ifndef __LOAD_MATRIX_H__
#define __LOAD_MATRIX_H__

#include <string>       //std::string
#include "Matrix.h"     //Matrix<>
#include "TextParser.h" //TextParser

template<typename T>
Matrix<T> loadMatrix(const std::string& filename) {

    TextParser tp(filename);

    std::size_t n;
    tp.readLine(n);

    Matrix<T> mat(n, n);

    for(std::size_t i = 0; i < n; i++) {

        std::vector<T> vec;
        tp.splitLine(' ', vec);

        for(std::size_t j = 0; j < vec.size(); j++) {
            mat[i][i + 1 + j] = mat[i + 1 + j][i] = vec[j];
        }
    }

    return mat;

}

#endif // __LOAD_MATRIX_H__
