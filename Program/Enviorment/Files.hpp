#ifndef __FILES_HPP__
#define __FILES_HPP__

#include <fstream>
#include <string>
#include <vector>

namespace Enviorment
{
    class file{
        protected:
            std::string _directory;
            std::fstream _fstrm;
        public:
            // @param directory: the directory to read the file from
            file(std::string directory);
            ~file();
            std::string readFile();
    };
    
    class Enviorment: protected file {
        std::vector<file> _Files;
    };
    
    
}
#endif
