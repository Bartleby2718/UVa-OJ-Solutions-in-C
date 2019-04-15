#include <stdio.h>

int minimumNumberOfSonars(int rows, int columns)
{
    return (rows / 3) * (columns / 3);
}

void test(int number, int rows, int columns, int expected)
{
    int actual = minimumNumberOfSonars(rows, columns);
    printf("Test %d: rows(n) = %d, columns(m) = %d\n", number, rows, columns);
    printf("Expected: %d. Actual: %d.\n", expected, actual);
}

int main()
{
//    test(1, 6, 6, 4);
//    test(2, 7, 7, 4);
//    test(3, 9, 13, 12);

    int numTestCases = 0;
    scanf("%d", &numTestCases);
    int results[numTestCases], rows, columns, result;
    for (int i = 0; i < numTestCases; i++)
    {
        scanf("%d %d", &rows, &columns);
        result = minimumNumberOfSonars(rows, columns);
        results[i] = result;
    }
    for (int j = 0; j < numTestCases; j++)
    {
        result = results[j];
        printf("%d\n", result);
    }
    return 0;
}