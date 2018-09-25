#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <cstring>  //std::memcpy()
#include <cstdlib>  //std::malloc(), std::realloc(), std::free()
#include <iostream> //std::cout, std::endl

template <typename T>
struct Matrix {

    T* data;                //Dados da matrix
    std::size_t lines;      //N�mero de linhas
    std::size_t columns;    //N�mero de colunas

    /// \brief Constr�i uma matrix m x n;
    /// \param m N�mero de linhas.
    /// \param n N�mero de colunas.
    Matrix(std::size_t m, std::size_t n) : data(nullptr), lines(m), columns(n) {
        data = static_cast<T*>(std::malloc(m * n * sizeof(T)));
        for(std::size_t i = 0; i < (m * n); i++) data[i] = static_cast<T>(0);
    }

    /// \brief Copy constructor.
    /// \param other Outra matriz.
    Matrix(const Matrix& other) : data(nullptr), lines(other.lines), columns(other.columns) {
        const std::size_t size = lines * columns * sizeof(T);
        data = static_cast<T*>(std::malloc(size));
        std::memcpy(data, other.data, size);
    }

    /// \brief Destrutor.
    ~Matrix(void) {
        std::free(data);
    }

    /// \brief Copy assignment.
    /// \param other Outra matriz.
    Matrix& operator = (const Matrix& other) {
        if(this != &other) {
            lines = other.lines;
            columns = other.columns;
            const std::size_t size = lines * columns * sizeof(T);
            data = static_cast<T*>(std::realloc(data, size));
            std::memcpy(data, other.data, size);
        }
        return (*this);
    }

    /// \brief Operador de indexa��o.
    /// \param index �ndice da linha que ser� acessada.
    /// \return Um ponteiro para o in�cio da linha.
    T* operator [] (std::size_t index) {
        return &(data[index * columns]);
    }

    /// \brief Operador de indexa��o.
    /// \param index �ndice da linha que ser� acessada.
    /// \return Um ponteiro para o in�cio da linha.
    const T* operator [] (std::size_t index) const {
        return &(data[index * columns]);
    }

    void print(void) {
        for(std::size_t i = 0; i < lines; i++) {
            for(std::size_t j = 0; j < columns; j++) {
                std::cout << this->operator[](i)[j] << "\t";
            }
            std::cout << std::endl;
        }
    }

};

#endif // __MATRIX_H__
