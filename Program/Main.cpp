#include <iostream>
#include <string>

// simple class to parse arguments from the command line, with support for long and short names
#include "arguments.h"
#include "Enviorment/Files.hpp"

int main(int argc, char** argv){
    // argument parser
    parser args(argc, argv);

    args.addArg("file",         "--file",       "-f",     false);
    args.addArg("enviorment",   "--enviorment", "-env",   false);

    // pass individual files
    if (args.checkArg("file")){
        Enviorment::_workflow _WorkFlow;
        
        for (std::string ite: args.getArgValues("file")){
            _WorkFlow << Enviorment::file(ite);
            
        }
    }

    // pass a directory
    if (args.checkArg("enviorment")){
        Enviorment::Enviorment _ENV = Enviorment::Enviorment(args.getArgValues("enviorment")[0]);

    }
    if (!args.checkArg("enviorment") && !args.checkArg("file")) {
        printf("Error: no specified file or directory. (hint: pass -f or -env)\n");
    }
    return 0;
}