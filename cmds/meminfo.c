#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("meminfo");
        return 1;
    }

    char line[256];
    int count = 0;

    printf("========= Memory Information =========\n");
    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "MemTotal", 8) == 0 ||
            strncmp(line, "MemFree", 7) == 0 ||
            strncmp(line, "MemAvailable", 12) == 0 ||
            strncmp(line, "Buffers", 7) == 0 ||
            strncmp(line, "Cached", 6) == 0) {
            printf("%s", line);
            count++;
        }
        if (count >= 5) break;  // only show the main 5 fields
    }

    fclose(fp);
    return 0;
}
