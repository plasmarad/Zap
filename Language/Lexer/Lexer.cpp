#include "Lexer.hpp"
#include <iostream>

// EXTRAS:
char ReturnChar(std::string str, size_t index){
    if (index >= str.length() || str[index] == '\0'){
        return '\0';
    }
    return str[index];
}
bool withinRange(size_t index, size_t start, size_t end){
    return index >= start && index < end;
}


namespace lexer
{
    std::vector<Token> Lex(std::string _data){
        std::vector<Token>  __tmp;
        std::string         __stmp; 

        for (size_t ite = 0; ite < _data.size(); ite++){
            switch (_data[ite]){
                case '_':
                case 'a'...'z':
                case 'A'...'Z':
                    if (!withinRange((size_t) ReturnChar(_data, ite+1), 'a', 'z') && !withinRange((size_t) ReturnChar(_data, ite+1), 'A', 'Z')){
                        __stmp += _data [ite];
                        __tmp.push_back(Token(__stmp, TokenType::Symbol));
                        __stmp.clear();
                    }
                    else{
                        __stmp += _data[ite];
                    }
                    break;
                case '.':
                    if (!withinRange((size_t) ReturnChar(_data, ite-1), '0', '9') && !withinRange((size_t) ReturnChar(_data, ite+1), '0', '9')){
                        __tmp.push_back(Token( ".", TokenType::Period));
                        __stmp.clear();
                        break;
                    }
                case '0'...'9':
                    __stmp += _data[ite];
                    if (!withinRange((size_t) ReturnChar(_data, ite+1), '0', '9') && ReturnChar(_data, ite+1) != '.'){
                        __tmp.push_back(Token(__stmp, TokenType::Number));
                        __stmp.clear();
                    }
                    break;
                case '\"':
                    ite+=1;
                    {
                    while (ReturnChar(_data, ite) != '\"'){
                        // check for escape sequence
                        if (ReturnChar(_data, ite) == '\\' && ReturnChar(_data, ite+1) == '\"'){
                            __stmp += '\"';
                            ite+=2;
                        }
                        __stmp += _data[ite];
                        ite+=1;
                        // deal with escape sequences in a OOP manner, and not during lexing
                    }
                    __tmp.push_back(Token(__stmp, TokenType::String));
                    __stmp.clear();
                    }
                    break;
                case ',':
                    __tmp.push_back(Token(",", TokenType::Comma));
                    break;
                case '+':
                    __tmp.push_back(Token("+", TokenType::Plus));
                    break;
                case '-':
                    __tmp.push_back(Token("-", TokenType::Dash));
                    break;
                case '*':
                    __tmp.push_back(Token("*", TokenType::Asterisk));
                    break;
                case '/':
                    __tmp.push_back(Token("/", TokenType::Slash));
                    break;
                case '[':
                    __tmp.push_back(Token("[", TokenType::OpenBracket));
                    break;
                case ']':
                    __tmp.push_back(Token("]", TokenType::CloseBracket));
                    break;
                case '{':
                    __tmp.push_back(Token("{", TokenType::OpenBrace));
                    break;
                case '}':
                    __tmp.push_back(Token("}", TokenType::CloseBrace));
                    break;
                case ':':
                    __tmp.push_back(Token(":", TokenType::Modifier));
                    break;
                case '$':
                    __tmp.push_back(Token("$", TokenType::CompilerDirective));
                    break;
                case ' ':
                    break;
                case ';':
                    __tmp.push_back(Token(";", TokenType::EOE));
                    break;
                default:
                    break;
            }
        }
        for (Token ite: __tmp){
            printf("%i %s\n", (int) ite.type, ite.value.c_str());
        }
        return __tmp;
    }
} // namespace lexer
