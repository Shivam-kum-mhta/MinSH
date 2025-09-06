#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;

    // Fetch system info
    if (sysinfo(&info) != 0) {
        perror("sysinfo");
        return 1;
    }

    long uptime = info.uptime; // uptime in seconds

    // Convert uptime to hours, minutes, and seconds
    int hours = uptime / 3600;
    int minutes = (uptime % 3600) / 60;
    int seconds = uptime % 60;

    // Print the formatted uptime
    printf("System Uptime: %d hour(s), %d minute(s), %d second(s)\n", hours, minutes, seconds);

    return 0;
}
