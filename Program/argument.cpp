#include "arguments.h"

parser::parser(int argc, char** argv){
    _argv = argv; _argc = argc;
}    

// remove -- or - from command argv
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
        printf ("Error: argument \"%s\" is missing. (hint: pass %s or %s)\n", arg_name.c_str(), _ARGS.back()._short.c_str(), _ARGS.back()._long.c_str());
        exit(1);
    }
}

bool parser::checkArg(std::string arg_name){
    for (int i = 0; i < _argc; i++) { 
        if(_argv[i] == _getArg(arg_name)._short || _argv[i] == _getArg(arg_name)._long) {
            return true;
        } 
    }
    return false;
}


parser::arg parser::_getArg(std::string arg_name){
    for (size_t i = 0; i < _ARGS.size(); i++){
        if (_ARGS[i]._arg_name == arg_name){
            return _ARGS[i];
        }
    }
    return _ARGS[0];
}

std::vector<char*> parser::getArgValues(std::string arg_name){
    std::vector<char*> _tmp_values;
    
    //offset for when looking in _argv
    int _arg_index = 0;
    
    // find the offset value by finding the argument's location in _argv
    for (int i = 0; i < _argc; i++) { 
        // find the location of arg_name in _argv
        if(_argv[i] == _getArg(arg_name)._short || _argv[i] == _getArg(arg_name)._long) {
            // if the next (i+1) cell in _argv is null: add 1 to i, otherwise add 0 to i 
            _arg_index =  (i += ( (_argv[i+1] == nullptr) ? 0 : 1));
        } 
    }
    
    // returning the actual tokens
    for (int i = _arg_index;i < _argc; i++){
        // if it's not an argument: push to the vector
        if  (_argv[i][0] != '-') _tmp_values.push_back(_argv[i]);
        // otherwise: return all the arguments.
        if  (_argv[i][0] == '-') return _tmp_values;
    }
    // return the arguments in the form of a vector of chars (char*)
    return _tmp_values;
}

