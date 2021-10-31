#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 1000005
#define I 10000000005

typedef long long int ll;
typedef struct Node
{
    ll cost;
    ll vertex1;
    ll vertex2;
} Node;
int comparator(const void *a, const void *b)
{
    return ((*(Node *)a).cost - (*(Node *)b).cost);
}
ll parent(ll set[], ll i)
{
    if (set[i] == i)
        return i;
    else
    {
        set[i] = parent(set, set[i]);
        return set[i];
    }
}
void setUnion(ll set[], ll a, ll b)
{
    a = parent(set, a);
    b = parent(set, b);
    if (a != b)
        set[b] = a;
}
void initSet(ll set[], ll v)
{
    for (ll i = 0; i < v; i++)
        set[i] = i;
}
long long int kruskals(Node m[], ll e, ll n)
{
    long long int sum = 0;
    ll set[N];
    initSet(set, n);
    ll j = 0;
    ll counter = 0;
    qsort(m, e, sizeof(Node), comparator);
    while ((j < n - 1) && (counter < e))
    {
        ll x = m[counter].vertex1, y = m[counter].vertex2;

        if ((parent(set, x) != parent(set, y)) && (counter < e))
        {
            sum += m[counter].cost;
            setUnion(set, x, y);
            j++;
        }
        counter++;
    }
    return sum;
}
int main()
{
    ll n = 0, X = 0;
    scanf("%lld %lld", &n, &X);
    Node edges[N];
    assert(edges);
    for (ll i = 0; i < X; i++)
    {
        scanf("%lld %lld %lld", &edges[i].vertex1, &edges[i].vertex2, &edges[i].cost);
    }
    printf("%lld\n", kruskals(edges, X, n));
    return 0;
}