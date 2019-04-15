#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


struct date
{
    int year;
    int month;
    int day;
};

bool isLeapYear(int year)
{
    if (year % 400 == 0)
    {
        return true;
    } else if (year % 100 == 0)
    {
        return false;
    } else if (year % 4 == 0)
    {
        return true;
    } else
    {
        return false;
    }
}

int daysInMonth(int year, int month)
{
    if (month == 2)
    {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    } else
    {
        return 31;
    }
}

struct date *addDays(struct date *date1, unsigned int offset)
{
    int remainingDaysThisMonth = daysInMonth(date1->year, date1->month) - date1->day;
    while (offset >= remainingDaysThisMonth + 1)
    {
        offset -= remainingDaysThisMonth + 1;
        date1->day = 1;
        date1->month += 1;
        if (date1->month > 12)
        {
            date1->month = 1;
            date1->year += 1;
        }
        remainingDaysThisMonth = daysInMonth(date1->year, date1->month) - date1->day;
    }
    if (offset > 0)
    {
        date1->day += offset;
    }
    return date1;
}

struct date *stringToDate(char *format)
{
    int year, month, day;
    char yearString[5] = "";
    strncpy(yearString, format + 4, 4);
    sscanf(yearString, "%d", &year);

    char monthString[3] = "";
    strncpy(monthString, format, 2);
    sscanf(monthString, "%d", &month);

    char dayString[3] = "";
    strncpy(dayString, format + 2, 2);
    sscanf(dayString, "%d", &day);

    struct date date1 = {year, month, day};
    struct date *pDate = malloc(3 * sizeof(int));
    *pDate = date1;
    return pDate;
}

char *zodiacSign(struct date *date1)
{
    if ((date1->month == 1 && date1->day >= 21) || (date1->month == 2 && date1->day < 20))
    {
        return "aquarius";
    } else if ((date1->month == 2 && date1->day >= 20) || (date1->month == 3 && date1->day < 21))
    {
        return "pisces";
    } else if ((date1->month == 3 && date1->day >= 21) || (date1->month == 4 && date1->day < 21))
    {
        return "aries";
    } else if ((date1->month == 4 && date1->day >= 21) || (date1->month == 5 && date1->day < 22))
    {
        return "taurus";
    } else if ((date1->month == 5 && date1->day >= 22) || (date1->month == 6 && date1->day < 22))
    {
        return "gemini";
    } else if ((date1->month == 6 && date1->day >= 22) || (date1->month == 7 && date1->day < 23))
    {
        return "cancer";
    } else if ((date1->month == 7 && date1->day >= 23) || (date1->month == 8 && date1->day < 22))
    {
        return "leo";
    } else if ((date1->month == 8 && date1->day >= 22) || (date1->month == 9 && date1->day < 24))
    {
        return "virgo";
    } else if ((date1->month == 9 && date1->day >= 24) || (date1->month == 10 && date1->day < 24))
    {
        return "libra";
    } else if ((date1->month == 10 && date1->day >= 24) || (date1->month == 11 && date1->day < 23))
    {
        return "scorpio";
    } else if ((date1->month == 11 && date1->day >= 23) || (date1->month == 12 && date1->day < 23))
    {
        return "sagittarius";
    } else
    {
        return "capricorn";
    }
}

int main()
{
    int numDatasets;
    scanf("%d", &numDatasets);
    int i;
    char format[9], sign[12];
    struct date *pDate;
    for (i = 1; i <= numDatasets; i++)
    {
        scanf("%s", format);
        pDate = stringToDate(format);
        pDate = addDays(pDate, 280);
        strcpy(sign, zodiacSign(pDate));
        printf("%d %02d/%02d/%04d %s\n", i, pDate->month, pDate->day, pDate->year, sign);
        free(pDate);
    }
    return 0;
}