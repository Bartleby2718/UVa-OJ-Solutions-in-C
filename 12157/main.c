#include <stdio.h>
#include <string.h>

unsigned getMileCost(unsigned *durations, unsigned numDurations)
{
    unsigned sum = 0, duration, cost, k;
    for (k = 0; k < numDurations; ++k)
    {
        duration = durations[k];
        cost = 10 * (duration / 30 + 1);
        sum += cost;
    }
    return sum;
}

unsigned getJuiceCost(unsigned *durations, unsigned numDurations)
{
    unsigned sum = 0, duration, cost, k;
    for (k = 0; k < numDurations; ++k)
    {
        duration = durations[k];
        cost = 15 * (duration / 60 + 1);
        sum += cost;
    }
    return sum;
}

int main()
{
    unsigned numTestCases, i; /* 0 < numTestCases < 50*/
    scanf("%u", &numTestCases);
    char line[100], *token;
    const char delimiter[2] = " ";
    for (i = 0; i < numTestCases; ++i)
    {
        unsigned numDurations; /* 0 < numDurations < 20 */
        scanf("%u\n", &numDurations);
        unsigned durations[numDurations]; /* 1 <= duration <= 2000 */

        fgets(line, 100, stdin);
        unsigned j = 0;
        token = strtok(line, delimiter);
        while (token != NULL)
        {
            sscanf(token, "%u", &durations[j]);
            token = strtok(NULL, delimiter);
            ++j;
        }

        unsigned mileCost = getMileCost(durations, numDurations);
        unsigned juiceCost = getJuiceCost(durations, numDurations);
        if (mileCost < juiceCost)
        {
            printf("Case %u: Mile %u\n", i + 1, mileCost);
        }
        else if (mileCost > juiceCost)
        {
            printf("Case %u: Juice %u\n", i + 1, juiceCost);
        }
        else
        {
            printf("Case %u: Mile Juice %u\n", i + 1, juiceCost);
        }
    }
    return 0;
}
