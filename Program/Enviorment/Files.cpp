#include "Files.hpp"
#include <fstream>


namespace Enviorment{
    file::file(std::string directory){
        _directory = directory;
        
        _fstrm.open(_directory, std::fstream::in);
        
    }
    std::string  file::readFile(){
        std::string file_contents;
        std::string line;
        while(std::getline(_fstrm, line)){
            file_contents += line + "\n";
        }
        return file_contents;
    }

    file::~file(){
        _fstrm.close();
        printf("Closing file: %s\n", _directory.c_str());
    }
}