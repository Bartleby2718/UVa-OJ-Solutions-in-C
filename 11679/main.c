#include <stdio.h>
#include <stdbool.h>

int main()
{
    int numBanks; /* 1 ≤ B ≤ 20 */
    int numDebentures; /* 1 ≤ N ≤ 20 */
    int reserve; /* 0 ≤ R_i ≤ 10000 */
    int debtorBank; /* 1 ≤ D ≤ B */
    int creditorBank; /* 1 ≤ C ≤ B, D != C */
    int debentureValue; /* 1 ≤ V ≤ 10000 */
    int i, j; /* i: index for bank, j: index for debenture */
    bool needBailout;
    scanf("%d %d", &numBanks, &numDebentures);
    while (!(numBanks == 0 && numDebentures == 0))
    {
        needBailout = false;
        long balances[numBanks];
        for (i = 0; i < numBanks; i++)
        {
            scanf("%d", &reserve);
            balances[i] = reserve;
        }
        for (j = 0; j < numDebentures; j++)
        {
            scanf("%d %d %d", &debtorBank, &creditorBank, &debentureValue);
            balances[debtorBank - 1] -= debentureValue;
            balances[creditorBank - 1] += debentureValue;
        }
        for (i = 0; i < numBanks; i++)
        {
            if (balances[i] < 0)
            {
                needBailout = true;
                break;
            }
        }
        printf(needBailout ? "N\n" : "S\n");
        scanf("%d %d", &numBanks, &numDebentures);
    }
    return 0;
}