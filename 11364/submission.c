#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int minimumDistance(int *positions, int numStores)
{
    int min = positions[0], max = positions[0], difference, i;
    for (i = 1; i < numStores; i++)
    {
        if (positions[i] > max)
        {
            max = positions[i];
        }
        if (positions[i] < min)
        {
            min = positions[i];
        }
    }
    difference = max - min;
    return difference * 2;
}

int *parseLine(char *line, int numStores)
{
    int *positions = malloc(sizeof(int) * numStores);
    int positionIndex = 0, position, j, k;
    char temp[4];
    while (*line != '\0')
    {
        for (k = 0; k < 4; k++)
        {
            temp[k] = '\0';
        }
        for (j = 0; *line != ' ' && *line != '\0'; j++, line++)
        {
            temp[j] = *line;
        }
        position = atoi(temp);
        positions[positionIndex] = position;
        if (*line == ' ')
        {
            line++;
        }
        positionIndex++;
    }

    return positions;
}

int main()
{
    int numCases;
    scanf("%d\n", &numCases);
    int numStores;
    int results[numCases], *positions, i;
    char line[61];
    for (i = 0; i < numCases; i++)
    {
        scanf("%d\n", &numStores);
        fgets(line, 61, stdin);
        positions = parseLine(line, numStores);
        int result = minimumDistance(positions, numStores);
        free(positions);
        results[i] = result;
    }
    for (i = 0; i < numCases; i++)
    {
        printf("%d\n", results[i]);
    }
    return 0;
}