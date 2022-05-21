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
                    _arg_name = __arg_name;
                    _long = __long;
                    _short = __short;
                    _required = __required;
                };
        
        };
        
        char** _argv; int _argc;
        std::vector <arg> _ARGS;
        std::string _format(char* argv);
    public:
        parser(int argc, char** argv);
        void addArg(std::string arg_name, std::string long_name, std::string short_name, bool required);
        bool checkArg(std::string arg_name);
        std::vector<std::string> getArgValues(std::string arg_name);

};

parser::parser(int argc, char** argv){
    _argv = argv; _argc = argc;
    
    
}    


std::string parser::_format(char* argv){
    std::string arg = argv;
    if(arg.substr(0,2) == "--"){
        arg = arg.substr(2);
    }
    else if(arg.substr(0,1) == "-"){
        arg = arg.substr(1);
    }
    return arg;
}

void parser::addArg(std::string arg_name, std::string long_name, std::string short_name, bool required){
    _ARGS.push_back(arg(arg_name, long_name, short_name, required));

    if (required && !checkArg(arg_name)){
        printf ("Error: argument %s is missing. (hint: pass %s)\n", arg_name.c_str(), _ARGS.back()._short.c_str());
        exit(1);
    }
}

bool parser::checkArg(std::string arg_name){
    std::string _short, _long;
    for (int i = 0; i < _ARGS.size(); i++){
        if (_ARGS[i]._arg_name == arg_name){
            _short = _ARGS[i]._short;
            _long  = _ARGS[i]._long;
            break;
        }
    }

    for (int i = 0; i < _argc; i++) { if(_argv[i] == _short || _argv[i] == _long) return true; }
    
    return false;
}

std::vector<std::string> parser::getArgValues(std::string arg_name){
    std::vector<std::string> values;
    
    int _arg_index = 0;
    // find index of arg_name in _argv
    for (int i = 0; i < _argc; i++){
        if (_format(_argv[i]) == arg_name){
           _arg_index = i;
        } 
    }

    // while an arg does not start with - or  -- push it to the vector
    for (int i = _arg_index; i < _argc; i++){
        if(_argv[i][0] != '-') values.push_back(_argv[i]);
        if (_argv[i][0] == '-' && _format(_argv[i]) != arg_name) return values;
    }
    return values;
}
#endif