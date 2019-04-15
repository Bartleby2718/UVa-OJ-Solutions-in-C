#include <stdio.h>

int main()
{
    int t; /* T < 30, the number of test cases */
    int i; /* index for test cases*/
    int n; /* 0 < N < 50, the number of walls */
    int j; /* index for walls*/
    int newHeight;  /* a positive integer not exceeding 10 */
    int previousHeight;  /* a positive integer not exceeding 10 */
    int highJumps, lowJumps;

    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {
        highJumps = 0;
        lowJumps = 0;
        scanf("%d", &n);
        scanf("%d", &previousHeight);
        for (j = 1; j < n; j++)
        {
            scanf("%d", &newHeight);
            if (newHeight > previousHeight)
            {
                highJumps++;
            } else if (newHeight < previousHeight)
            {
                lowJumps++;
            }
            previousHeight = newHeight;
        }
        printf("Case %d: %d %d\n", i, highJumps, lowJumps);
    }
    return 0;
}