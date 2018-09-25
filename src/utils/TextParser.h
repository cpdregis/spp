#ifndef __TEXT_PARSER_H__
#define __TEXT_PARSER_H__

#include <string>   //std::string, std::getline()
#include <sstream>  //std::stringstream
#include <iostream> //std::cerr, std::endl
#include <fstream>  //std::ifstream
#include <cstdlib>  //std::exit()

class TextParser {

private:

    std::ifstream file;

public:

    TextParser(const std::string& filename) : file{filename, std::ifstream::in} {
        if(!file.is_open()) {
            std::cerr << "Could not open file: " << filename << std::endl;
            std::exit(1);
        }
    }

    ~TextParser(void) {
        file.close();
    }

    template<typename T>
    std::size_t readLine(T& t) {
        std::string line;
        std::getline(file, line);
        if(line.size()) {
            std::stringstream{line} >> t;
            return 1;
        } else {
            return 0;
        }
    }


    template<typename... Args>
    std::size_t splitLine(char delimiter, Args&... args) {
        std::string line;
        std::getline(file, line);
        if(line.size()) {
            std::stringstream sstr{line};
            return _split(sstr, delimiter, args...);
        } else {
            return 0;
        }
    }

    template<typename T>
    std::size_t splitLine(char delimiter, std::vector<T>& vec) {
        std::string line;
        std::getline(file, line);
        format(line);
        std::stringstream sstr{line};
        while(true) {
            std::string value;
            std::getline(sstr, value, delimiter);
            if(value.size()) {
                T t;
                std::stringstream{value} >> t;
                vec.emplace_back(t);
            } else {
                break;
            }
        }
        return vec.size();
    }

    void replaceAll(std::string& s, const std::string& search, const std::string& replace) {
        for( std::size_t pos = 0; ; pos += replace.length() ) {
            // Locate the substring to replace
            pos = s.find( search, pos );
            if( pos == std::string::npos ) break;
            // Replace by erasing and inserting
            s.erase( pos, search.length() );
            s.insert( pos, replace );
        }
    }

    void format(std::string& line) {
        while(line.find("\t") != std::string::npos) {
            replaceAll(line, "\t", " ");
        }
        while(line.find("  ") != std::string::npos) {
            replaceAll(line, "  ", " ");
        }
    }

private:

    template<typename T>
    std::size_t _split(std::stringstream& sstr, char delimiter, T& t) {
        std::string line;
        std::getline(sstr, line, delimiter);
        if(line.size()) {
            std::stringstream{line} >> t;
            return 1;
        } else {
            return 0;
        }
    }

    template<typename T, typename... Args>
    std::size_t _split(std::stringstream& sstr, char delimiter, T& t, Args&... args) {
        std::size_t a = _split(sstr, delimiter, t);
        if(a) {
            return a + _split(sstr, delimiter, args...);
        } else {
            return a;
        }
    }

};

#endif // __TEXT_PARSER_H__
