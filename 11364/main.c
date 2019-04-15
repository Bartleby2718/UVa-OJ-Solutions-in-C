#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int minimumDistance(int *positions, int numStores)
{
    int min = positions[0], max = positions[0], difference;
    for (int i = 1; i < numStores; i++)
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

void testMinimumDistance(int *positions, int numStores, int expected)
{
    int position;
    for (int i = 0; i < numStores; i++)
    {
        position = positions[i];
        printf("%d ", position);
    }
    int actual = minimumDistance(positions, numStores);
    printf("-> expected: %d, actual: %d.\n", expected, actual);
}

int *parseLine(char *line, int numStores)
{
    int *positions = malloc(sizeof(int) * numStores);
    int positionIndex = 0, position;
    char temp[4];
    while (*line != '\0')
    {
        // reset temp
        for (int k = 0; k < 4; k++)
        {
            temp[k] = '\0';
        }

        // move to temp one char at a time
        for (int j = 0; *line != ' ' && *line != '\0'; j++, line++)
        {
            temp[j] = *line;
        }

        // convert characters in temp to an int
        position = atoi(temp);
        positions[positionIndex] = position;

        // increment index
        if (*line == ' ')
        {
            line++;
        }
        positionIndex++;
    }

    return positions;
}

void testParseLine(char *line, int numStores, int *expectedArray)
{
    int *result = parseLine(line, numStores);

    printf("\"%s\" -> expected: {", line);
    for (int i = 0; i < numStores - 1; i++)
    {
        printf("%d, ", expectedArray[i]);
    }
    printf("%d}, actual: {", expectedArray[numStores - 1]);
    for (int i = 0; i < numStores - 1; i++)
    {
        printf("%d, ", result[i]);
    }
    printf("%d}\n", result[numStores - 1]);
    free(result);
}

int main()
{
//    int positions1[] = {24, 13, 89, 37};
//    testMinimumDistance(positions1, 4, 152);
//    int positions2[] = {7, 30, 41, 14, 39, 42};
//    testMinimumDistance(positions2, 6, 70);
//    int positions3[] = {5 ,10 ,15 ,20, 25 ,30 ,35 ,40 ,45 ,50};
//    testMinimumDistance(positions3, 10, 90);
//
//
//    testParseLine("24 13 89 37", 4, positions1);
//    testParseLine("7 30 41 14 39 42", 6, positions2);
//    testParseLine("5 10 15 20 25 30 35 40 45 50", 10, positions3);

    int numCases; // numCases between 1 and 100, inclusive
    scanf("%d\n", &numCases);
    int numStores; // numStores between 1 and 20, inclusive
    int results[numCases], *positions;
    char line[61];
    for (int i = 0; i < numCases; i++)
    {
        scanf("%d\n", &numStores);
        fgets(line, 61, stdin);
        positions = parseLine(line, numStores);
        int result = minimumDistance(positions, numStores);
        free(positions);
        results[i] = result;
    }
    for (int i = 0; i < numCases; i++)
    {
        printf("%d\n", results[i]);
    }
    return 0;
}

/* Lessons learned:
 * 1) If scanf doesn't take in the trailing newline character, it maybe consumed by the following fgets.
 * https://www.geeksforgeeks.org/problem-with-scanf-when-there-is-fgetsgetsscanf-after-it/
 * 2)
 * */