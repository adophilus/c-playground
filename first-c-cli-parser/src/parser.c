#include <stdlib.h>
#include "parser.h"

Parser *init_parser(ParserOption *options) {
  Parser *parser = malloc(sizeof(Parser));

  parser->options = options;

  return parser;
}
