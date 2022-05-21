// #include <Enviorment/Files.hpp>
// -I.

#include <iostream>
#include <string>
#include "arguments.h"



int main(int argc, char** argv){
    parser args(argc, argv);

    args.addArg("help", "--help", "-h", false);
    args.addArg("file", "--file", "-f", true);

    if (args.checkArg("file")){
        args.getArgValues("file");
    }
    
    return 0;
}

// TODO: work on argument parsing
// UPDATE: it can find arguments
// UPDATE: it can find values for arguments
