#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>
#include <map>

// this improves readability (Atleast to me)
#define KEYWORD_BREAK       "break"
#define KEYWORD_CLASS       "class"
#define KEYWORD_CONSTANT    "const"
#define KEYWORD_CONTINUE    "continue"
#define KEYWORD_ELSE        "else"
#define KEYWORD_FOR         "for"
#define KEYWORD_IF          "if"
#define KEYWORD_INCLUDE     "include"
#define KEYWORD_NONE        "none"
#define KEYWORD_PRIVATE     "private"
#define KEYWORD_PUBLIC      "public"
#define KEYWORD_RETURN      "return"
#define KEYWORD_WHILE       "while"


enum class TokenType
{
    Identifier, // symbol like a name, symbols can be letters
    Number, // Integer or floating point number
    String, // String literal

    // Keywords
    Keyword_None,
    Keyword_If,
    Keyword_Else,
    Keyword_While,
    Keyword_For,
    Keyword_Return,
    Keyword_Break,
    Keyword_Continue,
    Keyword_Class,
    Keyword_Include,
    Keyword_Public,
    Keyword_Private,

    // Operators
    Plus,               // +
    Assign,             // =
    Dash,               // -
    Asterisk,           // *
    Slash,              // /
    Period,             // .
    Not,                // !
    At,                 // @
    Modulus,            // %
    Caret,              // ^
    Ampersand,          // &
    GreaterThan,        // >
    LessThan,           // <
    LessThanEqual,      // <=
    GreaterThanEqual,   // >=
    Equals,             // ==
    NotEqual,           // !=
    Question,           // ?
    Tilde,              // ~
    Pipe,
    Or,
    And,
    Modifier,           //modifier: colon 
    CompilerDirective,  //compiler handle: $
    EOE,                // end of expression: ; (semicolon)


    OpenBracket,        // [
    CloseBracket,       // ]
    OpenBrace,          // {
    CloseBrace,         // }
    
    Comma,
    Comment
    
};

// maps the token type to the string representation of the token type
// for easier lookup later on
std::map <std::string, TokenType> keyword_map = {
    { KEYWORD_IF,        TokenType::Keyword_If       },
    { KEYWORD_ELSE,      TokenType::Keyword_Else     },
    { KEYWORD_WHILE,     TokenType::Keyword_While    },
    { KEYWORD_FOR,       TokenType::Keyword_For      },
    { KEYWORD_RETURN,    TokenType::Keyword_Return   },
    { KEYWORD_BREAK,     TokenType::Keyword_Break    },
    { KEYWORD_CONTINUE,  TokenType::Keyword_Continue },
    { KEYWORD_CLASS,     TokenType::Keyword_Class    },
    { KEYWORD_NONE,      TokenType::Keyword_None     },
    { KEYWORD_INCLUDE,   TokenType::Keyword_Include  },
    { KEYWORD_PUBLIC ,   TokenType::Keyword_Public   },
    { KEYWORD_PRIVATE,   TokenType::Keyword_Private  }
};

class Token{
    public:
        TokenType type;
        std::string value;
    
        Token(std::string value, TokenType type): type(type), value(value) {};
};

#endif