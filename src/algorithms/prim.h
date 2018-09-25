#ifndef __PRIM_H__
#define __PRIM_H__

#include <limits>
#include <vector>
#include <deque>

template<typename T>
struct Vertex {

    std::size_t index;    // N�mero do v�rtice
    T* key;               // Peso para o vizinho mais pr�ximo

    // Construtor
    Vertex(std::size_t index, T* key) : index{index}, key{key} {};

    // Sobrecarga de operador relacional (menor que), ser� utilizado na fila de prioridades
    bool operator < (const Vertex<T>& other) {
        return (*key) < (*other.key);
    }

};

template<typename T>
T prim(const Matrix<T>& mat) {

    std::vector<T> key;         // Pesos para os vizinhos mais pr�ximos
    std::deque<Vertex<T>> q;    // Lista de v�rtices que ainda n�o fazem parte da solu��o

    for(std::size_t i = 0; i < mat.lines; i++) {
        key.emplace_back(std::numeric_limits<T>::max());  // Todos vertices come�am com o maior peso poss�vel
    }

    for(std::size_t i = 0; i < mat.lines; i++) {
        q.emplace_back(Vertex<T>{i, &key[i]});
    }

    key[0] = 0; // Come�a pelo v�rtice zero

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
