#include <stdio.h>

int getMax(int *numbers, int count)
{
    int max = numbers[0];
    int i, number;
    for (i = 1; i < count; ++i)
    {
        number = numbers[i];
        if (number > max)
        {
            max = number;
        }
    }
    return max;
}

long numTimes(int blockHeight, int blockLength, int *pieceHeights)
{
    /* case 1: nonsense values */
    if (blockHeight <= 0 || blockLength <= 0)
    {
        return 0;
    }

    /* case 2: slice the top */
    int max = getMax(pieceHeights, blockLength);
    if (max < blockHeight)
    {
        return (blockHeight - max) + numTimes(max, blockLength, pieceHeights);
    }

    /* case 3: divide */
    int i, height;
    for (i = 0; i < blockLength; ++i)
    {
        height = pieceHeights[i];
        if (height == blockHeight)
        {
            return numTimes(height, i, pieceHeights) + numTimes(height, blockLength - i - 1, pieceHeights + i + 1);
        }
    }
    return 0;
}

int main()
{
    int blockHeight; /* 1 <= A <= 10000 */
    int blockLength; /* 1 <= C <= 10000 */
    scanf("%d %d", &blockHeight, &blockLength);
    while (!(blockHeight == 0 && blockLength == 0))
    {
        int pieceHeights[blockLength]; /* 1 <= X_i <= A */
        int i;
        for (i = 0; i < blockLength; ++i)
        {
            scanf("%d", &pieceHeights[i]);
        }
        long answer = numTimes(blockHeight, blockLength, pieceHeights);
        printf("%li\n", answer);
        scanf("%d %d", &blockHeight, &blockLength);
    }
    return 0;
}
