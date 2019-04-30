#include <stdio.h>
#include <string.h>

int getDisplacement(int *instructions, char *instruction)
{
    int displacement, oneBasedIndex;
    if (strcmp(instruction, "LEFT") == 0)
    {
        displacement = -1;
    }
    else if (strcmp(instruction, "RIGHT") == 0)
    {
        displacement = 1;
    }
    else
    {
        sscanf(instruction, "SAME AS %d", &oneBasedIndex);
        displacement = instructions[oneBasedIndex - 1];
    }
    return displacement;
}

void testGetDisplacement(int *instructions, char *instruction, int expected)
{
    int actual = getDisplacement(instructions, instruction);
    printf("%s: expected %d, got %d.\n", instruction, expected, actual);
}

int main()
{
    /*
    int instructions[2] = {1, -1};
    testGetDisplacement(instructions, "LEFT", -1);
    testGetDisplacement(instructions, "RIGHT", 1);
    testGetDisplacement(instructions, "SAME AS 2", -1);
    return 0;
    */
    unsigned numTestCases, i; /* T <= 100*/
    scanf("%u", &numTestCases);
    for (i = 0; i < numTestCases; ++i)
    {
        int position = 0;
        unsigned numInstructions, j; /* 1 <= n <= 100 */
        scanf("%u\n", &numInstructions);
        int instructions[numInstructions];
        for (j = 0; j < numInstructions; ++j)
        {
            char line[12] = "";
            fgets(line, 12, stdin);
            strtok(line, "\n");
            int displacement = getDisplacement(instructions, line);
            instructions[j] = displacement;
            position += displacement;
        }
        printf("%d\n", position);
    }


    return 0;
}