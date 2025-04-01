#include <stdlib.h>
#include "parser.h"

int main(int argc, char **argv) {
  ParserOption *parser_options = malloc(sizeof(ParserOption) * 2);
  ParserOption feature_parser_option = {.short_name = "-f",
                                        .long_name = "--feature"};
  ParserOption count_parser_option = {.short_name = "-c",
                                      .long_name = "--count"};
  parser_options[0] = feature_parser_option;
  parser_options[1] = count_parser_option;

  Parser *parser = init_parser(parser_options);

  return 0;
}
