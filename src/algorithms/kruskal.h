#ifndef __KRUSKAL_H__
#define __KRUSKAL_H__

#include <vector>
#include <algorithm>

// Estrutura da aresta
template<typename T>
struct Edge {

    std::size_t o;  //Origem
    std::size_t d;  //Destino
    T w;            //Peso

    // Construtor
    Edge(std::size_t origin, std::size_t destiny, T weight) : o{origin}, d{destiny}, w{weight} {}

    // Sobrecarga de operador relacional (menor que), será utilizado para ordenação de arestas
    bool operator < (const Edge<T>& other) {
        return w < other.w;
    }

};

template<typename T>
T kruskal(const Matrix<T>& mat) {

    //Cria vetor contendo as arestas
    std::vector<Edge<T>> edges;
    for(std::size_t i = 0; i < mat.lines; i++) {
        for(std::size_t j = 0; j < mat.columns; j++) {
            edges.emplace_back(Edge<T>(i, j, mat[i][j]));
        }
    }

    // Ordena vetor de arestas por peso (ordem crescente)
    std::sort(edges.begin(), edges.end());

    // Cria vetor com os identificadores de arvore
    // Cada índice representa um vertice, o conteúdo representa o identificador da arvore em que ele pertence
    // Inicialmente cada vertice pertence a uma arvore que só tem ele próprio
    std::vector<std::size_t> tree_ids;
    for(std::size_t i = 0; i < mat.lines; i++) {
        tree_ids.push_back(i);
    }

    T total = 0;    // Variavel que irá acumular a soma dos pesos

    for(std::size_t i = 0; i < edges.size(); i++) {

        //Se os vertices da aresta pertencem a arvores distintas
        if(tree_ids[edges[i].o] != tree_ids[edges[i].d]) {

            // Acumula o peso na variável total
            total += edges[i].w;

            // Coloca os vertices na mesma arvore (com o mesmo identificador)
            std::size_t id = tree_ids[edges[i].d];
            for(std::size_t j = 0; j < tree_ids.size(); j++) {
                if(tree_ids[j] == id) {
                    tree_ids[j] = tree_ids[edges[i].o];
                }
            }

        }

    }

    return total;

}

#endif // __KRUSKAL_H__
