#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__

#include "prim.h"   //Vertex

template<typename T>
T dijkstra(const Matrix<T>& mat) {

    std::vector<T> key;         // Pesos para os vizinhos mais próximos
    std::deque<Vertex<T>> q;    // Lista de vértices que ainda não fazem parte da solução
    std::vector<std::size_t> p;

    for(std::size_t i = 0; i < mat.lines; i++) {
        key.emplace_back(std::numeric_limits<T>::max());  // Todos vertices começam com o maior valor possível
    }

    for(std::size_t i = 0; i < mat.lines; i++) {
        q.emplace_back(Vertex<T>{i, &key[i]});
    }

    p.resize(mat.lines);

    key[0] = 0;

    while(q.size()) {

        std::make_heap(q.begin(), q.end());
        std::sort_heap(q.begin(), q.end());

        std::size_t u = q.front().index;
        q.pop_front();

        for(std::size_t v = 0; v < mat.lines; v++) {
            if(key[v] > (key[u] + mat[u][v])) {
                key[v] = (key[u] + mat[u][v]);
                p[v] = u;
            }
        }
    }

    T total = 0;
    std::size_t aux = mat.lines - 1;
    while(true) {
        total += mat[aux][p[aux]];
        aux = p[aux];
        if(aux == 0) break;
    }

    return total;

}

#endif // __DIJKSTRA_H__
