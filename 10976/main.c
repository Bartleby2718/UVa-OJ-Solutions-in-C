#include <stdio.h>

int main()
{
    int k, x, y, count;
    while (scanf("%d", &k) == 1)
    {
        count = 0;
        for (y = k + 1; y <= 2 * k; y++)
        {
            if ((k * y) % (y - k) == 0)
            {
                count++;
            }
        }
        printf("%d\n", count);
        for (y = k + 1; y <= 2 * k; y++)
        {
            if ((k * y) % (y - k) == 0)
            {
                x = (k * y) / (y - k);
                printf("1/%d = 1/%d + 1/%d\n", k, x, y);
            }
        }
    }

    return 0;
}
