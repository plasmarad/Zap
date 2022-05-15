#ifndef __ARG_PARSER_HPP__
#define __ARG_PARSER_HPP__

#include <string>

// argument parser
// Language: cpp
// header only

class ArgParser
{
    public: 
        ArgParser(int argc, char** argv);
        ~ArgParser();
};
#endif

// use:
//      ArgParser parser(argc, argv);
//           argument: short, long, 
//      if (parser.argument(""))