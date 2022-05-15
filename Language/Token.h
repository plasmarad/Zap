#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>

enum class TokenType
{
    Symbol, // symbol like a name
    Number, // Integer or floating point number
    String, // String literal
    

    // Operators
    Plus,               // +
    Equal,              // =
    Minus,              // -
    Asterisk,           // *
    Slash,              // /

    OpenBracket,        // [
    CloseBracket,       // ]
    OpenBrace,          // {
    CloseBrace,         // }
    Modifier,           //modifier: colon 
    CompilerDirective,  //compiler handle: $

};

class Token{
    private:
        TokenType type;
        std::string value;
    public:
        Token(TokenType type, std::string value): type(type), value(value) {};
};

#endif
