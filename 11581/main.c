#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void print3X3Grid(int *array)
{
    int i, j;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            printf("%d\t", array[i * 3 + j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

int *sumOfAdjacentCells(int *array)
{
    int *newArray = calloc(9, sizeof(int));
    int i, j, sum;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            sum = 0;
            if (i > 0)
            {
                sum += array[(i - 1) * 3 + j];
            }
            if (i < 2)
            {
                sum += array[(i + 1) * 3 + j];
            }
            if (j > 0)
            {
                sum += array[i * 3 + (j - 1)];
            }
            if (j < 2)
            {
                sum += array[i * 3 + (j + 1)];
            }
            newArray[i * 3 + j] = sum % 2;
        }
    }
    return newArray;
}

void testSumOfAdjacentCells()
{
    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, *p;
    p = sumOfAdjacentCells(a);
    print3X3Grid(p);
}

bool checkAllZeros(int *array)
{
    int i, j;
    bool allZeros = true;
    for (i = 0; i < 3 && allZeros; ++i)
    {
        for (j = 0; j < 3 && allZeros; ++j)
        {
            allZeros = array[i * 3 + j] == 0;
        }
    }
    return allZeros;
}

void testCheckAllZeros()
{
    int a[9] = {1, 0, 1, 0, 0, 0, 1, 0, 1};
    printf("%s", checkAllZeros(a) ? "true" : "false");
    int b[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    printf("%s", checkAllZeros(b) ? "true" : "false");
}

int main()
{
    int numTestCases, i, j, k, digit, grid[9], *p;
    char c;
    scanf("%d", &numTestCases);
    /* consume newline character */
    getchar();
    for (i = 0; i < numTestCases; ++i)
    {
        /* consume newline character */
        getchar();
        for (j = 0; j < 3; ++j)
        {
            for (k = 0; k < 3; ++k)
            {
                c = getchar();
                digit = c - 48;
                grid[j * 3 + k] = digit;
            }
            /* consume newline character */
            getchar();
        }
        p = grid;
        j = -1;
        bool allZeros = checkAllZeros(p);
        while (!allZeros)
        {
            ++j;
            p = sumOfAdjacentCells(p);
            allZeros = checkAllZeros(p);
        }
        printf("%d\n", j);
    }
    return 0;
}