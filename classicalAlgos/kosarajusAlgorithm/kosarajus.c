#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#define N 100
#define I __INT_MAX__

typedef long long int ll;

typedef struct Node
{
    ll vertex;
    struct Node *next;
} Node;

void display(Node *first);
void push(struct Node *first, ll a);
bool isEmpty(struct Node *first);
ll pop(struct Node *first);

void display(Node *first)
{

    struct Node *temp;
    temp = first->next;

    while (temp)
    {
        printf("%lld ", temp->vertex);
        temp = temp->next;
    }
    printf("\n");
}

void push(struct Node *first, ll a)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->vertex = a;
    temp->next = first->next;
    first->next = temp;
}
bool isEmpty(struct Node *first)
{
    if (first->next)
        return 0;
    else
        return 1;
}

ll pop(struct Node *first)
{

    if (isEmpty(first))
        printf("The stack is empty\n");
    else
    {

        Node *p = first;
        p = p->next;
        first->next = p->next;
        ll temp = p->vertex;
        free(p);
        return temp;
    }
}

void dfsL(Node *list, ll x, ll visited[], Node *st)
{

    if (visited[x] == 0)
    {
        visited[x] = 1;
        Node *temp;
        temp = (list + x)->next;
        while (temp)
        {
            dfsL(list, temp->vertex, visited, st);
            temp = temp->next;
        }
        push(st, x);
    }
}
void dfsR(Node *list, ll x, ll visited[])
{

    if (visited[x] == 0)
    {
        visited[x] = 1;
        printf("%lld ", x);
        Node *temp;
        temp = (list + x)->next;
        while (temp)
        {
            dfsR(list, temp->vertex, visited);
            temp = temp->next;
        }
    }
}

ll main()
{
    // for kosarajus

    ll n = 0, X = 0;
    scanf("%lld %lld", &n, &X);
    Node *adjList = (Node *)malloc((n + 1) * sizeof(Node));
    Node *adjListR = (Node *)malloc((n + 1) * sizeof(Node));
    Node *stack = (Node *)malloc(sizeof(Node));
    stack->next = NULL;
    stack->vertex = 0;
    for (ll i = 0; i <= n; i++)
    {
        (adjList + i)->next = NULL;
        (adjList + i)->vertex = 0;
        (adjListR + i)->next = NULL;
        (adjListR + i)->vertex = 0;
    }
    ll temp1, temp2;
    for (ll i = 1; i <= X; i++)
    {
        scanf("%lld %lld", &temp1, &temp2);
        push(adjList + temp1, temp2);
        push(adjListR + temp2, temp1);
    }
    ll visited[N] = {0};
    for (ll i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
            dfsL(adjList, i, visited, stack);
    }
    ll visitedR[N] = {0};
    while (!isEmpty(stack))
    {
        ll i = pop(stack);
        if (visitedR[i] == 0)
        {
            dfsR(adjListR, i, visitedR);
            printf("\n");
        }
    }
    return 0;
}