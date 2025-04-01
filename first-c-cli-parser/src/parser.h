typedef struct {
  char *short_name;
  char *long_name;
} ParserOption;

typedef struct {
  char *short_name;
  char *long_name;
  char *value;
} ParserResult;

typedef struct {
  ParserOption *options;
  ParserResult *results;
} Parser;

Parser *init_parser(ParserOption *options);
