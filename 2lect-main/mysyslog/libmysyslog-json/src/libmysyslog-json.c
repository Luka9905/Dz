#include "/home/sa/2lect-main/mysyslog/libmysyslog-json/include/libmysyslog-json.h"
#include <stdio.h>
#include <time.h>

int log_json_format(FILE *file, const char *msg, int level) {
    if (file == NULL || msg == NULL) return -1;

    time_t now = time(NULL);

    const char *level_str;
    switch (level) {
        case DEBUG: level_str = "DEBUG"; break;
        case INFO: level_str = "INFO"; break;
        case WARN: level_str = "WARN"; break;
        case ERROR: level_str = "ERROR"; break;
        case CRITICAL: level_str = "CRITICAL"; break;
        default: level_str = "UNKNOWN"; break;
    }

    fprintf(file, "{\"timestamp\":%ld,\"level\":\"%s\",\"message\":\"%s\"}\n", now, level_str, msg);
    return 0;
}

