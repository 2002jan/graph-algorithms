#include "representations/AM.h"
#include "representations/IM.h"
#include "representations/EL.h"
#include "representations/AL.h"

int main() 
{
    initAMatrix(".\\data\\task1Graph.txt", AMSIZE);

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            printf("%d ", AMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n");

    initIMatrix(10, 0);

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < IncidenceCount; j++)
        {
            printf("%d ", IMatrix[i][j]);
        }
        printf("\n");
    }

    freeIMatrix();

    printf("\n\n\n");

    initEdgeList(10, 0);

    EL *current = EdgeListStart;

    while (current != NULL)
    {
        printf("%d -> %d\n", current->i, current->j);
        current = current->next;
    }

    freeEdgeList();

    printf("\n\n\n");

    initAList(10, 0);

    for(int i = 0; i < 10; i++)
    {
        ALI *current = AdjacencyList[i];

        printf("%d -> ", i);

        while (current != NULL)
        {
            printf("%d, ", current->j);
            current = current->next;
        }
        printf("\n");
    }

    freeAdjacencyList();

    return 0;
}