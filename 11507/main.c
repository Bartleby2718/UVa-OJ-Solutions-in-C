#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getDirection(char currentDirection[3], char bendingDirection[3])
{
    char *answer = calloc(3, sizeof(char));
    if (strcmp(bendingDirection, "No") == 0)
    {
        strcpy(answer, currentDirection);
    } else if (currentDirection[1] == 'x')
    {
        answer[1] = bendingDirection[1];
        answer[0] = (currentDirection[0] == bendingDirection[0]) ? '+' : '-';
    } else if (currentDirection[1] == bendingDirection[1])
    {
        answer[1] = 'x';
        answer[0] = (currentDirection[0] == bendingDirection[0]) ? '-' : '+';

    } else /* perpendicular rotation does not affect the direction */
    {
        strcpy(answer, currentDirection);
    }
    return answer;
}

int main()
{
    long length;
    long i; /*index for bending position*/
    scanf("%li", &length);
    char currentDirection[3], bendingDirection[3], *newDirection;
    while (length != 0)
    {
        strcpy(currentDirection, "+x");
        for (i = length - 1; i > 0; i--)
        {
            scanf("%s", bendingDirection);
            newDirection = getDirection(currentDirection, bendingDirection);
            strcpy(currentDirection, newDirection);
            free(newDirection);
        }
        printf("%s\n", currentDirection);
        scanf("%li", &length);
    }
    return 0;
}