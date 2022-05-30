#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#include <Language/Token.h>
#include <vector>

namespace lexer
{
    // function that returns tokens
    std::vector<Token> Lex(std::string _data);
} // namespace lexer


#endif
