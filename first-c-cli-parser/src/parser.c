#include "parser.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Parser *parser_init() {
  Parser *parser = malloc(sizeof(Parser));
  return parser;
}

void parser_add_argument(Parser *parser, ParserArgument option) {
  parser->arguments = realloc(parser->arguments, sizeof(ParserArgument) *
                                                     parser->argument_length++);
  InternalParserArgument internal_parser_option = {
      .short_name = option.short_name,
      .long_name = option.long_name,
      .is_checked = false};
  parser->arguments[parser->argument_length] = internal_parser_option;
}

void parser_parse(Parser *parser, int arguments_count, char **arguments) {
  InternalParserArgument *current_parser_argument_being_checked;

  for (int i = 0; i < arguments_count; i++) {
    char *current_argument = arguments[i];
    bool is_checking_argument = (i % 2) == 0;

    for (int j = 0; j < parser->argument_length; j++) {
      InternalParserArgument *current_parser_argument = &parser->arguments[j];

      if (current_parser_argument->is_checked == true) {
        continue;
      }

      if (is_checking_argument) {
        if (current_argument == current_parser_argument->short_name ||
            current_argument == current_parser_argument->long_name) {
          current_parser_argument_being_checked = current_parser_argument;
          fprintf(stderr, "Currently parser argument being checked: %s\n",
                  current_parser_argument_being_checked->long_name);
          break;
        }
      } else {
        char *value = current_argument;
        fprintf(stderr, "Found value for current parser argument %s: %s\n",
                current_parser_argument_being_checked->long_name, value);
        current_parser_argument_being_checked->value = value;
        current_parser_argument_being_checked->is_checked = true;
      }
    }
  }
}
