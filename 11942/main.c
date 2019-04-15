#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numGroups; /*0 < N < 20*/
    int i; /*index for groups*/
    int previousLength, newLength; /* each distinct, positive integer less than 100*/
    int j; /*index for beard lengths*/
    bool increasing, ordered;
    scanf("%d", &numGroups);
    printf("Lumberjacks:\n");
    for (i = 0; i < numGroups; i++)
    {
        scanf("%d", &previousLength);
        scanf("%d", &newLength);
        increasing = newLength > previousLength;
        ordered = true;
        previousLength = newLength;
        for (j = 2; j < 10; j++)
        {
            scanf("%d", &newLength);
            if (increasing != (newLength > previousLength))
            {
                ordered = false;
            }
            previousLength = newLength;
        }
        printf(ordered ? "Ordered\n" : "Unordered\n");
    }
    return 0;
}