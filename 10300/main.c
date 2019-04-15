#include <stdio.h>

int main()
{
    int n;  /* n<20, the number of test cases */
    scanf("%d", &n);
    int f;  /* 0<f<20, the number of farmers in the test */
    int i;  /* index for test cases */
    int j;  /* index for farmer */
    long size, numAnimals, friendliness;
    long long premiumPerFarmer, summedBurden;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &f);
        summedBurden = 0;
        for (j = 0; j < f; j++)
        {
            scanf("%li %li %li", &size, &numAnimals, &friendliness);
            premiumPerFarmer = size * friendliness;
            summedBurden += premiumPerFarmer;
        }
        printf("%llu\n", summedBurden);
    }
    return 0;
}