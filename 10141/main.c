#include <float.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int numRequirements, numProposals;
    int rfp, i, j, k; /*index for RFP, requirements, proposals, requirementMets, respectively*/
    char requirement[82], proposal[82], bestProposal[82], line[82];
    fgets(line, 82, stdin);
    sscanf(line, "%d %d", &numRequirements, &numProposals);
    float price, lowestPrice;
    int numRequirementsMet, mostRequirements;
    rfp = 0;
    while (!(numRequirements == 0 && numProposals == 0))
    {
        rfp++;
        lowestPrice = FLT_MAX;
        mostRequirements = 0;
        for (i = 0; i < numRequirements; i++)
        {
            fgets(requirement, 82, stdin);
        }
        for (j = 0; j < numProposals; j++)
        {
            fgets(proposal, 82, stdin);
            fgets(line, 82, stdin);
            sscanf(line, "%f %d", &price, &numRequirementsMet);
            for (k = 0; k < numRequirementsMet; k++)
            {
                fgets(requirement, 82, stdin);
            }
            if (numRequirementsMet > mostRequirements)
            {
                mostRequirements = numRequirementsMet;
                lowestPrice = price;
                strcpy(bestProposal, proposal);
            } else if (numRequirementsMet == mostRequirements && price < lowestPrice)
            {
                lowestPrice = price;
                strcpy(bestProposal, proposal);
            }
        }
        strtok(bestProposal, "\n");
        printf("%sRFP #%d\n%s\n", (rfp > 1 ? "\n" : ""), rfp, bestProposal);
        fgets(line, 82, stdin);
        sscanf(line, "%d %d", &numRequirements, &numProposals);
    }
    return 0;
}