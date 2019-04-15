#include <stdio.h>

int main()
{
    int caseIndex = 0;
    int i, x, n;
    int emoogleBalance, should, did;
    scanf("%d", &n);
    while (n != 0)
    {
        caseIndex++;
        should = 0;
        did = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &x);
            if (x == 0)
            {
                did++;
            } else
            {
                should++;
            }
        }
        emoogleBalance = should - did;
        printf("Case %d: %d\n", caseIndex, emoogleBalance);
        scanf("%d", &n);
    }
    return 0;
}