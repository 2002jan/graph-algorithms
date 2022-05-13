#ifndef EDGE_LIST
#define EDGE_LIST

#include <stdint.h>
#include "AM.h"

typedef struct EdgeList
{
    int8_t i;
    int8_t j;
    struct EdgeList *next;
} EL;

EL *EdgeListStart;
int8_t EdgeListDirected;

void initEdgeList(int n, uint8_t directed)
{
    int i, j;

    EdgeListStart = (EL*)malloc(sizeof(EL));
    EdgeListDirected = directed;

    EL * current = EdgeListStart; 
    EL * prev = NULL;

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
                current->i = i;
                current->j = j;

                prev = current;
                current = (EL*)malloc(sizeof(EL));
                prev->next = current;
                current->next = NULL;
            }
        }
    }

    free(current);

    if (prev != NULL)
    {
        prev->next = NULL;
    }
    
}

void freeEdgeList()
{
    EL *next, *current;

    current = EdgeListStart;
    
    if(current == NULL) return;

    do{
        next = current->next;
        free(current);
        current = next;
    } while (current != NULL);
    
    EdgeListStart = NULL;

    return;
}

uint8_t checkELEdge(int i, int j)
{
    EL *current;

    current = EdgeListStart;

    while (current != NULL)
    {
        if (current->i == i && current->j == j)
            return 1;

        if(!EdgeListDirected)
            if (current->i == j && current->j == i)
            return 1;

        current = current->next;
    }
        

    return 0;
}

#endif