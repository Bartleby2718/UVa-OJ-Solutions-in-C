#include <stdio.h>

int main()
{
    int numTestCases;
    int i; /*index for test cases*/
    int numScaryCreatures;
    int j; /*index for scary creatures*/
    int creatureSpeed; /*1 ≤ c_i ≤ 10000 for each i*/
    int clownSpeed;
    scanf("%d", &numTestCases);
    for (i = 1; i <= numTestCases; i++)
    {
        clownSpeed = 0;
        scanf("%d", &numScaryCreatures);
        for (j = 0; j < numScaryCreatures; j++)
        {
            scanf("%d", &creatureSpeed);
            if (creatureSpeed > clownSpeed)
            {
                clownSpeed = creatureSpeed;
            }
        }
        printf("Case %d: %d\n", i, clownSpeed);
    }
    return 0;
}