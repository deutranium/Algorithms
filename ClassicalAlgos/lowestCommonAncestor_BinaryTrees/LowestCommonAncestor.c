//Lowest Common Ancestor - Given a Binary tree, not a BST, and two user defined node values, find the Lowest common ancestor.
//The following Input/ Output will clarify further :
/*
    Given Binary Tree :       3
                            /   \
                           6     8
                          / \     \
                         2  11     13
                            /\    /
                           9  5  7
    Note :For n1 = 2, n2 = 5, Lowest Common Ancestor is 6
          For n1 = 9, n2 = 5, Lowest Common Ancestor is 11
    OUTPUT :
        In-Order Traversal : 2, 6, 9, 11, 5, 3, 8, 7, 13,
        Enter Node 1 value : 2
        Enter Node 2 value : 5
        Lowest Common Ancestor of n1 and n2 : 6

*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *Create()
{
    struct Node *temp = NULL;
    int x; //data;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Heap Full\n");
        return NULL;
    }
    printf("Enter Node value : ");
    scanf("%d", &x);
    if (x == -1)
        return NULL;

    temp->data = x;
    printf("Enter the left child of %d, ", x);
    temp->left = Create();
    printf("Enter the right child of %d, ", x);
    temp->right = Create();

    return temp;
}
void InOrder(struct Node *p)
{
    if (p)
    {
        InOrder(p->left);
        printf("%d, ", p->data);
        InOrder(p->right);
    }
    return;
}
struct Node *LCA(struct Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    struct Node *left = LCA(root->left, n1, n2);
    struct Node *right = LCA(root->right, n1, n2);
    if (left && right)
        return root;
    if (!left && !right)
        return NULL;

    return (left != NULL) ? left : right;
}
int main()
{
    struct Node *root = NULL;
    root = Create();
    printf("\nIn-Order Traversal : ");
    InOrder(root);
    // struct Node *n1 = NULL, *n2 = NULL;
    // n1 = (struct Node *)malloc(sizeof(struct Node));
    // n2 = (struct Node *)malloc(sizeof(struct Node));
    int n1, n2;
    printf("\nEnter Node 1 value : ");
    scanf("%d", &n1);
    printf("Enter Node 2 value : ");
    scanf("%d", &n2);
    struct Node *result = NULL;
    result = LCA(root, n1, n2);
    printf("Lowest Common Ancestor of n1 and n2 : %d\n", result->data);
    free(root);
    return 0;
}