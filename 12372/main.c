#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool determine(int length, int width, int height)
{
    return (length <= 20) && (width <= 20) && (height <= 20);
}

void testDetermine(int length, int width, int height, bool expected)
{
    bool actual = determine(length, width, height);
    char *expectedStr = expected ? "good" : "bad";
    char *actualStr = actual ? "good" : "bad";
    printf("length %d, width %d, height %d: expected %s, got %s.\n", length, width, height, expectedStr, actualStr);
}

char *toString(bool result)
{
    return result ? "good" : "bad";
}

void testToString()
{
    if (strcmp(toString(true), "good") == 0 && strcmp(toString(false), "bad") == 0)
    {
        printf("toString works fine.\n");
    } else
    {
        printf("toString doesn\'t work.\n");
    }
}


int main()
{
//    testToString();
//
//    testDetermine(20, 20, 20, true);
//    testDetermine(1, 2, 21, false);

    int t; /* an integer T (T ≤ 100), which indicates the number of test cases. */
    scanf("%d", &t);
    int length, width, height;
    int i;
    char *resultStr;
    bool result;
    for (i = 0; i < t; i++)
    {
        scanf("%d %d %d", &length, &width, &height);
        result = determine(length, width, height);
        resultStr = toString(result);
        printf("Case %d: %s\n", i + 1, resultStr);
    }
    return 0;
}