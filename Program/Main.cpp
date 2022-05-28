// #include <Enviorment/Files.hpp>
// -I.

#include <iostream>
#include <string>

// simple class to parse arguments from the command line, with support for long and short names
#include "arguments.h"
#include "Enviorment/Files.hpp"

int main(int argc, char** argv){
    parser args(argc, argv);

    args.addArg("file", "--file", "-f", false);
    args.addArg("directory", "--directory", "-d", false);

    if (args.checkArg("file")){
        
    } 
    if (!args.checkArg("directory") && !args.checkArg("file")) {
        printf("Error: no specified file or directory. (hint: pass -f or -d)\n");
    }
    return 0;
}