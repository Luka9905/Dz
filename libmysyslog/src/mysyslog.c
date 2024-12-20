#include "/home/sa/2lect-main/mysyslog/libmysyslog/include/mysyslog.h"
#include "/home/sa/2lect-main/mysyslog/libmysyslog-text/include/libmysyslog-text.h"
#include "/home/sa/2lect-main/mysyslog/libmysyslog-json/include/libmysyslog-json.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int mysyslog(const char *msg, int level, int driver, int format, const char *path) {
    if (msg == NULL || path == NULL) {
        fprintf(stderr, "Error: message or path is NULL\n");
        return -1;
    }

    FILE *file = fopen(path, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        return -1;
    }

    int result = -1;

    if (driver == TEXT_DRIVER) {
        result = log_text_format(file, msg, level);
    } else if (driver == JSON_DRIVER) {
        result = log_json_format(file, msg, level);
    } else {
        fprintf(stderr, "Unknown driver\n");
    }

    fclose(file);
    return result;
}
