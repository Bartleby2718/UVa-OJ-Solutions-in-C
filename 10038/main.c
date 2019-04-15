#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, previous, new, absoluteDifference;
    bool isJolly;
    while (scanf("%d", &n) == 1)
    {
        isJolly = true;
        bool *array = calloc(n - 1, sizeof(bool));
        scanf("%d", &previous);
        for (i = 1; i < n; i++)
        {
            scanf("%d", &new);
            absoluteDifference = abs(new - previous);
            if (absoluteDifference < n)
            {
                array[absoluteDifference] = true;
            } else
            {
                isJolly = false;
            }
            previous = new;
        }
        for (i = 1; i < n; i++)
        {
            if (!isJolly || !array[i])
            {
                isJolly = false;
                break;
            }
        }
        printf(isJolly ? "Jolly\n" : "Not jolly\n");
        free(array);
    }
    return 0;
}