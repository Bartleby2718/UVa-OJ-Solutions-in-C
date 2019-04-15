#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dictionary
{
    size_t size;
    char *keyArray;
    int *valueArray;
};

void addEntry(struct dictionary *dictionary1, char key, int value)
{ /* assumes the same entry has not been added*/
    size_t size = dictionary1->size;
    int i;
    for (i = 0; i < size && dictionary1->keyArray[i] != '\0'; i++);
    dictionary1->keyArray[i] = key;
    dictionary1->valueArray[i] = value;
}

int getValue(struct dictionary *dictionary1, char key)
{
    size_t size = dictionary1->size;
    int i, value = 0;
    for (i = 0; i < size; i++)
    {
        if (dictionary1->keyArray[i] == key)
        {
            value = dictionary1->valueArray[i];
            break;
        }
    }
    return value;
}


int main()
{
    int numTests, numPaidCharacters, i;
    scanf("%d\n", &numTests);
    for (i = 0; i < numTests; i++)
    {
        scanf("%d\n", &numPaidCharacters);
        char *keyArray = calloc(numPaidCharacters, sizeof(char));
        int *valueArray = calloc(numPaidCharacters, sizeof(int));
        struct dictionary dictionary1 = {numPaidCharacters, keyArray, valueArray};
        struct dictionary *pDictionary1 = &dictionary1;
        int j;
        char paidCharacter;
        int value;
        for (j = 0; j < numPaidCharacters; j++)
        {
            scanf("%c %d\n", &paidCharacter, &value);
            addEntry(pDictionary1, paidCharacter, value);
        }
        long numLinesInArticle, k;
        scanf("%li\n", &numLinesInArticle);
        char line[10002], *c;
        unsigned long long sum = 0;
        for (k = 0; k < numLinesInArticle; k++)
        {
            fgets(line, 10002, stdin);
            for (c = line; *c != '\n' && *c != '\0'; c++)
            {
                value = getValue(pDictionary1, *c);
                sum += value;
            }
        }
        free(keyArray);
        free(valueArray);
        printf("%llu.%02llu$\n", sum / 100, sum % 100);
    }
    return 0;
}