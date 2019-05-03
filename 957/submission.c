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

int main()
{
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