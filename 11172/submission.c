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
int main()
{
    int numCases, first, second, i, j;
    scanf("%d", &numCases);
    char results[numCases], result;
    for (i = 0; i < numCases; i++)
    {
        scanf("%d %d", &first, &second);
        result = relation(first, second);
        results[i] = result;
    }
    for (j = 0; j < numCases; j++)
    {
        result = results[j];
        printf("%c\n", result);
    }
    return 0;
}