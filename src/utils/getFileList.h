#ifndef __GET_FILE_LIST_H__
#define __GET_FILE_LIST_H__

#include <string>   //std::string
#include <vector>   //std::vector<>

/// \brief Retorna um vetor de strings contendo a lista de arquivos de um diret�rio especificado.
/// \param directory O caminho do diret�rio.
/// \return A lista de arquivos do diret�rio especificado.
std::vector<std::string> getFileList(const std::string& directory);

#endif // __GET_FILE_LIST_H__
