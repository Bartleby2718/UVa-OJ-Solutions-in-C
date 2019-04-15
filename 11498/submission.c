#include <stdbool.h>
#include <stdio.h>


char *residence(int divisionX, int divisionY, int x, int y)
{
    if (x == divisionX || y == divisionY)
    {
        return "divisa";
    } else if (x < divisionX && y > divisionY)
    {
        return "NO";
    } else if (x > divisionX && y > divisionY)
    {
        return "NE";
    } else if (x > divisionX && y < divisionY)
    {
        return "SE";
    } else
    {
        return "SO";
    }
}

int main()
{
    int k; /* number of queries that will be made (0 < K ≤ 1000 */
    int n, m; /* integers N and M representing the coordinates of the division point (−10000 < N, M < 10000 */
    int x, y; /* integers X and Y representing the coordinates of a residence (−10000 ≤ X, Y ≤ 10000 */
    char *answer;
    int i;
    scanf("%d", &k);
    while (k != 0)
    {
        scanf("%d %d", &n, &m);
        for (i = 0; i < k; i++)
        {
            scanf("%d %d", &x, &y);
            answer = residence(n, m, x, y);
            printf("%s\n", answer);
        }
        scanf("%d", &k);
    }
    return 0;
}