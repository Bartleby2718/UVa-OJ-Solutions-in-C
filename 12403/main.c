#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t;  /* denoting the number of operations 1 ≤ T ≤ 100 )*/
    scanf("%d\n", &t);
    int i, account = 0, donation;
    char operation[15];  /*word 6 + space 1 + amount 6 + newline 1 + null terminator 1 */
    const char *donate = "donate";
    const char *report = "report";
    for (i = 0; i < t; i++)
    {
        fgets(operation, 15, stdin);
        if (strncmp(operation, donate, 6) == 0)
        {
            donation = (int) strtol(operation + 7, (char **) NULL, 10);
            account += donation;
        } else if (strncmp(operation, report, 6) == 0)
        {
            printf("%d\n", account);
        }
    }
    return 0;
}