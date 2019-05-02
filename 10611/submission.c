#include <stdio.h>

unsigned long getShortestButTaller(unsigned long *ladyHeights, unsigned numLadyChimps, unsigned long luchuHeight)
{
    long long low = 0, high = numLadyChimps - 1, mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (ladyHeights[mid] <= luchuHeight)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    /* can exit the loop only when "low" increases too much, so only check low */
    if (low >= numLadyChimps)
    {
        return 0;
    }
    else
    {
        unsigned long taller = ladyHeights[low];
        if (taller <= luchuHeight)
        {
            return 0;
        }
        else
        {
            unsigned long shorter = ladyHeights[high];
            return (shorter <= luchuHeight) ? taller : shorter;
        }
    }
}

unsigned long getTallestButShorter(unsigned long *ladyHeights, unsigned numLadyChimps, unsigned long luchuHeight)
{
    long long low = 0, high = numLadyChimps - 1, mid;
    while (low < high)
    {
        mid = (low + high + 1) / 2;
        if (ladyHeights[mid] >= luchuHeight)
        {
            high = mid - 1;
        }
        else
        {
            low = mid;
        }
    }
    /* can exit the loop only when "high" decreases too much, so only check ih */
    if (high < 0)
    {
        return 0;
    }
    else
    {
        unsigned long shorter = ladyHeights[high];
        if (shorter >= luchuHeight)
        {
            return 0;
        }
        else
        {
            unsigned long taller = ladyHeights[low];
            return (taller < luchuHeight) ? taller : shorter;
        }
    }
}

int main()
{
    unsigned numLadyChimps;
    scanf("%u", &numLadyChimps);
    unsigned i;
    unsigned long ladyHeights[numLadyChimps];
    for (i = 0; i < numLadyChimps; ++i)
    {
        scanf("%lu", &ladyHeights[i]);
    }
    unsigned numQueries;
    unsigned long luchuHeight;
    scanf("%u", &numQueries);
    for (i = 0; i < numQueries; ++i)
    {
        scanf("%lu", &luchuHeight);

        unsigned long tallestButShorter = getTallestButShorter(ladyHeights, numLadyChimps, luchuHeight);
        char strTallestButShorter[11] = "";
        if (tallestButShorter == 0)
        {
            strTallestButShorter[0] = 'X';
        }
        else
        {
            sprintf(strTallestButShorter, "%ld", tallestButShorter);
        }

        unsigned long shortestButTaller = getShortestButTaller(ladyHeights, numLadyChimps, luchuHeight);
        char strShortestButTaller[11] = "";
        if (shortestButTaller == 0)
        {
            strShortestButTaller[0] = 'X';
        }
        else
        {
            sprintf(strShortestButTaller, "%ld", shortestButTaller);
        }
        printf("%s %s\n", strTallestButShorter, strShortestButTaller);
    }
    return 0;
}