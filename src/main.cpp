#include <string>               //std::string
#include <vector>               //std::vector<>
#include <iostream>             //std::cin, std::cout, std::endl
#include "utils/getFileList.h"  //getFileList();
#include "utils/Matrix.h"
#include "utils/loadMatrix.h"
#include "algorithms/kruskal.h"

#ifdef __linux__
#define CLEAR_COMMAND "clear"
#else
#define CLEAR_COMMAND "cls"
#endif //__linux__

int main() {

    char repeat = 'y';

    while(repeat == 'y') {

        //Limpa console
        std::system(CLEAR_COMMAND);

        //Obt�m lista de inst�ncias
        std::vector<std::string> files = getFileList("instances/");;

        //Usu�rio escolhe uma inst�ncia da lista
        std::cout << "Available Instances:" << std::endl;
        for(std::size_t i = 0; i < files.size(); i++) {
            std::cout << "   (" << i << ") " << files[i] << std::endl;
        }
        std::size_t instance;
        std::cout << "\nSelect an instance: ";
        std::cin >> instance;

        Matrix<int> m = loadMatrix<int>(files[instance]);

        //Usu�rio escolhe um m�todo de ordena��o
        std::size_t method;
        std::cout << "\nAvailable methods:" << std::endl;
        std::cout << "   (0) Kruskal" << std::endl;
        std::cout << "\nSelect a method: ";
        std::cin >> method;

        //Ordena vetor de acordo com o m�todo escolhido
        switch(method) {
            case 0:
                std::cout << "Weight: " << kruskal(m) << std::endl;
                break;
            default:
                std::cout << "\nInvalid option ";
                continue;
        }

        //Usu�rio escolhe se deseja repetir o processo
        std::cout << "\nRepeat (y/n)?: ";
        std::cin >> repeat;

    }
}
