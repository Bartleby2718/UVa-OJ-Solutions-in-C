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

void testGetAnswer(int *durations, int numTracks, int desiredSum, int *expectedTracks, int expectedNumTracks)
{
    Answer *actual = getAnswer(durations, numTracks, desiredSum);
    printf("Make %d with {%d", desiredSum, durations[0]);
    int i;
    for (i = 1; i < numTracks; ++i)
    {
        printf(", %d", durations[i]);
    }
    printf("}: expected ");
    printf("{%d", expectedTracks[0]);
    for (i = 1; i < expectedNumTracks; ++i)
    {
        printf(", %d", expectedTracks[i]);
    }
    printf("}, got ");
    printf("{%d", actual->durations[0]);
    for (i = 1; i < actual->numTracks; ++i)
    {
        printf(", %d", actual->durations[i]);
    }
    printf("}.\n");
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

void testPrintOutput()
{
    int p[] = {10, 23, 1, 2, 3, 4, 5, 7};
    Answer a = {p, 8};
    printOutput(&a);
}

int main()
{

    int a1[] = {1, 3, 4}, b1[] = {1, 4};
    testGetAnswer(a1, 3, 5, b1, 2);
    int a2[] = {9, 8, 4, 2}, b2[] = {8, 2};
    testGetAnswer(a2, 4, 10, b2, 2);
    int a3[] = {10, 5, 7, 4}, b3[] = {10, 5, 4};
    testGetAnswer(a3, 4, 20, b3, 3);
    int a4[] = {10, 23, 1, 2, 3, 4, 5, 7}, b4[] = {10, 23, 1, 2, 3, 4, 5, 7};
    testGetAnswer(a4, 8, 90, b4, 8);
    int a5[] = {4, 10, 44, 43, 12, 9, 8, 2}, b5[] = {4, 10, 12, 9, 8, 2};
    testGetAnswer(a5, 8, 45, b5, 6);

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
