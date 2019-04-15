#include <stdio.h>

struct cartesianCoordinate
{
    long x;
    long y;
};

long getStartingRoot(long long spiralPosition)
{
    long startingRoot;
    for (startingRoot = 1;; startingRoot += 2)
    {
        if ((spiralPosition >= startingRoot * startingRoot) &&
            (spiralPosition < (startingRoot + 2) * (startingRoot + 2)))
        {
            return startingRoot;
        }
    }

}

struct cartesianCoordinate spiralToCartesian(long size, long long spiralPosition)
{
    long startingRoot = getStartingRoot(spiralPosition);
    long line = (size + 1) / 2 + (startingRoot - 1) / 2; /*center + offset*/
    long column = (size + 1) / 2 + (startingRoot - 1) / 2; /*center + offset*/
    long startingSquare = startingRoot * startingRoot;
    long current;
    for (current = startingSquare; current < spiralPosition; current++)
    { /* for odd n, start from n^2, up 1, left n, down n+1, right n+1, up n+1*/
        if (current < startingSquare + 1)
        {
            line++;
        } else if (current < startingSquare + 1 + startingRoot)
        {
            column--;
        } else if (current < startingSquare + 1 + startingRoot + (startingRoot + 1))
        {
            line--;
        } else if (current < startingSquare + 1 + startingRoot + (startingRoot + 1) + (startingRoot + 1))
        {
            column++;
        } else
        {
            line++;
        }
    }
    struct cartesianCoordinate c = {column, line};
    return c;
}

int main()
{
    long size; /* the size of the border of the grid and is an odd number no larger than 100000*/
    long line, column;
    long long spiralPosition;
    struct cartesianCoordinate c;
    scanf("%li %lli", &size, &spiralPosition);
    while (size != 0 || spiralPosition != 0)
    {
        c = spiralToCartesian(size, spiralPosition);
        column = c.x;
        line = c.y;
        printf("Line = %li, column = %li.\n", line, column);
        scanf("%li %lli", &size, &spiralPosition);
    }
    return 0;
}