TIME CONVERSION

#include <stdio.h>
int main() {
    char timeStr[11];
    int h, m, s;
    char meridian[3];
    scanf("%s", timeStr);
    sscanf(timeStr, "%2d:%2d:%2d%2s", &h, &m, &s, meridian);
    
    if (strcmp(meridian, "PM") == 0 && h != 12) {
        h += 12;
    } else if (strcmp(meridian, "AM") == 0 && h == 12) {
        h = 0;
    }

    printf("%02d:%02d:%02d\n", h, m, s);

    return 0;
}
....................................................................................
