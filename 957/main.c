#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct answer
{
    long numPopes;
    long startingYear;
    long endingYear;
} Answer;

Answer *getAnswer(long periodLength, long numPopes, long *years)
{
    Answer *p = calloc(1, sizeof(Answer *));
    long i, j, startingYear;
    long *numPopesInPeriod, arrNumPopes[numPopes];
    numPopesInPeriod = arrNumPopes;
    memset(arrNumPopes, 0, numPopes * sizeof(long));
    long *endingYears, arrEndingYears[numPopes];
    memset(arrEndingYears, 0, numPopes * sizeof(long));
    endingYears = arrEndingYears;
    long index = -1, maxNumPopes = -1, oldestEndingYear = -1;
    for (i = 0; i < numPopes; ++i)
    {
        startingYear = years[i];
        for (j = i; j < numPopes; ++j)
        {
            long yearInConsideration = years[j];
            if (yearInConsideration >= startingYear && yearInConsideration < startingYear + periodLength)
            {
                ++numPopesInPeriod[i];
                endingYears[i] = yearInConsideration;
            }
            else if (yearInConsideration >= startingYear + periodLength)
            {
                break;
            }
        }
        if (numPopesInPeriod[i] > maxNumPopes)
        {
            index = i;
            maxNumPopes = numPopesInPeriod[i];
            oldestEndingYear = endingYears[i];
        }
    }
    Answer a = {maxNumPopes, years[index], oldestEndingYear};
    *p = a;
    return p;
}

void testGetAnswer()
{
    long periodLength = 5;
    long numPopes = 20;
    long years[] = {1, 2, 3, 6, 8, 12, 13, 13, 15, 16, 17, 18, 19, 20, 20, 21, 25, 26, 30, 31};
    Answer *actual = getAnswer(periodLength, numPopes, years);
    Answer expected = {6, 16, 20};
    printf("20 popes: {1, 2, 3, 6, 8, 12, 13, 13, 15, 16, 17, 18, 19, 20, 20, 21, 25, 26, 30, 31}");
    printf(" in the period of 5 years\n");
    printf("expected: %ld popes from %ld to %ld.\n", expected.numPopes, expected.startingYear, expected.endingYear);
    printf("got: %ld popes from %ld to %ld.\n", actual->numPopes, actual->startingYear, actual->endingYear);
    free(actual);
}


int main()
{
/*
    testGetAnswer();
    return 0;
*/
    long periodLength;
    while (scanf("%ld", &periodLength) == 1)
    {
        long numPopes;
        scanf("%ld", &numPopes);
        long i, years[numPopes];
        for (i = 0; i < numPopes; ++i)
        {
            scanf("%ld", &years[i]);
        }
        Answer *a = getAnswer(periodLength, numPopes, years);
        printf("%ld %ld %ld\n", a->numPopes, a->startingYear, a->endingYear);
        free(a);
    }
    return 0;
}