#include <stdio.h>

int findNumber(char *word)
{
    char *one = "one";
    char *two = "two";
    char *three = "three";

    char *pWord = word;
    char *pOne = one;
    int maximumDifference = 1, difference = 0;
    char a, b;
    while (*pWord != '\0')
    {
        a = *pWord;
        b = *pOne;
        if (a != b)
        {
            difference++;
        }
        pWord++;
        pOne++;
    }
    if (difference <= maximumDifference)
    {
        return 1;
    }

    pWord = word;
    char *pTwo = two;
    maximumDifference = 1, difference = 0;
    while (*pWord != '\0')
    {
        a = *pWord;
        b = *pTwo;
        if (a != b)
        {
            difference++;
        }
        pWord++;
        pTwo++;
    }

    if (difference <= maximumDifference)
    {
        return 2;
    }
    pWord = word;
    char *pThree = three;
    maximumDifference = 1, difference = 0;
    while (*pWord != '\0')
    {
        a = *pWord;
        b = *pThree;
        if (a != b)
        {
            difference++;
        }
        pWord++;
        pThree++;
    }
    if (difference <= maximumDifference)
    {
        return 3;
    }

    return 0;
}

int main()
{
    int numWords, i, number;
    scanf("%d", &numWords);
    for (i = 0; i < numWords; i++)
    {
        char word[6];
        scanf("%s", word);
        number = findNumber(word);
        printf("%d\n", number);
    }
    return 0;
}