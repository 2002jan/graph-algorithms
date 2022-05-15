#include "representations/AM.h"
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

    int i;

    initAMatrix("./data/task2Graph.txt", AMSIZE);

    printf("Topo sort\n\n");

    int b = 0;

    for (i = 1; i <= 20; i++)
    {
        int k = 50 * i;
    
        initAList(k, 1);

        int a, b;

        clock_t begin = clock();

        for(a = 0; a < 50; a++)
        {
            topologicalSort();
        }

        clock_t end = clock();

        double time = (double)(end - begin) / CLOCKS_PER_SEC * 1000;

        time /= 50;

        ns[i - 1] = k;
        times[i - 1] = time;

        printf("%d: %f\n", k, time);

        if (i > 1 && times[i - 1] < times[i - 2])
        {
            i -= 1;
            b += 1; 
        } else {
            b = 0;
        }

        if (b == 20 && i > 1)
        {
            b = 0;
            i -= 1;
        }
        
        

        freeAdjacencyList();
    }

    exportToCsv(ns, times, runs, "AL", "Topo");

    free(ns);
    free(times);

    return 0;
}