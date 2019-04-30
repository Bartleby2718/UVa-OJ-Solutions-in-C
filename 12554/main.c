#include <stdio.h>
#include <string.h>


char *whatToSay(unsigned index)
{
    unsigned remainder = index % 16;

    if (remainder % 4 == 0)
    {
        return "Happy";
    }
    else if (remainder % 4 == 1)
    {
        return "birthday";
    }
    else if (remainder % 4 == 2)
    {
        return "to";
    }
    else
    {
        return remainder == 11 ? "Rujia" : "you";
    }
}

void testWhatToSay()
{
    int i;
    for (i = 0; i < 16 + 1; ++i)
    {
        printf("%d: %s\n", i, whatToSay(i));
    }
}

int main()
{
    /*
    testWhatToSay();
    return 0;
     */
    unsigned numPeople, i;
    scanf("%u", &numPeople);
    char names[numPeople][102]; /* TODO: doesn't work if this is changed to char *names[numPeople]*/
    for (i = 0; i < numPeople; ++i)
    {
        char name[102] = ""; /* at most 100 characters and do not have whitespace characters inside */
        scanf("%s", name);
        strcpy(names[i], name);
    }
    unsigned numSung = (numPeople > 16) ? (numPeople / 16 + 1) : 1;
    for (i = 0; i < numSung * 16; ++i)
    {
        char who[102], what[9];
        strcpy(who, names[i % numPeople]);
        strcpy(what, whatToSay(i));
        printf("%s: %s\n", who, what);
    }
    return 0;
}