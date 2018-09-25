#ifndef __PRIM_H__
#define __PRIM_H__

#include <limits>
#include <vector>
#include <deque>

template<typename T>
struct Vertex {

    std::size_t index;    // Número do vértice
    T* key;               // Peso para o vizinho mais próximo

    // Construtor
    Vertex(std::size_t index, T* key) : index{index}, key{key} {};

    // Sobrecarga de operador relacional (menor que), será utilizado na fila de prioridades
    bool operator < (const Vertex<T>& other) {
        return (*key) < (*other.key);
    }

};

template<typename T>
T prim(const Matrix<T>& mat) {

    std::vector<T> key;         // Pesos para os vizinhos mais próximos
    std::deque<Vertex<T>> q;    // Lista de vértices que ainda não fazem parte da solução

    for(std::size_t i = 0; i < mat.lines; i++) {
        key.emplace_back(std::numeric_limits<T>::max());  // Todos vertices começam com o maior peso possível
    }

    for(std::size_t i = 0; i < mat.lines; i++) {
        q.emplace_back(Vertex<T>{i, &key[i]});
    }

    key[0] = 0; // Começa pelo vértice zero

    while(q.size()) {

        std::make_heap(q.begin(), q.end());
        std::sort_heap(q.begin(), q.end());

        std::size_t u = q.front().index;
        q.pop_front();

        for(std::size_t i = 0; i < q.size(); i++) {
            std::size_t v = q[i].index;
            if(mat[u][v] < key[v]) {
                key[v] = mat[u][v];
            }
        }

    }

    T total = 0;
    for(std::size_t i = 0; i < key.size(); i++) {
        total += key[i];
    }

    return total;

}

#endif // __PRIM_H__
