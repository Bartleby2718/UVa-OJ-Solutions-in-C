#include <stdio.h>

long getPosition(int depth, long index)
{
    long node = 1; /* top node */
    --index; /* make index zero-based */
    long i;
    for (i = 0; i < depth - 1; ++i) /* go down the tree (depth-1) times */
    {
        node *= 2;  /* go down one node*/
        if (index % 2 == 1) /* right subtree if not divisible by 2*/
        {
            ++node;
        }
        index /= 2;
    }
    return node;
}

int main()
{
    int depth; /* 2 <= d <= 20 */
    long index; /* 1 <= i <= 524288 */
    int numTestCases, i;
    scanf("%d", &numTestCases);
    for (i = 0; i < numTestCases; ++i)
    {
        scanf("%d %ld", &depth, &index);
        long answer = getPosition(depth, index);
        printf("%ld\n", answer);
    }
    return 0;
}
