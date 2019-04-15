#include <stdio.h>

int main()
{
    long n;
    scanf("%li", &n);
    while (n != 0)
    {
        printf("%li\n", (n - 1) % 9 + 1);
        scanf("%li", &n);
    }
    return 0;
}