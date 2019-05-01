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

void testNumTimes(int blockHeight, int blockLength, int *pieceHeights, long expected)
{
    long actual = numTimes(blockHeight, blockLength, pieceHeights);
    printf("Height %d X Length %d (", blockHeight, blockLength);
    int i;
    for (i = 0; i < blockLength; ++i)
    {
        printf("%s%d", i > 0 ? ", " : "", pieceHeights[i]);
    }
    printf("): expected %li, got %li.\n", expected, actual);
}

int main()
{
    /*
    int array1[] = {1, 2, 3, 2, 0, 3, 4, 5};
    testNumTimes(5, 8, array1, 7);
    int array2[] = {1, 0, 2};
    testNumTimes(3, 3, array2, 3);
    int array3[] = {4, 4, 1};
    testNumTimes(4, 3, array3, 3);
    int array4[] = {1};
    testNumTimes(1, 1, array4, 0);
    int array5[] = {1};
    testNumTimes(2, 1, array5, 1);
    int array6[] = {1, 1};
    testNumTimes(1, 2, array6, 0);
    int array7[] = {1, 1};
    testNumTimes(3, 2, array7, 2);
    int array8[] = {3, 2, 1, 2, 3};
    testNumTimes(3, 5, array8, 2);
    int array9[] = {2, 2, 3, 4, 5, 6, 4, 2, 0, 6};
    testNumTimes(6, 10, array9, 10);
    int array10[] = {1, 1, 0, 0, 2, 2, 0, 0, 4, 4, 0, 0, 8, 8, 0, 0};
    testNumTimes(10, 16, array10, 24);
    return 0;
    */
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