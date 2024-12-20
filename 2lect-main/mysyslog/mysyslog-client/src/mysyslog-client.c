#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "/home/sa/2lect-main/mysyslog/libmysyslog/include/mysyslog.h"

int main(int argc, char *argv[]) {
    char *message = NULL;
    int level = INFO;
    int driver = TEXT_DRIVER;
    int format = TEXT_FORMAT;
    char *path = NULL;

    int opt;
    while ((opt = getopt(argc, argv, "m:l:d:f:p:")) != -1) {
        switch (opt) {
            case 'm':
                message = optarg;
                break;
            case 'l':
                if (strcmp(optarg, "DEBUG") == 0) level = DEBUG;
                else if (strcmp(optarg, "INFO") == 0) level = INFO;
                else if (strcmp(optarg, "WARN") == 0) level = WARN;
                else if (strcmp(optarg, "ERROR") == 0) level = ERROR;
                else if (strcmp(optarg, "CRITICAL") == 0) level = CRITICAL;
                else fprintf(stderr, "Unknown log level: %s\n", optarg);
                break;
            case 'd':
                driver = atoi(optarg);
                break;
            case 'f':
                format = atoi(optarg);
                break;
            case 'p':
                path = optarg;
                break;
            default:
                fprintf(stderr, "Usage: %s -m <message> -l <level> -d <driver> -f <format> -p <path>\n", argv[0]);
                return EXIT_FAILURE;
        }
    }

    if (message == NULL || path == NULL) {
        fprintf(stderr, "Message and path are required\n");
        return EXIT_FAILURE;
    }

    if (mysyslog(message, level, driver, format, path) != 0) {
        fprintf(stderr, "Failed to write to log\n");
        return EXIT_FAILURE;
    }

    printf("Message logged successfully to %s\n", path);
    return EXIT_SUCCESS;
}

