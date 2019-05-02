#include <stdio.h>
#include <stdlib.h>

typedef struct answers
{
    long lower;
    long higher;
} Answer;

Answer *getAnswer(long *prices, unsigned numBooks, long money)
{
    /* always possible to find a solution
     * If there are multiple solutions, print the solution that minimizes the
     * difference between the prices i and j */
    Answer *p = malloc(sizeof(Answer *));
    unsigned i, j;
    long price1, price2;
    for (i = 0; i < numBooks; ++i)
    {
        for (j = i + 1; j < numBooks; ++j)
        {
            price1 = prices[i];
            price2 = prices[j];
            if (price1 + price2 == money)
            {
                if (price1 >= price2 && price2 >= p->lower)
                {
                    p->higher = price1;
                    p->lower = price2;
                }
                else if (price1 < price2 && price1 >= p->lower)
                {
                    p->lower = price1;
                    p->higher = price2;
                }
            }
        }
    }
    return p;
}

int main()
{
    unsigned numBooks; /* 2 <= N <= 10,000 */
    while (scanf("%u", &numBooks) != EOF)
    {
        long prices[numBooks]; /* each < 1,000,001 */
        unsigned i;
        for (i = 0; i < numBooks; ++i)
        {
            scanf("%li", &prices[i]);
        }
        long money;
        scanf("%li", &money);
        Answer *answer = getAnswer(prices, numBooks, money);
        printf("Peter should buy books whose prices are %li and %li.\n\n", answer->lower, answer->higher);
    }
    return 0;
}
