#include <stdio.h>
#include <string.h>

int main()
{
    int numTestCases;
    int i; /*index for test cases*/
    char url[101], urls[10][101];
    int j; /*index for urls*/
    int relevance, maxRelevance, relevances[10];
    scanf("%d", &numTestCases);
    for (i = 1; i <= numTestCases; i++)
    {
        maxRelevance = 0;
        for (j = 0; j < 10; j++)
        {
            scanf("%s %d", url, &relevance);
            strcpy(urls[j], url);
            relevances[j] = relevance;
            if (relevance > maxRelevance)
            {
                maxRelevance = relevance;
            }
        }
        printf("Case #%d:\n", i);
        for (j = 0; j < 10; j++)
        {
            relevance = relevances[j];
            if (maxRelevance == relevance)
            {
                strcpy(url, urls[j]);
                printf("%s\n", url);
            }
        }
    }
    return 0;
}