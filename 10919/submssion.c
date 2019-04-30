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

int main()
{
    unsigned numCoursesSelected; /* 1<= k <= 100 */
    scanf("%u", &numCoursesSelected);
    while (numCoursesSelected != 0)
    {
        bool meetsRequirement = true;
        unsigned numCategories; /* 0 <= m <= 100 */
        scanf("%u", &numCategories);
        char cn[5] = "";
        unsigned i, j;
        char coursesSelected[numCoursesSelected][5];
        for (i = 0; i < numCoursesSelected; ++i)
        {
            scanf("%s", coursesSelected[i]);
        }
        for (i = 0; i < numCategories; ++i)
        {
            unsigned numCoursesInCategory; /* 1 <= c <= 100 */
            unsigned minNumCoursesInCategory; /* 0 <= r <= c */
            scanf("%u %u", &numCoursesInCategory, &minNumCoursesInCategory);
            char coursesInCategory[numCoursesInCategory][5];
            for (j = 0; j < numCoursesInCategory; ++j)
            {
                memset(cn, 0, 5);
                scanf("%s", coursesInCategory[j]);

            }
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
