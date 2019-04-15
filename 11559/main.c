#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int numParticipants; /*  1 ≤ N ≤ 200, */
    long budget; /* 1 ≤ B ≤ 500000 */
    int numHotels; /* 1 ≤ H ≤ 18 */
    int numWeeks; /* 1 ≤ W ≤ 13 */
    int price;  /* 1 ≤ p ≤ 10000 */
    int availableBeds; /* 0 ≤ a ≤ 1000*/
    int i, j;  /*i: index for hotels, j: index for weeks*/
    long cost, minimumCost;
    bool withinBudget, enoughBeds, canStay;
    while (scanf("%d %li %d %d", &numParticipants, &budget, &numHotels, &numWeeks) == 4)
    {
        minimumCost = LONG_MAX;
        for (i = 0; i < numHotels; i++)
        {
            scanf("%d", &price);
            cost = price * numParticipants;
            withinBudget = cost < budget;
            for (j = 0; j < numWeeks; j++)
            {
                scanf("%d", &availableBeds);
                enoughBeds = numParticipants < availableBeds;
                canStay = withinBudget && enoughBeds;
                if (canStay && (cost < minimumCost))
                {
                    minimumCost = cost;
                }
            }
        }
        if (minimumCost == LONG_MAX)
        {
            printf("stay home\n");
        } else
        {
            printf("%li\n", minimumCost);
        }
    }
    return 0;
}