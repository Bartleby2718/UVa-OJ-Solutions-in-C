#include <stdio.h>

int minimumNumberOfSonars(int rows, int columns)
{
    return (rows / 3) * (columns / 3);
}

int main()
{
    int numTestCases;
    scanf("%d\n", &numTestCases);
    int results[numTestCases], rows, columns, result, i, j;
    for (i = 0; i < numTestCases; i++)
    {
        scanf("%d %d\n", &rows, &columns);
        result = minimumNumberOfSonars(rows, columns);
        results[i] = result;
    }
    for (j = 0; j < numTestCases; j++)
    {
        result = results[j];
        printf("%d\n", result);
    }
    return 0;
}