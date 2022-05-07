#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct AdjacencyMatrix
{
    int n;
    uint8_t **matrix;
} AM;

AM AMatrix;

void initAMatrix(char *path, int n)
{

    FILE *fdata = fopen(path, "r");

    if (fdata == NULL)
    {
        printf("File not found -> \"%s\"", path);
        exit(1);
    }

    AMatrix = (AM){n};

    AMatrix.matrix = malloc(sizeof(uint8_t) * n * n);

    int i, j;
    char a, b;

    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n; j++)
        {
            fscanf(fdata, "%c%c", &a, &b);

            if (a == '1')
                AMatrix.matrix[i][j] == 1;
            else if (a == '0')
                AMatrix.matrix[i][j] == 0;
        }
    }

    fclose(fdata);
}

void freeAMatrix()
{
    free(AMatrix.matrix);
}

#endif