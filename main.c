#include "representations/AM.h"
#include "representations/IM.h"

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

    return 0;
}