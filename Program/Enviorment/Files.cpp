#include "Files.hpp"
#include <fstream>

namespace Enviorment{
    file::file(std::string directory){
        _directory = directory;
        _fstrm.open(_directory, std::fstream::in);
        
    }
    std::string  file::readFile(){
        std::string file_contents;
        for (std::string _ln; std::getline(_fstrm, _ln);){
            file_contents += (_ln + '\n');
        }
        return file_contents;
    }

    file::~file(){
        _fstrm.close();
    }    
}


Enviorment::Enviorment::Enviorment(std::string _ENV_DIR){
    
}