#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#include <Token.h>

namespace lexer
{
    class lexer
    {
        public:
            lexer(std::string input);
            ~lexer();
            Token* nextToken();
        private:
            std::string input;
            int currentPosition;
            int readPosition;
            char peekChar();
    };
} // namespace lexer


#endif
