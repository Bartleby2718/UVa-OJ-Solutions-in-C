#include <stdio.h>

int getMinPresses(int current, int next)
{
    int up = (next - current + 100) % 100;
    return up <= 50 ? up : 100 - up;
}

void testGetMinPresses(int current, int next, int expected)
{
    int actual = getMinPresses(current, next);
    printf("(%d, %d) -> expected %d, got %d.\n", current, next, expected, actual);
}

int main()
{
    /*
    testGetMinPresses(3, 9, 6);
    testGetMinPresses(0, 99, 1);
    testGetMinPresses(12, 27, 15);
    testGetMinPresses(0, 0, 0);
    testGetMinPresses(99, 0, 1);
    testGetMinPresses(0, 50, 50);
    testGetMinPresses(0, 49, 49);
    testGetMinPresses(0, 51, 49);
    */
    int current, next;
    scanf("%d %d", &current, &next);
    while (!(current == -1 && next == -1))
    {
        int minPresses = getMinPresses(current, next);
        printf("%d\n", minPresses);
        scanf("%d %d", &current, &next);
    }
    return 0;
}