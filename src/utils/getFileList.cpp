#include "getFileList.h"

#include <dirent.h> //DIR, dirent, readdir, closedir
#include <iostream> //std::cerr, std::endl
#include <cstring>  //std::strcmp()

std::vector<std::string> getFileList(const std::string& directory) {
    std::vector<std::string> file_list;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(directory.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if(std::strcmp(ent->d_name, ".") != 0 && std::strcmp(ent->d_name, "..") != 0) {
                file_list.push_back(directory + std::string(ent->d_name));
            }
        }
        closedir (dir);
    } else {
        std::cerr << "Could not open directory: " << directory << std::endl;
    }
    return file_list;
}
