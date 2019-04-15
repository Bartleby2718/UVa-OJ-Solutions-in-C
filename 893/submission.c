#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    long offset; /*0~999,999,999*/
    int day, month, year;
    scanf("%li %d %d %d", &offset, &day, &month, &year);
    while (!(offset == 0 && day == 0 && month == 0 && year == 0))
    { /*took code from https://stackoverflow.com/a/15669430/4370146 after I had reinvented the wheel*/
        struct tm t = {.tm_year=year - 1900, .tm_mon=month - 1, .tm_mday=day};
        t.tm_mday += offset;
        mktime(&t);
        printf("%d %d %d\n", t.tm_mday, t.tm_mon + 1, t.tm_year + 1900);
        scanf("%li %d %d %d", &offset, &day, &month, &year);
    }
    return 0;
}
