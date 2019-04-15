#include <stdio.h>


int main()
{
    int height, up, down, fatigueFactor;  /* up > 0, 1 <= all <= 100 */
    int day;
    float currentHeight, newUp;
    scanf("%d %d %d %d", &height, &up, &down, &fatigueFactor);
    while (height != 0)
    {
        currentHeight = up;
        if (currentHeight > height)
        {
            printf("success on day 1\n");
        } else
        {
            for (day = 2; currentHeight - down >= 0 && currentHeight <= height; day++)
            {
                currentHeight -= down;
                newUp = up * (1 - (day - 1) * fatigueFactor / 100.0);
                if (newUp < 0)
                {
                    newUp = 0;
                }
                currentHeight += newUp;
            }
            printf("%s on day %d\n", (currentHeight > height) ? "success" : "failure", day - 1);
        }
        scanf("%d %d %d %d", &height, &up, &down, &fatigueFactor);
    }
    return 0;
}