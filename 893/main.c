#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

int daysInYear(int year)
{
    return isLeapYear(year) ? 366 : 365;
}

int dayOfYear(struct date *date1)
{
    int i, sum = 0;
    for (i = 1; i < date1->month; i++)
    {
        sum += daysInMonth(date1->year, i);
    }
    sum += date1->day;
    return sum;
}

struct date *addDays(struct date *date1, unsigned long offset)
{
    int remainingDaysThisYear = daysInYear(date1->year) - dayOfYear(date1);
    while (offset >= remainingDaysThisYear + 1)
    {
        offset -= remainingDaysThisYear + 1;
        date1->day = 1;
        date1->month = 1;
        date1->year += 1;
        remainingDaysThisYear = daysInYear(date1->year) - dayOfYear(date1);
    }

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
int main()
{
    long offset; /*0~999999999*/
    int day; /*1~31*/
    int month; /*1~12*/
    int year; /*1998~2999*/
    struct date date1, *pDate = &date1;
    scanf("%li %d %d %d", &offset, &day, &month, &year);
    while (!(offset == 0 && day == 0 && month == 0 && year == 0))
    {
        pDate->year = year;
        pDate->month = month;
        pDate->day = day;
        pDate = addDays(pDate, offset);
        printf("%d %d %d\n", pDate->day, pDate->month, pDate->year);
        scanf("%li %d %d %d", &offset, &day, &month, &year);
    }
    return 0;
}
