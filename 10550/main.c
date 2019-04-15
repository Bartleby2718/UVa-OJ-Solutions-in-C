#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int getDegrees(int initial, int first, int second, int third)
{
    int sum = 0;
    //turn the dial clockwise 2 full turns
    sum += 360 * 2;

    // stop at the first number of the combination
    if (initial == first)
    {
        sum += 360;
    } else
    {
        sum += ((initial - first + 40) % 40) * 9;
    }

    // turn the dial counter-clockwise 1 full turn
    sum += 360;

    // continue turning counter-clockwise until the 2nd number is reached
    if (first == second)
    {
        sum += 360;
    } else
    {
        sum += ((second - first + 40) % 40) * 9;
    }

    // turn the dial clockwise again until the 3rd number is reached
    if (second == third)
    {
        sum += 360;
    } else
    {
        sum += ((second - third + 40) % 40) * 9;
    }
    return sum;
}


void testGetDegrees1()
{
    int expected = 1350;
    int actual = getDegrees(0, 30, 0, 30);
    printf("Test 1: 0, 30, 0, 30 - ");
    printf("Expected: %d, ", expected);
    printf("Actual: %d\n", actual);
}

void testGetDegrees2()
{
    int expected = 1350;
    int actual = getDegrees(5, 35, 5, 35);
    printf("Test 2: 5, 35, 5, 35 - ");
    printf("Expected: %d, ", expected);
    printf("Actual: %d\n", actual);
}

void testGetDegrees3()
{
    int expected = 1620;
    int actual = getDegrees(0, 20, 0, 20);
    printf("Test 3: 0, 20, 0, 20 - ");
    printf("Expected: %d, ", expected);
    printf("Actual: %d\n", actual);
}


void testGetDegrees4()
{
    int expected = 1620;
    int actual = getDegrees(7, 27, 7, 27);
    printf("Test 4: 7, 27, 7, 27 - ");
    printf("Expected: %d, ", expected);
    printf("Actual: %d\n", actual);
}

void testGetDegrees5()
{
    int expected = 1890;
    int actual = getDegrees(0, 10, 0, 10);
    printf("Test 5: 0, 10, 0, 10 - ");
    printf("Expected: %d, ", expected);
    printf("Actual: %d\n", actual);
}

void testGetDegrees6()
{
    int expected = 1890;
    int actual = getDegrees(9, 19, 9, 19);
    printf("Test 6: 9, 19, 9, 19 - ");
    printf("Expected: %d, ", expected);
    printf("Actual: %d\n", actual);
}

int main()
{
    int initial, first, second, third, result;
    bool reachedEnd = false;
    scanf("%d %d %d %d", &initial, &first, &second, &third);
    result = getDegrees(initial, first, second, third);
    printf("%d", result);
    reachedEnd = (initial == 0 && first == 0 && second == 0 && third == 0);
    while (!reachedEnd)
    {
        scanf("%d %d %d %d", &initial, &first, &second, &third);
        result = getDegrees(initial, first, second, third);
        printf("\n%d", result);
        reachedEnd = (initial == 0 && first == 0 && second == 0 && third == 0);
    }
    testGetDegrees1();
    testGetDegrees2();
    testGetDegrees3();
    testGetDegrees4();
    testGetDegrees5();
    testGetDegrees6();
    return 0;
}

