#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct answers
{
    int *durations;
    int numTracks;
} Answer;

int getSum(int *array, int numElements)
{
    int i, sum = 0;
    for (i = 0; i < numElements; ++i)
    {
        sum += array[i];
    }
    return sum;
}

Answer *getAnswer(int *durations, int numTracks, int desiredSum)
{
    Answer *pAnswer = malloc(sizeof(Answer));
    Answer notFound = {NULL, 0};

    /* case 1: invalid input*/
    if (durations == NULL || numTracks <= 0 || desiredSum <= 0)
    {
        *pAnswer = notFound;
        return pAnswer;
    }

    int i, duration, sum = 0, min = INT_MAX;
    for (i = 0; i < numTracks; ++i)
    {
        duration = durations[i];
        sum += duration;
        if (duration < min)
        {
            min = duration;
        }
    }
    if (sum <= desiredSum)  /* case 2: sum of all elements equals desiredSum */
    {
        Answer answer = {durations, numTracks};
        *pAnswer = answer;
        return pAnswer;
    }
    else if (min > desiredSum) /* case 3: every element exceeds desiredSum */
    {
        *pAnswer = notFound;
        return pAnswer;
    }
    else  /* case 4: otherwise, compare two elements */
    {
        /* choice 1: include the first element */
        Answer *pAnswer1;
        if (durations[0] > desiredSum)
        {
            pAnswer1 = malloc(sizeof(Answer));
            *pAnswer1 = notFound;
        }
        else
        {
            pAnswer1 = getAnswer(durations + 1, numTracks - 1, desiredSum - durations[0]);
            int *durations1;
            if (pAnswer1->durations == NULL)
            {
                durations1 = malloc(sizeof(int));
            }
            else
            {
                durations1 = malloc((pAnswer1->numTracks + 1) * sizeof(int));
                memcpy(durations1 + 1, pAnswer1->durations, pAnswer1->numTracks * sizeof(int));
            }
            durations1[0] = durations[0];  /* copy the "first" element*/
            pAnswer1->durations = durations1;
            ++(pAnswer1->numTracks);  /* +1 for the "first" element*/
        }

        /* choice 2: exclude the first element */
        Answer *pAnswer2 = getAnswer(durations + 1, numTracks - 1, desiredSum);

        /* compare choice 1 & choice 2*/
        int sum1 = getSum(pAnswer1->durations, pAnswer1->numTracks);
        int sum2 = getSum(pAnswer2->durations, pAnswer2->numTracks);

        if (sum2 <= 0 && sum1 > 0)
        {
            return pAnswer1;
        }
        else if (sum1 <= 0 && sum2 > 0)
        {
            return pAnswer2;
        }
        else if (sum1 > 0 && sum2 > 0)
        {
            return (sum1 >= sum2) ? pAnswer1 : pAnswer2;
        }
        else
        {
            *pAnswer = notFound;
            return pAnswer;
        }
    }
}

void printOutput(Answer *a1)
{
    int i, duration, sum = 0;
    for (i = 0; i < a1->numTracks; ++i)
    {
        duration = a1->durations[i];
        printf("%d ", duration);
        sum += duration;
    }
    printf("sum:%d\n", sum);
}

int main()
{
    int desiredSum;
    while (scanf("%d", &desiredSum) == 1)
    {
        int numTracks; /* number of tracks on the CD does not exceed 20 */
        scanf("%d", &numTracks);
        int durations[numTracks], i;
        for (i = 0; i < numTracks; ++i)
        {
            scanf("%d", &durations[i]);
        }
        Answer *a = getAnswer(durations, numTracks, desiredSum);
        printOutput(a);
    }
    return 0;
}
