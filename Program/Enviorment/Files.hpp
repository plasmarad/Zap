#ifndef __FILES_HPP__
#define __FILES_HPP__

#include <string>

#include <vector>
namespace Enviorment
{
    class Enviorment: protected file{
        std::vector<file> _Files;
    };
    
    class file{
        protected:
            // peak into the binary contents of the file
        public:
            file();
            ~file();
            void readFile(std::string fileName);
            void writeFile(std::string fileName);
    };
} // namespace Enviorment


#endif
