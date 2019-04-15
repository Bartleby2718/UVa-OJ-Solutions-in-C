#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(size_t size)
{
    // taken from https://stackoverflow.com/a/16871702/4370146
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
    for (int i = 0; a[i] != '\0'; i++, originalLength++)
    {
        if (a[i] == '"')
            numDoubleQuotes++;
    }
    int newLength = originalLength + numDoubleQuotes + 1;
    char *a2 = malloc(sizeof(char) * newLength);
    bool isOpening = true;
    for (int i = 0, j = 0; a[i] != '\0'; i++, j++)
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

void testWithOnePair()
{
    char *x = "\"a\"";
    char *y = replaceDoubleQuotes(x);
    char *expected = "``a''";
    printf("Original: %s of length %d\n", x, (int) strlen(x));
    printf("Expected: %s of length %d\n", expected, (int) strlen(expected));
    printf("Actual: %s of length %d\n", y, (int) strlen(y));
}

void testWithTwoPairs()
{
    char *x = "\"a\"\"b\"";
    char *y = replaceDoubleQuotes(x);
    char *expected = "``a''``b''";
    printf("Original: %s of length %d\n", x, (int) strlen(x));
    printf("Expected: %s of length %d\n", expected, (int) strlen(expected));
    printf("Actual: %s of length %d\n", y, (int) strlen(y));
}

void testWithGivenSample()
{
    char *x = "\"To be or not to be,\" quoth the Bard, \"that\n"
              "is the question\".\n"
              "The programming contestant replied: \"I must disagree.\n"
              "To `C' or not to `C', that is The Question!\"";
    char *y = replaceDoubleQuotes(x);
    char *expected = "``To be or not to be,'' quoth the Bard, ``that\n"
                     "is the question''.\n"
                     "The programming contestant replied: ``I must disagree.\n"
                     "To `C' or not to `C', that is The Question!''";
    printf("Original: %s of length %d\n", x, (int) strlen(x));
    printf("Expected: %s of length %d\n", expected, (int) strlen(expected));
    printf("Actual: %s of length %d\n", y, (int) strlen(y));
}

int main(void)
{
    testWithOnePair();
    testWithTwoPairs();
    testWithGivenSample();
    printf("input string : ");
    char *m = inputString(10);
    int l = strlen(m);
    printf("%s is a string of length %d\n", m, l);

    char *m2 = replaceDoubleQuotes(m);
    int l2 = strlen(m2);
    printf("%s is a string of length %d\n", m2, l2);
    printf("%s", m2);
    free(m);
    free(m2);
    return 0;
}