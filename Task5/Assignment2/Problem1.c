#include <stdio.h>

int main() {
    int hours, minutes, seconds, time;
    printf("Enter time in format [hh:mm:ss]: ");
    scanf("%d:%d:%d", &hours, &minutes, &seconds);
    time = hours * 3600 + minutes * 60 + seconds;
    printf("Time in format [hh:mm:ss]: %02d:%02d:%02d\n", time / 3600, (time % 3600) / 60, time % 60);

    return 0;
}