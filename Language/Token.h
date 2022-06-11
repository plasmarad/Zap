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
    Dash,              // -
    Asterisk,           // *
    Slash,              // /
    Period,             // .
    Modifier,           //modifier: colon 
    CompilerDirective,  //compiler handle: $
    EOE,                // end of expression: ; (semicolon)


    OpenBracket,        // [
    CloseBracket,       // ]
    OpenBrace,          // {
    CloseBrace,         // }
    
    Comma
};

class Token{
    public:
        TokenType type;
        std::string value;
    
        Token(std::string value, TokenType type): type(type), value(value) {};
};

#endif