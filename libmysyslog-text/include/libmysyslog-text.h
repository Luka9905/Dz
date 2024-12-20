#ifndef LIBMYSYSLOG_TEXT_H
#define LIBMYSYSLOG_TEXT_H

#include <stdio.h>

#define DEBUG     0
#define INFO      1
#define WARN      2
#define ERROR     3
#define CRITICAL  4

extern int log_text_format(FILE *file, const char *msg, int level);

#endif
