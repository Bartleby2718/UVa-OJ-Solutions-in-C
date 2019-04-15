#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool determine(int length, int width, int height)
{
    return (length <= 20) && (width <= 20) && (height <= 20);
}

char *toString(bool result)
{
    return result ? "good" : "bad";
}


int main()
{
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