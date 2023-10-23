#include <stdio.h>
#include <time.h>

int main(void) {
int year;
scanf("%d", &year);
year = year - 1900;
struct tm t;
t.tm_sec = 0;
t.tm_min = 0;
t.tm_mday = 1;
t.tm_mon = 0;
t.tm_year = year;
t.tm_yday = 0;
t.tm_isdst = -1;
time_t k = mktime(&t);
int count = 0;
while (t.tm_year == year) {

    // printf("%d  %d\n", t.tm_mon, t.tm_mday);
    if (t.tm_wday == 0 ||
        t.tm_wday == 6 ||
        (t.tm_yday + 1) == 1 ||
        (t.tm_yday + 1) == 2 ||
        (t.tm_yday + 1) == 4 ||
        (t.tm_yday + 1) == 8 ||
        (t.tm_yday + 1) == 16 ||
        (t.tm_yday + 1) == 32 ||
        (t.tm_yday + 1) == 64 ||
        (t.tm_yday + 1) == 128 ||
        (t.tm_yday + 1) == 256) {
            count += 1;
        }
    t.tm_mday += 1;
    t.tm_isdst = -1;
    k = mktime(&t);
}
printf("%d\n", count);

return 0;
}
