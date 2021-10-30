// A C++ program for Dijkstra's single source shortest path algorithm.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#define N 100
#define I __INT_MAX__

typedef long long int ll;
void dijkstra(ll m[][N], ll vertex, ll source, ll e)
{
    ll dist[N];
    ll min = I;
    ll included[N] = {0};
    ll n;
    ll counter = 0;

    for (ll i = 1; i <= vertex; i++)
    {
        dist[i] = m[source][i];
        if (dist[i] < min)
        {
            min = dist[i];
            n = i;
        }
    }
    dist[source] = 0;

    while (counter < vertex)
    {

        counter++;
        included[source] = 1;
        included[n] = 1;

        for (ll u = 1; u <= vertex; u++)
        {
            if ((dist[n] + m[n][u] < dist[u]) && (included[u] == 0))
            {
                dist[u] = dist[n] + m[n][u];
            }
        }

        min = I;
        for (ll i = 1; i <= vertex; i++)
        {
            if ((dist[i] < min) && (included[i] == 0))
            {
                min = dist[i];
                n = i;
            }
        }
    }

    for (ll i = 1; i <= vertex; i++)
    {
        if (dist[i] != I)
            printf("%lld ", dist[i]);
        else
            printf("inf ");
    }
    printf("\n");
}
int main()
{
    ll n, e;

    scanf("%lld %lld", &n, &e);
    ll weightedEdges[3][N];
    ll adjMatrix[N][N] = {0};
    for (ll i = 0; i < e; i++)
    {
        //vertex 1, vertex 2, weight
        scanf("%lld %lld %lld", &weightedEdges[0][i], &weightedEdges[1][i], &weightedEdges[2][i]);
    }

    for (ll i = 0; i < e; i++)
    {
        ll j = weightedEdges[0][i];
        ll k = weightedEdges[1][i];
        adjMatrix[j][k] = weightedEdges[2][i];
    }

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (adjMatrix[i][j] == 0)
            {
                adjMatrix[i][j] = I;
            }
        }
    }
}