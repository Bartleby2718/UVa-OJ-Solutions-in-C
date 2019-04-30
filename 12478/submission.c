#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_NAMES 8
#define MAX_STRING_LENGTH 8
#define GRID_WIDTH 9
#define GRID_LENGTH 9


void insertionSort(char *array, unsigned length)
{
    int i, j;
    for (i = 1; i < length; ++i)
    {
        char key = array[i];
        for (j = i - 1; array[j] > key && j >= 0; --j)
        {
            array[j + 1] = array[j];
        }
        array[j + 1] = key;
    }
}

bool equivalentWhenPermuted(char *string1, char *string2, unsigned length)
{
    char *first = calloc(length + 1, sizeof(char));
    strncpy(first, string1, length);
    insertionSort(first, length);
    char *second = calloc(length + 1, sizeof(char));
    strncpy(second, string2, length);
    insertionSort(second, length);
    bool result = strcmp(first, second) == 0;
    free(first);
    free(second);
    return result;
}

int main()
{
    char names[NUM_NAMES][MAX_STRING_LENGTH] = {"RAKIBUL",
                                                "ANINDYA",
                                                "MOSHIUR",
                                                "SHIPLU",
                                                "KABIR",
                                                "SUNNY",
                                                "OBAIDA",
                                                "WASI"};
    char grid[GRID_LENGTH][GRID_WIDTH + 1] = {"OBIDAIBKR",
                                              "RKAULHISP",
                                              "SADIYANNO",
                                              "HEISAWHIA",
                                              "IRAKIBULS",
                                              "MFBINTRNO",
                                              "UTOYZIFAH",
                                              "LEBSYNUNE",
                                              "EMOTIONAL"};
    unsigned i, j, k;
    bool keepSearching = true;
    for (i = 0; i < NUM_NAMES && keepSearching; ++i)
    {
        char *name = names[i];
        unsigned length = strlen(name);
        unsigned count = 0;
        /* check horizontal*/
        for (j = 0; j < GRID_LENGTH; ++j)
        {

            for (k = 0; k <= GRID_WIDTH - length; ++k)
            {
                char horizontalWord[MAX_STRING_LENGTH] = "";
                strncpy(horizontalWord, grid[j] + k, length);
                if (equivalentWhenPermuted(horizontalWord, name, length))
                {
                    ++count;
                }
            }
        }
        /* check vertical */
        for (j = 0; j <= GRID_LENGTH - length; ++j)
        {
            for (k = 0; k < GRID_WIDTH; ++k)
            {
                char verticalWord[MAX_STRING_LENGTH] = "";
                unsigned l;
                for (l = 0; l < length; ++l)
                {
                    verticalWord[l] = grid[j + l][k];
                }
                if (equivalentWhenPermuted(verticalWord, name, length))
                {
                    ++count;
                }
            }
        }
        if (count == 2)
        {
            printf("%s\n", name);
            keepSearching = (count != 2);
        }
    }
    return 0;
}