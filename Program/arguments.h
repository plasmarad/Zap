#ifndef __ARG_PARSER_HPP__
#define __ARG_PARSER_HPP__

#include <iostream>
#include <string>
#include <vector>

class parser{
    private:
        class arg{
            public:
                std::string _arg_name;
                std::string _long;
                std::string _short;
                bool _required;
                std::vector<std::string> _values;
                arg(std::string __arg_name, std::string __long, std::string __short, bool __required){
                    _arg_name   = __arg_name;
                    _long       = __long;
                    _short      = __short;
                    _required   = __required;
                };
        
        };
        
        char** _argv; int _argc;
        std::vector <arg> _ARGS;
        std::string _format(char* argv);
        // reference to the arg object
        arg _getArg(std::string arg_name);
    public:
        parser(int argc, char** argv);
        void addArg(std::string arg_name, std::string long_name, std::string short_name, bool required);
        bool checkArg(std::string arg_name);
        std::vector<char*> getArgValues(std::string arg_name);

};

#endif