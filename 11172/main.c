#include <stdio.h>

char relation(int first, int second)
{

    if (first > second)
    {
        return '>';
    } else if (first < second)
    {
        return '<';
    } else
    {
        return '=';
    }
}

void test(int first, int second, char expected)
{
    char actual = relation(first, second);
    printf("%d vs %d. Expected: %c. Actual: %c\n", first, second, expected, actual);
}

int main()
{
//    test(10, 20, '<');
//    test(20, 10, '>');
//    test(10, 10, '=');
    int numCases, first, second;
    scanf("%d", &numCases);
    char results[numCases], result;
    for (int i = 0; i < numCases; i++)
    {
        scanf("%d %d", &first, &second);
        result = relation(first, second);
        results[i] = result;
    }
    for (int j = 0; j < numCases ; j++)
    {
        result = results[j];
        printf("%c\n", result);
    }
    return 0;
}