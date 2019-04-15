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

void testResidence(int divisionX, int divisionY, int x, int y, char *expected)
{
    char *actual = residence(divisionX, divisionY, x, y);
    printf("Division point (%d, %d). (%d, %d) -> expected %s, got %s.\n", divisionX, divisionY, x, y, expected, actual);
}

int main()
{
//    testResidence(2, 1, 10, 10, "NE");
//    testResidence(2, 1, -10, 1, "divisa");
//    testResidence(2, 1, 0, 33, "NO");
//    testResidence(-1000, -1000, -1000, -1000, "divisa");
//    testResidence(-1000, -1000, 0, 0, "NE");
//    testResidence(-1000, -1000, -2000, -10000, "SO");
//    testResidence(-1000, -1000, -999, -1001, "SE");
    int k; /* number of queries that will be made (0 < K ≤ 1000 */
    int n, m; /* integers N and M representing the coordinates of the division point (−10000 < N, M < 10000 */
    int x, y; /* integers X and Y representing the coordinates of a residence (−10000 ≤ X, Y ≤ 10000 */
    char *answer;
    scanf("%d", &k);
    while (k != 0)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < k; i++)
        {
            scanf("%d %d", &x, &y);
            answer = residence(n, m, x, y);
            printf("%s\n", answer);
        }
        scanf("%d", &k);
    }
    return 0;
}