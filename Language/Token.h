#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>

enum class TokenType
{
    Symbol, // symbol like a name, symbols can be letterss
    Number, // Integer or floating point number
    String, // String literal
    

    // Operators
    Plus,               // +
    Equal,              // =
    Minus,              // -
    Asterisk,           // *
    Slash,              // /
    Period,             // .

    OpenBracket,        // [
    CloseBracket,       // ]
    OpenBrace,          // {
    CloseBrace,         // }
    Modifier,           //modifier: colon 
    CompilerDirective,  //compiler handle: $

};

class Token{
    public:
        TokenType type;
        std::string value;
    
        Token(std::string value, TokenType type): type(type), value(value) {};
};

#endif