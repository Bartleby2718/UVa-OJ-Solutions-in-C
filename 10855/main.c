#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printGrid(char *square, int size)
{
    int i, j;
    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < size; ++j)
        {
            putchar(square[i * size + j]);
        }
        putchar('\n');
    }
    putchar('\n');
}


int countAppearances(const char *bigSquare, int bigSize, const char *smallSqaure, int smallSize)
{
    int i, j, k, l, sum = 0;
    bool same;
    char bigChar, smallChar;
    for (i = 0; i < bigSize - smallSize + 1; ++i)
    {
        for (j = 0; j < bigSize - smallSize + 1; ++j)
        {
            same = true;
            for (k = 0; k < smallSize && same; ++k)
            {
                for (l = 0; l < smallSize && same; ++l)
                {
                    bigChar = bigSquare[(i + k) * bigSize + (j + l)];
                    smallChar = smallSqaure[k * smallSize + l];
                    same = bigChar == smallChar;
                }
            }
            if (same)
            {
                ++sum;
            }
        }
    }
    return sum;
}

char *rotateOnce(char *square, int size)
{
    int i, j;
    char *newSquare = malloc(sizeof(char) * (size * size + 1));
    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < size; ++j)
        {
            newSquare[j * size + (size - 1 - i)] = square[i * size + j];
        }
    }
    newSquare[size * size] = '\0';
    return newSquare;
}

void testRotateOnce(char *square, int size)
{
    int i;
    for (i = 0; i < 4; ++i, square = rotateOnce(square, size))
    {
        printGrid(square, size);
    }
}

int main()
{
    int big, small, i, appearances[4];
    char *grid;
    scanf("%d %d", &big, &small);
    while (!(big == 0 && small == 0))
    {
        char bigSquare[big][big], smallSquare[small][small];
        for (i = 0; i < big; ++i)
        {
            scanf("%s", bigSquare[i]);
        }
        for (i = 0; i < small; ++i)
        {
            scanf("%s", smallSquare[i]);
        }
        grid = (char *) smallSquare;
        for (i = 0; i < 4; ++i, grid = rotateOnce(grid, small))
        {
            appearances[i] = countAppearances((char *) bigSquare, big, grid, small);
        }
        printf("%d %d %d %d\n", appearances[0], appearances[1], appearances[2], appearances[3]);
        scanf("%d %d", &big, &small);
    }
    return 0;
}