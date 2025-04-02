#include <stdbool.h>
#include <stddef.h>

typedef struct {
  char *short_name;
  char *long_name;
} ParserArgument;

typedef struct {
  char *short_name;
  char *long_name;
  bool is_checked;
  char *value;
} InternalParserArgument;

typedef struct {
  char *short_name;
  char *long_name;
  char *value;
} ParserResult;

typedef struct {
  InternalParserArgument *arguments;
  size_t argument_length;
  ParserResult *results;
} Parser;

Parser *parser_init();
void parser_add_argument(Parser *parser, ParserArgument argument);
void parser_parse(Parser *parser, int arguments_count, char **arguments);
