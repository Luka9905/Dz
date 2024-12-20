#ifndef LIBMYSYSLOG_JSON_H
#define LIBMYSYSLOG_JSON_H

#include <stdio.h>

#define DEBUG     0
#define INFO      1
#define WARN      2
#define ERROR     3
#define CRITICAL  4

int log_json_format(FILE *file, const char *msg, int level);

#endif
