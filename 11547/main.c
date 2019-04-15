#include <stdio.h>
#include <stdlib.h>

int getAnswer(int n)
{
    return (abs(((n * 567) / 9 + 7492) * 235 / 47 - 498) / 10) % 10;
}

void testGetAnswer(int n, int expected)
{
    int actual = getAnswer(n);
    printf("%d: expected %d, got %d\n", n, expected, actual);
}

int main()
{
//    testGetAnswer(637, 1);
//    testGetAnswer(-120, 3);

    int numCases, i, n, answer;
    scanf("%d", &numCases);
    for (i = 0; i < numCases; i++)
    {
        scanf("%d", &n);
        answer = getAnswer(n);
        printf("%d\n", answer);
    }
    return 0;
}