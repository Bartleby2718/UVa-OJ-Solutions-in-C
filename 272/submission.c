#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(size_t size)
{
    char *str, ch;
    size_t length = 0;
    str = realloc(NULL, sizeof(char) * size);
    if (str == NULL)
        return str;
    while ((ch = fgetc(stdin)) != EOF)
    {
        str[length++] = ch;
        if (length == size)
        {
            str = realloc(str, sizeof(char) * (size *= 2));
            if (str == NULL)
                return str;
        }
    }
    str[length++] = '\0';

    return realloc(str, sizeof(char) * length);
}

char *replaceDoubleQuotes(char *a)
{
    int originalLength = 0, numDoubleQuotes = 0;
    int k;
    for (k = 0; a[k] != '\0'; k++, originalLength++)
    {
        if (a[k] == '"')
            numDoubleQuotes++;
    }
    int newLength = originalLength + numDoubleQuotes + 1;
    char *a2 = malloc(sizeof(char) * newLength);
    bool isOpening = true;
    int i, j;
    for (i = 0, j = 0; a[i] != '\0'; i++, j++)
    {
        if (a[i] == '"')
        {
            if (isOpening)
            {
                a2[j++] = '`';
                a2[j] = '`';
            } else
            {
                a2[j++] = '\'';
                a2[j] = '\'';
            }
            isOpening = !isOpening;
        } else
        {
            a2[j] = a[i];
        }
    }
    a2[newLength - 1] = '\0';
    return a2;
}


int main(void)
{
    char *m = inputString(10);
    char *m2 = replaceDoubleQuotes(m);
    printf("%s", m2);
    free(m);
    free(m2);
    return 0;
}