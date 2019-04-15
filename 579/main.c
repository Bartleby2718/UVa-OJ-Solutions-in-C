#include <stdio.h>

int main()
{
    int hours, minutes;
    float hoursAngle, minutesAngle, difference;
    scanf("%d:%d", &hours, &minutes);
    while (!(hours == 0 && minutes == 0))
    {
        hoursAngle = 30 * hours + 0.5 * minutes; /*30 degrees in 1 hour = 60 minutes*/
        minutesAngle = 6 * minutes;  /*360 degrees in 1 hour = 60 minutes*/
        difference = hoursAngle - minutesAngle + 360;
        while (difference > 360)
        {
            difference -= 360;
        }
        if (difference > 180)
        {
            difference = 360 - difference;
        }
        printf("%.3f\n", difference);
        scanf("%d:%d", &hours, &minutes);
    }
    return 0;
}