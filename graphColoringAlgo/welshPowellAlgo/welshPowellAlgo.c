#include <stdio.h>
#include <string.h>

#define maxV 11
#define maxC 5
// a b c d e f g h i j k
int graph[maxV][maxV] = {
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0}, // a
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // b
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // c
    {0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1}, // d
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}, // e
    {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0}, // f
    {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1}, // g
    {1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1}, // h
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0}, // i
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1}, // j
    {0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0}  // k
};

int degree[maxV]; // grau
int color[maxV];  // cor dos vértices
int order[maxV];  // ordem

void sort()
{ // ordenação
    int i, j, aux;
    for (i = 0; i < maxV; i++)
    {
        for (j = maxV - 1; j > i; j--)
        {
            if (degree[order[j]] > degree[order[j - 1]])
            {
                aux = order[j];
                order[j] = order[j - 1];
                order[j - 1] = aux;
            }
        }
    }
}

void init()
{
    int i;
    for (i = 0; i < maxV; i++)
    {
        degree[i] = 0;
    }
    for (i = 0; i < maxV; i++)
    {
        order[i] = i;
    }
    for (i = 0; i < maxV; i++)
    {
        color[i] = 0;
    }
}

void countDegree()
{
    int i, j;
    init();
    for (i = 0; i < maxV; i++)
    {
        degree[i] = 0;
    }
    for (i = 0; i < maxV; i++)
    {
        order[i] = i;
    }

    for (i = 0; i < maxV; i++)
    {
        for (j = 0; j < maxV; j++)
        {
            if (graph[i][j] == 1)
                degree[i]++;
        }
    }
    sort();
}

void printWP()
{
    int i;
    printf("Vértices em ordem de 0 a %d \n\n", maxV - 1);
    for (i = 0; i < maxV; i++)
    {
        printf("Vértice %d tem grau %d e a cor dele é %d\n", i, degree[i], color[i]);
    }
    printf("\n-----------------------------------------\n");
    printf("Vértices ordenados por grau\n\n");
    for (i = 0; i < maxV; i++)
    {
        printf("Vértice %d tem grau %d e a cor dele é %d\n", order[i], degree[order[i]], color[order[i]]);
    }
}

void welshPowell()
{
    int i, j, k, o;
    int vColor[maxC];
    countDegree();
    for (i = 0; i < maxV; i++)
    { // percorrer a ordem dos vetores
        o = order[i];
        memset(vColor, 0, sizeof(vColor));
        for (j = 0; j < maxV; j++)
        { // percorrer as adjacencias
            if (graph[o][j] == 1 && color[j] != 0)
            { // verificar a cor do vizinho
                vColor[color[j]] = 1;
            }
        }
        k = 1;
        while (color[o] == 0)
        {
            if (vColor[k] == 0)
            {
                color[o] = k;
            }
            k++;
        }
    }
    printWP();
}

int main()
{
    welshPowell();
    return 0;
}