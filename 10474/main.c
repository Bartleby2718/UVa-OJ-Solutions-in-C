#include <stdio.h>
#include <stdlib.h>

unsigned *getPositionThroughBinarySearch(unsigned *sortedArray, unsigned low, unsigned high, unsigned query)
{
    unsigned lowElement = sortedArray[low];
    unsigned highElement = sortedArray[high];
    unsigned *p = calloc(1, sizeof(unsigned));
    if (query == lowElement)
    {
        *p = low + 1;
        return p;
    }
    else if (query > lowElement && query <= highElement)
    {
        unsigned mid = (low + high) / 2;
        unsigned midElement = sortedArray[mid];
        if (query <= midElement)
        {
            return getPositionThroughBinarySearch(sortedArray, low, mid, query);
        }
        else
        {
            return getPositionThroughBinarySearch(sortedArray, mid + 1, high, query);
        }
    }
    else
    {
        return NULL;
    }
}

int main()
{
    unsigned numMarbles, numQueries, i, index = 0;
    scanf("%u %u", &numMarbles, &numQueries);
    while (!(numMarbles == 0 && numQueries == 0))
    {
        ++index;
        printf("CASE# %u:\n", index);

        unsigned marbles[numMarbles], newMarble;
        int j;
        scanf("%u", marbles);
        /* insertion sort */
        for (i = 1; i < numMarbles; ++i)
        {
            scanf("%u", &newMarble);
            for (j = i - 1; j >= 0 && marbles[j] > newMarble; --j)
            {
                marbles[j + 1] = marbles[j];
            }
            marbles[j + 1] = newMarble;
        }
        unsigned query; /* none of the input numbers are greater than 10000 and none of them are negative. */
        for (i = 0; i < numQueries; ++i)
        {
            scanf("%u", &query);
            unsigned *pPosition = getPositionThroughBinarySearch(marbles, 0, numMarbles - 1, query);
            if (pPosition == NULL)
            {
                printf("%u not found\n", query);
            }
            else
            {
                printf("%u found at %u\n", query, *pPosition);
            }
            free(pPosition);
        }
        scanf("%u %u", &numMarbles, &numQueries);
    }
    return 0;
}
