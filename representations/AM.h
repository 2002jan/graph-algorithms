#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX

#define AMSIZE 1000

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t AMatrix[AMSIZE][AMSIZE];

void initAMatrix(char *path, int n)
{

    FILE *fdata = fopen(path, "r");

    if (fdata == NULL)
    {
        printf("File not found -> \"%s\"", path);
        exit(1);
    }

    int i, j;
    char a, b;

    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n; j++)
        {
            fscanf(fdata, "%c%c", &a, &b);

            if (a == '1')
                AMatrix[i][j] = 1;
            else if (a == '0')
                AMatrix[i][j] = 0;
        }
    }

    fclose(fdata);
}

uint8_t checkAMEdge(int i, int j)
{
    return AMatrix[i][j];
}

void addAMDirectedEdge(int i, int j)
{
    AMatrix[i][j] = 1;
}

void addAMUndirectedEdge(int i, int j)
{
    addAMDirectedEdge(i, j);
    addAMDirectedEdge(j, i);
}

void removeAMDirectedEdge(int i, int j)
{
    AMatrix[i][j] = 0;
}

void removeAMUndirectedEdge(int i, int j)
{
    removeAMDirectedEdge(i, j);
    removeAMDirectedEdge(j, i);
}

#endif