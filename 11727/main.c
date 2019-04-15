#include <stdio.h>

int median(int a, int b, int c)
{
    int j, salary;
    int salaries[3] = {a, b, c};
    int minimumSalary = 10001, minimumIndex = -1, maximumSalary = 0, maximumIndex = -1;
    for (j = 0; j < 3; j++)
    {
        salary = salaries[j];
        if (salary < minimumSalary)
        {
            minimumSalary = salary;
            minimumIndex = j;
        }
        if (salary > maximumSalary)
        {
            maximumSalary = salary;
            maximumIndex = j;
        }
    }
    j = 3 - minimumIndex - maximumIndex;
    salary = salaries[j];
    return salary;
}

void testMedian(int a, int b, int c, int expected)
{
    int actual = median(a, b, c);
    printf("(%d, %d, %d) -> expected %d, got %d.\n", a, b, c, expected, actual);
}

int main()
{
    testMedian(1000, 2000, 3000, 2000);
    testMedian(3000, 2500, 1500, 2500);
    testMedian(1500, 1200, 1800, 1500);
    int t; /* an integer T (T < 20) that indicates the number of test cases */
    int i; /* loop variable */
    int a, b, c; /*  the salaries of the three employees, all in the range [1000, 10000]. */
    int answer;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        answer = median(a, b, c);
        printf("Case %d: %d\n", i + 1, answer);

    }
    return 0;
}