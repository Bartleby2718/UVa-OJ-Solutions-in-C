#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool checkMembership(char course[5], char courses[][5], unsigned numCourses)
{
    int i;
    for (i = 0; i < numCourses; ++i)
    {
        if (strcmp(course, courses[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

void testCheckMembership(char course[5], char courses[][5], unsigned numCourses, bool expected)
{
    printf("%s in {", course);
    int i;
    for (i = 0; i < numCourses; ++i)
    {
        if (i == 0)
        {
            printf("%s", courses[i]);
        }
        else
        {
            printf(", %s", courses[i]);
        }
    }
    bool actual = checkMembership(course, courses, numCourses);
    printf("}? expected %s, got %s.\n", expected ? "true" : "false", actual ? "true" : "false");
}

int main()
{
    /*
    char courses[][5] = {"1234", "5678"};
    testCheckMembership("1234", courses, 2, true);
    testCheckMembership("5678", courses, 2, true);
    testCheckMembership("1211", courses, 2, false);
    return 0;
    */
    unsigned numCoursesSelected; /* 1<= k <= 100 */
    scanf("%u", &numCoursesSelected);
    int a = 0;
    while (numCoursesSelected != 0)
    {
        ++a;
        bool meetsRequirement = true;
        unsigned numCategories; /* 0 <= m <= 100 */
        scanf("%u", &numCategories);
        /*
        printf("Test case #%d\n", a);
        printf("number of courses (k): %u\n", numCoursesSelected);
        printf("number of categories (m): %u\n", numCategories);
         */
        char cn[5] = "";
        unsigned i, j;
        /*
        printf("Courses:");
         */
        char coursesSelected[numCoursesSelected][5];
        for (i = 0; i < numCoursesSelected; ++i)
        {
            scanf("%s", coursesSelected[i]);
            /*
            printf(" %s", coursesSelected[i]);
             */
        }
        /*
        printf("\n");
         */
        for (i = 0; i < numCategories; ++i)
        {
            unsigned numCoursesInCategory; /* 1 <= c <= 100 */
            unsigned minNumCoursesInCategory; /* 0 <= r <= c */
            scanf("%u %u", &numCoursesInCategory, &minNumCoursesInCategory);
            /*
            printf("category #%u: total %u, minimum %u\n", i + 1, numCoursesInCategory, minNumCoursesInCategory);
            printf("Courses:");
             */
            char coursesInCategory[numCoursesInCategory][5];
            for (j = 0; j < numCoursesInCategory; ++j)
            {
                memset(cn, 0, 5);
                scanf("%s", coursesInCategory[j]);
                /*
                printf(" %s", coursesInCategory[j]);
                 */

            }
            /*
            printf("\n");
             */
            unsigned count = 0;
            for (j = 0; j < numCoursesInCategory && count < minNumCoursesInCategory && meetsRequirement; ++j)
            {
                bool isSelected = checkMembership(coursesInCategory[j], coursesSelected, numCoursesSelected);
                if (isSelected)
                {
                    ++count;
                }
            }
            if (count < minNumCoursesInCategory)
            {
                meetsRequirement = false;
            }
        }
        printf(meetsRequirement ? "yes\n" : "no\n");
        scanf("%u", &numCoursesSelected);
    }
    return 0;
}