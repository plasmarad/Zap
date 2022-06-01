#ifndef __FILES_HPP__
#define __FILES_HPP__

#include <fstream>
#include <string>
#include <vector>
#include <Language/Lexer/Lexer.hpp>


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
    
    class _workflow{
        std::vector<file> _fls;
        public:
            void operator<<(file);
    };

    // Manages files and aswell as building projects
    class Enviorment {
        _workflow _env;
        
        public:
            // initialize and setup an enviorment
            // it will also scan the directory for files
            Enviorment(std::string _ENV_DIR);
    };
    
    
}
#endif
