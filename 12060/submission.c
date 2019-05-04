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
