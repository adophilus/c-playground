#include "parser.h"
#include <stdlib.h>

int main(int argc, char **argv) {
  ParserArgument *parser_options = malloc(sizeof(ParserArgument) * 2);
  ParserArgument feature_parser_option = {.short_name = "-f",
                                        .long_name = "--feature"};
  ParserArgument count_parser_option = {.short_name = "-c",
                                      .long_name = "--count"};
  Parser *parser = parser_init();
  parser_add_argument(parser, feature_parser_option);
  parser_add_argument(parser, count_parser_option);

  parser_parse(parser, argc, argv);

  return 0;
}
