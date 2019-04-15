#include <stdio.h>
#include <string.h>

int main()
{
    int length = 100;
    char string[length];
    while (fgets(string, length - 1, stdin))
    {
        printf("%s", string);
    }
    return 0;
}