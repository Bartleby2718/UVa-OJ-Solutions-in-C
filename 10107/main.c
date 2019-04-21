#include <stdio.h>

int main()
{
    long i, temp, median, array[10000];
    long index = 0;
    while (scanf("%li", &array[index]) == 1)
    {
        for (i = index; (i > 0) && (array[i - 1] > array[i]); --i)
        {
            temp = array[i];
            array[i] = array[i - 1];
            array[i - 1] = temp;
        }
        if (index % 2 == 0) /* last index even == odd number of elements */
        {
            median = array[index / 2];
        } else
        {
            median = (array[(index - 1) / 2] + array[(index + 1) / 2 ]) / 2;
        }
        printf("%li\n", median);
        ++index;
    }
    return 0;
}
