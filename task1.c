#include "representations/AM.h"
#include "representations/IM.h"
#include "representations/EL.h"
#include "representations/AL.h"

#include <time.h>
#include "csvExporter.h"

int main()
{
    int runs = 20;
    int *ns;
    double *times;
    ns = (int *)calloc(runs, sizeof(int));
    times = (double *)calloc(runs, sizeof(double));

    initAMatrix(".\\data\\task1Graph.txt", AMSIZE);

    printf("Adjacency matrix\n");

    int i;

    for (i = 1; i <= 20; i++)
    {
        break;
        int k = 50 * i;

        int a, b, c = 0;

        double time = 0;

        for (c = 0; c < 10; c++)
        {

            clock_t begin = clock();

            for (a = 0; a < k; a++)
            {
                for (b = 0; b < k; b++)
                {
                    if (a == b)
                        continue;

                    checkAMEdge(a, b);
                }
            }

            clock_t end = clock();

            time += (double)(end - begin) / CLOCKS_PER_SEC * 1000;
        }

        time /= 10;

        ns[i - 1] = k;
        times[i - 1] = time;

        printf("%d: %f\n", k, time);
    }

    // exportToCsv(ns, times, runs, "AM", "Search");

    printf("\n\nAdjacency list\n");

    for (i = 1; i <= 20; i++)
    {
        break;
        int k = 50 * i;

        initAList(k, 0);

        int a, b;

        clock_t begin = clock();

        for (a = 0; a < k; a++)
        {
            for (b = 0; b < k; b++)
            {
                if (a == b)
                    continue;

                checkALEdge(a, b);
            }
        }

        clock_t end = clock();

        double time = (double)(end - begin) / CLOCKS_PER_SEC * 1000;

        ns[i - 1] = k;
        times[i - 1] = time;

        printf("%d: %f\n", k, time);

        freeAdjacencyList();
    }

    // exportToCsv(ns, times, runs, "AL", "Search");

    printf("\n\nIncidence Matrix\n");

    for (i = 1; i <= 20; i++)
    {
        break;
        int k = 50 * i;

        initIMatrix(k, 0);

        int a, b;

        clock_t begin = clock();

        for (a = 0; a < k; a++)
        {
            for (b = 0; b < k; b++)
            {
                if (a == b)
                    continue;

                checkIMEdge(a, b);
            }
        }

        clock_t end = clock();

        double time = (double)(end - begin) / CLOCKS_PER_SEC * 1000;

        ns[i - 1] = k;
        times[i - 1] = time;

        printf("%d: %f\n", k, time);

        freeIMatrix();
    }

    // exportToCsv(ns, times, runs, "IM", "Search");

    printf("\n\nEdge list\n");

    for (i = 1; i <= 20; i++)
    {
        int k = 50 * i;

        initEdgeList(k, 0);

        int a, b;

        clock_t begin = clock();

        for (a = 0; a < k; a++)
        {
            for (b = 0; b < k; b++)
            {
                if (a == b)
                    continue;

                checkELEdge(a, b);
            }
        }

        clock_t end = clock();

        double time = (double)(end - begin) / CLOCKS_PER_SEC * 1000;

        ns[i - 1] = k;
        times[i - 1] = time;

        printf("%d: %f\n", k, time);

        freeEdgeList();
    }

    exportToCsv(ns, times, runs, "EL", "Search");

    return 0;
}