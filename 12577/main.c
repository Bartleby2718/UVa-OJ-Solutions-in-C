#include <stdio.h>
#include <string.h>

int main()
{
    char string[6];
    char *hajj = "Hajj";
    char *umrah = "Umrah";
    char *whenHajj = "Hajj-e-Akbar";
    char *whenUmrah = "Hajj-e-Asghar";
    scanf("%s", string);
    int index = 0;

    while (*string != '*')
    {
        index++;
        if (strcmp(string, hajj) == 0)
        {
            printf("Case %d: %s\n", index, whenHajj);
        } else if (strcmp(string, umrah) == 0)
        {
            printf("Case %d: %s\n", index, whenUmrah);
        }
        scanf("%s", string);
    }
    return 0;
}