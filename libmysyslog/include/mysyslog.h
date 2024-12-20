#ifndef MYSYSLOG_H
#define MYSYSLOG_H

#include <stdio.h>

#define DEBUG     0
#define INFO      1
#define WARN      2
#define ERROR     3
#define CRITICAL  4

#define TEXT_FORMAT   0
#define JSON_FORMAT   1

#define TEXT_DRIVER   0
#define JSON_DRIVER   1

int mysyslog(const char *msg, int level, int driver, int format, const char *path);

#endif
