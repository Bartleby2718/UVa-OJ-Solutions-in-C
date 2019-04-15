#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int getDegrees(int initial, int first, int second, int third)
{
    int sum = 0;
    sum += 360 * 2;

    if (initial == first)
    {
        sum += 360;
    } else
    {
        sum += ((initial - first + 40) % 40) * 9;
    }

    sum += 360;

    if (first == second)
    {
        sum += 360;
    } else
    {
        sum += ((second - first + 40) % 40) * 9;
    }

    if (second == third)
    {
        sum += 360;
    } else
    {
        sum += ((second - third + 40) % 40) * 9;
    }
    return sum;
}

int main()
{
    int initial, first, second, third, result;
    bool reachedEnd = false;
    scanf("%d %d %d %d", &initial, &first, &second, &third);
    result = getDegrees(initial, first, second, third);
    printf("%d", result);
    reachedEnd = (initial == 0 && first == 0 && second == 0 && third == 0);
    while (!reachedEnd)
    {
        scanf("%d %d %d %d", &initial, &first, &second, &third);
        result = getDegrees(initial, first, second, third);
        printf("\n%d", result);
        reachedEnd = (initial == 0 && first == 0 && second == 0 && third == 0);
    }
    return 0;
}

