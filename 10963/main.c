#include <stdio.h>
#include <stdbool.h>

int main()
{
    int numCases;  /* the number of the cases following */
    scanf("%d", &numCases);
    int i, j, difference;
    int w;  /* the number of columns W of the ground to be considered */
    int y1; /* the north-most row of the gap in this column */
    int y2;  /* the south-most row of the gap in this column. Row numbers are integers between -100 and 100 inclusive*/
    bool canBeClosed;
    for (i = 0; i < numCases; i++)
    {
        scanf("\n");
        scanf("%d", &w);
        scanf("%d %d", &y1, &y2);
        difference = y1 - y2;
        canBeClosed = true;

        for (j = 1; j < w; j++)
        {
            scanf("%d %d", &y1, &y2);
            if (y1 - y2 != difference)
            {
                canBeClosed = false;
            }
        }
        printf("%s%s\n", (i > 0 ? "\n" : ""), (canBeClosed ? "yes" : "no"));
    }


    return 0;
}