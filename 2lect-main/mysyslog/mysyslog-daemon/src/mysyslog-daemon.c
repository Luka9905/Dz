#include "/home/sa/2lect-main/mysyslog/libmysyslog/include/mysyslog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void read_config(const char* config_path, char* path, int* format, int* driver) {
    FILE* file = fopen(config_path, "r");
    if (!file) {
        perror("Failed to open config file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "path=%s", path)) continue;
        if (sscanf(line, "format=%d", format)) continue;
        if (sscanf(line, "driver=%d", driver)) continue;
    }
    fclose(file);
}

int main() {
    char log_path[256] = "/var/log/mysyslog.log";
    int format = 0, driver = 0;

    read_config("/etc/mysyslog/mysyslog.cfg", log_path, &format, &driver);

    while (1) {
        mysyslog("Debug message", DEBUG, driver, format, log_path);
        sleep(1);
        mysyslog("Info message", INFO, driver, format, log_path);
        sleep(1);
        mysyslog("Warning message", WARN, driver, format, log_path);
        sleep(1);
        mysyslog("Error message", ERROR, driver, format, log_path);
        sleep(1);
        mysyslog("Critical message", CRITICAL, driver, format, log_path);
        sleep(1);
    }

    return 0;
}
