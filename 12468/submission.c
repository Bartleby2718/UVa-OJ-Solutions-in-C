#include <stdio.h>

int getMinPresses(int current, int next)
{
    int up = (next - current + 100) % 100;
    return up <= 50 ? up : 100 - up;
}

int main()
{
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