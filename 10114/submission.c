#include <stdio.h>
#include <stdbool.h>

int main()
{
    float downPayment, loanAmount, previousDepreciationPercentage, newDepreciationPercentage, carValue, monthlyPayment;
    int duration, numDepreciationRecords, i, j, previousMonthNumber, newMonthNumber;
    scanf("%d %f %f %d", &duration, &downPayment, &loanAmount, &numDepreciationRecords);
    while (duration >= 0)
    {
        /* initial depreciation record (down payment) */
        carValue = loanAmount + downPayment;
        monthlyPayment = loanAmount / duration;
        scanf("%d %f", &previousMonthNumber, &previousDepreciationPercentage);
        carValue *= (1 - previousDepreciationPercentage);
        if (loanAmount < carValue)
        {
            printf("0 months\n");
        }

        for (i = 0; i < numDepreciationRecords - 1; i++)
        {
            scanf("%d %f", &newMonthNumber, &newDepreciationPercentage);
            /* after previous depreciation record */
            for (j = previousMonthNumber + 1; j < newMonthNumber && loanAmount >= carValue; j++)
            {
                carValue *= (1 - previousDepreciationPercentage);
                loanAmount -= monthlyPayment;
                if (loanAmount < carValue)
                {
                    printf("%d month%s\n", j, j > 1 ? "s" : "");
                }
            }
            /* new depreciation record */
            if (loanAmount >= carValue)
            {
                carValue *= (1 - newDepreciationPercentage);
                loanAmount -= monthlyPayment;
                if (loanAmount < carValue)
                {
                    printf("%d month%s\n", j, j > 1 ? "s" : "");
                }
            }
            /* update variables */
            previousMonthNumber = newMonthNumber;
            previousDepreciationPercentage = newDepreciationPercentage;
        }
        /* after last depreciation record ~ until the end of the duration */
        for (j = previousMonthNumber + 1; j <= duration && loanAmount >= carValue; j++)
        {
            carValue *= (1 - previousDepreciationPercentage);
            loanAmount -= monthlyPayment;
            if (loanAmount < carValue)
            {
                printf("%d month%s\n", j, j > 1 ? "s" : "");
            }
        }
        scanf("%d %f %f %d", &duration, &downPayment, &loanAmount, &numDepreciationRecords);
    }
    return 0;
}