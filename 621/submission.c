#include <stdio.h>
#include <string.h>

char analyze(char *sequence)
{
    int length = strlen(sequence);
    if (strcmp(sequence, "1") == 0 || strcmp(sequence, "4") == 0 || strcmp(sequence, "78") == 0)
    {
        return '+';
    }
    char *lastTwoDigits = sequence + (length - 2);
    if (strcmp(lastTwoDigits, "35") == 0)
    {
        return '-';
    }
    char firstDigit = sequence[0];
    char lastDigit = sequence[length - 1];
    if (firstDigit == '9' && lastDigit == '4')
    {
        return '*';

    }
    if (strncmp(sequence, "190", 3) == 0)
    {
        return '?';
    }
    return '!';
}

int main()
{
    int n; /* A integer n stating the number of encrypted results */
    scanf("%d\n", &n);

    int i;
    char sequence[20], output;
    for (i = 0; i < n; i++)
    {
        fgets(sequence, 20, stdin);
        strtok(sequence, "\n");
        output = analyze(sequence);
        printf("%c\n", output);
    }
    return 0;
}