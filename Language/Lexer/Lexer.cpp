#include "Lexer.hpp"
#include <iostream>

// ================================================================================================
char ReturnChar(std::string str, size_t index){
    if (index >= str.length() || str[index] == '\0'){
        return '\0';
    }
    return str[index];
}
bool withinRange(size_t index, size_t start, size_t end){
    return index >= start && index < end;
}
// use a map to store keywords and their token types
void Identifier_detect_keyword(std::vector<Token> &ref, std::string _buffered_string){
    //iterate through the map and if no keyword is found, create a new token with the type of Identifier
    for (auto &keyword : keyword_map){
        if (_buffered_string == keyword.first){
            ref.push_back(Token(_buffered_string,keyword.second));
            return;
        }
    }
    ref.push_back(Token(_buffered_string, TokenType::Identifier));

}

// ================================================================================================

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
                    //TODO: add support for numbers inside of variables by checking: if (isdigit(_data[ite+1]))
                    // example: hell0
                    if (!withinRange((size_t) ReturnChar(_data, ite+1), 'a', 'z') && !withinRange((size_t) ReturnChar(_data, ite+1), 'A', 'Z')){
                        __stmp += _data [ite];
                        // find if it is a keyword and push back the token accordingly
                        Identifier_detect_keyword(__tmp, __stmp);
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
        

        return __tmp;
    }
} // namespace lexer
