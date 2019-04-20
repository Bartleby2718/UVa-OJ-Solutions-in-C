#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isDescending(char *code)
{
    char *p, current, next;
    for (p = code; *(p + 1) != '\0'; ++p)
    {
        current = *p;
        next = *(p + 1);
        if (current < next)
        {
            return false;
        }
    }
    return true;
}

int nextSmallestIndex(char *code, char except)
{
    /* assumes that the string is not empty */
    char smallestChar = CHAR_MAX, *p;
    int life = 0, i, smallestIndex = -1;
    for (p = code; *p != '\0'; p++)
    {
        if (*p == except)
        {
            ++life;
        }
    }
    for (i = 0; code[i] != '\0'; ++i)
    {
        if (code[i] == except)
        {
            if (life > 0)
            {
                --life;
            } else
            {
                return i;
            }
        } else if (code[i] > except && code[i] < smallestChar)
        {
            smallestChar = code[i];
            smallestIndex = i;
        }
    }
    return smallestIndex;
}

char *sort(char *code)
{ /* insertion sort */
    size_t length = strlen(code);
    int i, j, key;
    for (i = 1; i < length; i++)
    {
        key = code[i];
        j = i - 1;
        while (j >= 0 && code[j] > key)
        {
            code[j + 1] = code[j];
            j--;
        }
        code[j + 1] = key;
    }
    return code;
}

char *getSuccessor(char *code)
{
    char *next = NULL, temp;
    size_t length = strlen(code), i = length - 2, nextSmallest;
    while (i >= 0 && isDescending(code + i))
    {
        --i;
    }
    if (i != -1)
    {
        next = calloc(length + 1, sizeof(char));
        strcpy(next, code);
        temp = next[i];
        nextSmallest = i + nextSmallestIndex(next + i, *(next + i));
        next[i] = next[nextSmallest];
        next[nextSmallest] = temp;
        strncpy(next, next, i + 1);

        char *sorted = sort(next + i + 1);
        strcpy(next + i + 1, sorted);
    }
    return next;
}

int main()
{
    char line[52], *successor;
    fgets(line, 52, stdin);
    strtok(line, "\n");
    while (strcmp(line, "#") != 0)
    {
        successor = getSuccessor(line);
        printf("%s\n", (successor == NULL) ? "No Successor" : successor);
        fgets(line, 52, stdin);
        strtok(line, "\n");
    }
    return 0;
}