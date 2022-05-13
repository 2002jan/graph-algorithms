#ifndef INCIDENCE_MATRIX
#define INCIDENCE_MATRIX

#include <stdint.h>
#include "AM.h"

int IncidenceCount;
int8_t *IMatrix[AMSIZE];

void initIMatrix(int n, uint8_t directed)
{
    int i, j, k = 0;

    IncidenceCount = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (AMatrix[i][j])
                IncidenceCount += 1;

    if (!directed)
        IncidenceCount /= 2;

    for (i = 0; i < AMSIZE; i++)
        IMatrix[i] = (int8_t *)calloc(IncidenceCount, sizeof(int8_t));

    for (i = 0; i < n; i++)
    {
        if (directed)
            j = 0;
        else
            j = i;

        for (; j < n; j++)
        {
            if (AMatrix[i][j])
            {
                if (directed)
                {
                    IMatrix[i][k] = -1;
                    IMatrix[j][k] = 1;
                } else 
                    IMatrix[i][k] = IMatrix[j][k] = 1;
                
                k += 1;
            }
            
        }
    }
}

void freeIMatrix()
{
    int i;

    for (i = 0; i < AMSIZE; i++)
        free(IMatrix[i]);
}

uint8_t checkIMEdge(int i, int j)
{
    int k;

    for (k = 0; k < IncidenceCount; k++)
    {
        if (IMatrix[j][k] == 1)
            if (IMatrix[i][k] == 1 || IMatrix[i][k] == -1)
            {
                return 1;
            }
    }

    return 0;
}



#endif