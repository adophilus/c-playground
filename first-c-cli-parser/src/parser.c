#include "parser.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Parser *parser_init() {
  Parser *parser = malloc(sizeof(Parser));
  return parser;
}

void parser_add_argument(Parser *parser, ParserArgument argument) {
  size_t argument_index = parser->argument_length;
  size_t parser_arguments_size =
      sizeof(ParserArgument) * ++parser->argument_length;

  /* fprintf(stderr, "Parser argument size: %ld\n", parser_arguments_size); */
  /* fprintf(stderr, "argument_index = %ld\n", argument_index); */
  /* fprintf(stderr, "parser->argument_length = %ld\n",
   * parser->argument_length); */

  void *arguments = realloc(parser->arguments, parser_arguments_size);
  if (arguments == NULL) {
    fprintf(stderr, "Failed to reallocate memory for arguments\n");
    exit(1);
  }

  parser->arguments = arguments;

  /* InternalParserArgument internal_parser_argument = { */
  /*     .short_name = argument.short_name, */
  /*     .long_name = argument.long_name, */
  /*     .is_checked = false}; */
  /* parser->arguments[argument_index] = internal_parser_argument; */

  parser->arguments[argument_index].short_name = argument.short_name;
  parser->arguments[argument_index].long_name = argument.long_name;
  parser->arguments[argument_index].is_checked = false;
}

void parser_parse(Parser *parser, int arguments_count, char **arguments) {
  fprintf(stderr, "Beginning parsing...\n");

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

  fprintf(stderr, "Done parsing...\n");
}
