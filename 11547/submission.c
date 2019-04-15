#include <stdio.h>
#include <stdlib.h>

int getAnswer(int n)
{
    return (abs(((n * 567) / 9 + 7492) * 235 / 47 - 498) / 10) % 10;
}

int main()
{
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