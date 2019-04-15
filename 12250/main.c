#include <stdio.h>
#include <string.h>

char *detectLanguage(char *string)
{
    if (strcmp(string, "HELLO") == 0)
    { return "ENGLISH"; }
    else if (strcmp(string, "HOLA") == 0)
    {
        return "SPANISH";
    } else if ((strcmp(string, "HALLO") == 0))
    {
        return "GERMAN";
    } else if (strcmp(string, "BONJOUR") == 0)
    {
        return "FRENCH";
    } else if (strcmp(string, "CIAO") == 0)
    {
        return "ITALIAN";
    } else if (strcmp(string, "ZDRAVSTVUJTE") == 0)
    {
        return "RUSSIAN";
    } else
    {
        return "UNKNOWN";
    }
}

int main()
{
    char input[15], *language;
    int index = 0;
    while (1)
    {
        index++;
        scanf("%s", input);
        if (strcmp(input, "#") == 0)
        {
            break;
        } else
        {
            language = detectLanguage(input);
            printf("Case %d: %s\n", index, language);

        }
    }
}