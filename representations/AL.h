#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST

#include <stdint.h>
#include "AM.h"

typedef struct AdjacencyListItem
{
    int j;
    struct AdjacencyListItem *next;
} ALI;

ALI **AdjacencyList;
int AdjacencyListCount;

void addALEdge(int i, int j);

void initAList(int n, uint8_t directed)
{
    int i, j;

    AdjacencyList = (ALI **)calloc(n, sizeof(ALI *));
    AdjacencyListCount = n;

    for (i = 0; i < n; i++)
    {
        if (directed)
            j = 0;
        else
            j = i;

        for (; j < n; j++)
        {
            if (AMatrix[j][i])
            {
                if (directed)
                    addALEdge(i, j);
                else
                {
                    addALEdge(i, j);
                    addALEdge(j, i);
                }
            }
        }
    }
}

void addALEdge(int i, int j)
{
    if (AdjacencyList == NULL)
        return;

    ALI *newEdge = (ALI *)calloc(1, sizeof(ALI));

    newEdge->j = j;

    if (AdjacencyList[i] == NULL)
    {
        AdjacencyList[i] = newEdge;
        return;
    }

    ALI *current = AdjacencyList[i];

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newEdge;

    return;
}

void freeAdjacencyList()
{
    if (AdjacencyList == NULL)
        return;

    int i;

    for (i = 0; i < AdjacencyListCount; i++)
    {
        ALI *current = AdjacencyList[i], *prev;

        while (current != NULL)
        {
            prev = current;
            current = prev->next;
            free(prev);
        }
    }

    free(AdjacencyList);
}

uint8_t checkALEdge(int i, int j)
{
    ALI *current;

    current = AdjacencyList[i];

    while (current != NULL)
    {
        if (current->j == j)
            return 1;

        current = current->next;
    }

    return 0;
}

void topologicalSort()
{

     int *edgesCounts = calloc(AdjacencyListCount, sizeof(int));

    int *topOrder = calloc(AdjacencyListCount, sizeof(int));

    int i;

    ALI *current;

    for (i = 0; i < AdjacencyListCount; i++)
    {
        current = AdjacencyList[i];

        while (current != NULL)
        {
            edgesCounts[current->j] += 1;

            current = current->next;
        }
    }

    int k, noChange = 0, j = 0, startJ;

    while (!noChange)
    {

        noChange = 1;
        startJ = j;

        for (k = 0; k < AdjacencyListCount; k++)
        {
            if (edgesCounts[k] == 0)
            {
                noChange = 0;
                topOrder[j++] = k;
                edgesCounts[k] = -1;
            }
        }

        for (k = startJ; k < j; k++)
        {
            current = AdjacencyList[topOrder[k]];

            while (current != NULL)
            {
                edgesCounts[current->j] -= 1;

                current = current->next;
            }
        }
    }

    free(edgesCounts);
    free(topOrder);
}

#endif