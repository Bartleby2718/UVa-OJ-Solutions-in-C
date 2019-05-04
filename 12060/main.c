#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct mixedFraction
{
    int wholeNumber;
    int numerator;
    int denominator;
} MixedFraction;

int getGcd(long a, long b)
{
    if (a < 0)
    {
        a = -a;
    }
    long temp;
    while (b != 0)
    {
        temp = a % b;

        a = b;
        b = temp;
    }
    return (int) a;
}

MixedFraction *getAverage(int *ints, int numInts)
{
    MixedFraction *p = malloc(sizeof(MixedFraction *));
    long sum = 0;
    int i;
    for (i = 0; i < numInts; ++i)
    {
        sum += ints[i];
    }
    int gcd = getGcd(sum, numInts);
    bool isNegative = sum < 0;
    if (isNegative)
    {
        sum = -sum;
    }
    /* the following three variables are forced to be nonnegative */
    int wholeNumber = sum / numInts;
    int numerator = (sum % numInts) / gcd;
    int denominator = numInts / gcd;
    MixedFraction mf = {isNegative ? -wholeNumber : wholeNumber,
                        (isNegative && wholeNumber == 0) ? -numerator : numerator,
                        numerator == 0 ? 0 : denominator};

    *p = mf;
    return p;
}

void testGetAverage(int *ints, int numInts, int wholeNumber, int numerator, int denominator)
{
    MixedFraction *mf = getAverage(ints, numInts);
    int i;
    printf("{%d", *ints);
    for (i = 1; i < numInts; ++i)
    {
        printf(", %d", ints[i]);
    }
    printf("}: expected %d %d/%d, got %d %d/%d.\n", wholeNumber, numerator, denominator,
           mf->wholeNumber, mf->numerator, mf->denominator);
}

int getNumDigits(int int1)
{
    if (int1 < 0)
    {
        int1 = -int1;
    }
    int numDigits = 1;
    while (int1 >= 10)
    {
        int1 /= 10;
        ++numDigits;
    }
    return numDigits;
}

void printMixedFraction(int wholeNumber, int numerator, int denominator)
{
    int i;
    if (numerator == 0)
    {
        if (wholeNumber >= 0)
        {
            printf("%d\n", wholeNumber);
        }
        else
        {
            printf("-% d\n", -wholeNumber);
        }
    }
    else
    {
        int numNumeratorDigits = getNumDigits(numerator);
        int numDenominatorDigits = getNumDigits(denominator);
        int numHyphens = numNumeratorDigits >= numDenominatorDigits ? numNumeratorDigits : numDenominatorDigits;
        if (wholeNumber == 0)
        {
            if (numerator > 0)
            {
                printf("%*d\n", numHyphens, numerator);
                for (i = 0; i < numHyphens; ++i)
                {
                    putchar('-');
                }
                putchar('\n');
                printf("%*d\n", numHyphens, denominator);
            }
            else
            {
                printf("%*d\n", numHyphens + 2, -numerator);
                printf("- ");
                for (i = 0; i < numHyphens; ++i)
                {
                    putchar('-');
                }
                putchar('\n');
                printf("%*d\n", numHyphens + 2, denominator);
            }
        }
        else
        {
            int numWholeNumberDigits = getNumDigits(wholeNumber);
            if (wholeNumber > 0)
            {
                printf("%*d\n", numWholeNumberDigits + numHyphens, numerator);
                printf("%d", wholeNumber);
                for (i = 0; i < numHyphens; ++i)
                {
                    putchar('-');
                }
                putchar('\n');
                printf("%*d\n", numWholeNumberDigits + numHyphens, denominator);
            }
            else
            {
                printf("%*d\n", numWholeNumberDigits + 2 + numHyphens, numerator);
                printf("-% d", -wholeNumber);
                for (i = 0; i < numHyphens; ++i)
                {
                    putchar('-');
                }
                putchar('\n');
                printf("%*d\n", numWholeNumberDigits + 2 + numHyphens, denominator);
            }
        }
    }
}

int main()
{
    /*
    printMixedFraction(2, 0, 0);
    printMixedFraction(-2, 0, 0);
    printMixedFraction(2, 1, 3);
    printMixedFraction(5, 1, 2);
    printMixedFraction(-2, 1, 3);
    printMixedFraction(1, 3, 10);
    printMixedFraction(0, 1, 5);
    printMixedFraction(0, -1, 5);
    int numInts1[] = {1, 2, 3};
    testGetAverage(numInts1, 3, 2, 0, 0);
    int numInts2[] = {-1, -2, -3};
    testGetAverage(numInts2, 3, -2, 0, 0);
    int numInts3[] = {1, 2, 4};
    testGetAverage(numInts3, 3, 2, 1, 3);
    int numInts4[] = {2, 4, 6, 10};
    testGetAverage(numInts4, 4, 5, 1, 2);
    int numInts5[] = {-1, -2, -4};
    testGetAverage(numInts5, 3, -2, 1, 3);
    int numInts6[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 4};
    testGetAverage(numInts6, 10, 1, 3, 10);
    int numInts7[] = {1, -1, 1, -1, 1, -1, -1, 1, 1, 1};
    testGetAverage(numInts7, 10, 0, 1, 5);
    int numInts8[] = {1, -1, 1, -1, 1, -1, -1, 1, 1, -3};
    testGetAverage(numInts8, 10, 0, -1, 5);
    */
    int numInts, i, index = 0;
    scanf("%d", &numInts);
    while (numInts != 0)
    {
        ++index;
        int ints[numInts];
        for (i = 0; i < numInts; ++i)
        {
            scanf("%d", &ints[i]);
        }
        printf("Case %d:\n", index);
        MixedFraction *pmf = getAverage(ints, numInts);
        printMixedFraction(pmf->wholeNumber, pmf->numerator, pmf->denominator);
        scanf("%d", &numInts);
    }
    return 0;
}