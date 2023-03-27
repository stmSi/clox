#include <stdio.h>

#include "common.h"
#include "compile.h"
#include "scanner.h"

const char* token_names[] = {
  "TOKEN_LEFT_PARAM", "TOKEN_RIGHT_PARAM" ,
  "TOKEN_LEFT_BRACE", "TOKEN_RIGHT_BRACE" ,
  "TOKEN_COMMA", "TOKEN_DOT", "TOKEN_MINUS", "TOKEN_PLUS",
  "TOKEN_SEMICOLON", "TOKEN_SLASH", "TOKEN_STAR",
  "TOKEN_BANG", "TOKEN_BANG_EQUAL",
  "TOKEN_EQUAL", "TOKEN_EQUAL_EQUAL",
  "TOKEN_GREATER", "TOKEN_GREATER_EQUAL",
  "TOEKN_LESS", "TOKEN_LESS_EQUAL",
  "TOKEN_IDENTIFIER", "TOKEN_STRING", "TOKEN_NUMBER",
  "TOKEN_AND", "TOKEN_CLASS", "TOKEN_ELSE", "TOKEN_FALSE",
  "TOKEN_FOR", "TOKEN_FUN", "TOKEN_IF", "TOKEN_NIL", "TOKEN_OR",
  "TOKEN_PRINT", "TOKEN_RETURN", "TOKEN_SUPER", "TOKEN_THIS",
  "TOKEN_TRUE", "TOKEN_VAR", "TOKEN_WHILE",

  "TOKEN_ERROR", "TOKEN_EOF"
};

void compile(const char* source) {
  initScanner(source);
  int line = -1;
  for(;;) {
    Token token = scanToken();
    if(token.line != line) {
      printf("%4d ", token.line);
      line = token.line;
    }else {
      printf("    | ");
    }
    printf("%s '%.*s'\n", token_names[token.type], token.length, token.start);

    if(token.type == TOKEN_EOF) break;
  }

}


