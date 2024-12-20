#include "/home/sa/2lect-main/mysyslog/libmysyslog-text/include/libmysyslog-text.h"
#include <stdio.h>
#include <time.h>

int log_text_format(FILE *file, const char *msg, int level) {
    if (file == NULL || msg == NULL) return -1;

    time_t now = time(NULL);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));

    const char *level_str;
    switch (level) {
        case DEBUG: level_str = "DEBUG"; break;
        case INFO: level_str = "INFO"; break;
        case WARN: level_str = "WARN"; break;
        case ERROR: level_str = "ERROR"; break;
        case CRITICAL: level_str = "CRITICAL"; break;
        default: level_str = "UNKNOWN"; break;
    }

    fprintf(file, "%s [%s] %s\n", timestamp, level_str, msg);
    return 0;
}
