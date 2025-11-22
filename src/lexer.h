#ifndef LEXER_H
#define LEXER_H

#include <stddef.h>
#include <stdbool.h>

typedef enum {

    TOK_WORD,
    TOK_PIPE,
    TOK_SEMICOLON,
    TOK_REDIR_OUT,
    TOK_REDIR_APPEND,
    TOK_ERROR,
    TOK_EOF

} TokenType;

typedef struct {

    TokenType type;
    char *lexeme;
    size_t pos;  // Byte offset for error reporting

} Token;

typedef struct {

    Token *tokens;
    size_t count;
    size_t cap;

} TokenVector;

void token_vector_init(TokenVector *vec);
void token_vector_free(TokenVector *vec);
int lex(const char *input, TokenVector *output);

#endif
