#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <cstring>  //std::memcpy()
#include <cstdlib>  //std::malloc(), std::realloc(), std::free()
#include <iostream> //std::cout, std::endl

template <typename T>
class Matrix {

private:

    T* data;                //Dados da matrix
    std::size_t lines;      //Número de linhas
    std::size_t columns;    //Número de colunas

public:

    /// \brief Constrói uma matrix m x n;
    /// \param m Número de linhas.
    /// \param n Número de colunas.
    Matrix(std::size_t m, std::size_t n) : data(nullptr), lines(m), columns(n) {
        data = static_cast<T*>(std::malloc(m * n * sizeof(T)));
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

    /// \brief Operador de indexação.
    /// \param index Índice da linha que será acessada.
    /// \return Um ponteiro para o início da linha.
    T* operator [] (std::size_t index) {
        return &(data[index * columns]);
    }

    /// \brief Operador de indexação.
    /// \param index Índice da linha que será acessada.
    /// \return Um ponteiro para o início da linha.
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
