#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int k;

// kd tree structure
typedef struct node
{
    int *point; // To store k dimensional data point
    struct node *left, *right;
} node;

// creating new node
struct node *create(int arr[])
{
    struct node *temp = (struct node *)calloc(1, sizeof(struct node));
    temp->point = calloc(k, sizeof(int));
    for (int i = 0; i < k; i++)
        temp->point[i] = arr[i];

    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(node *root, int point[], int depth)
{
    // if tree is empty
    if (root == NULL)
        return create(point);

    // Current dimension
    int cd = depth % k;

    // comparing points with root wrt dimension before insertion
    if (point[cd] < (root->point[cd]))
        root->left = insert(root->left, point, depth + 1);
    else
        root->right = insert(root->right, point, depth + 1);

    return root;
}

// main insert function to insert a node
struct node *insert_main(node *root, int point[])
{
    return insert(root, point, 0);
}

// checking if two arrays are equal
bool equal(int arr1[], int arr2[])
{
    // Checking if all elements of array 1 = array 2
    for (int i = 0; i < k; ++i)
        if (arr1[i] != arr2[i])
            return false;

    return true;
}

// recursive search function to find the set of data points in the tree
bool searchRec(node *root, int point[], int depth)
{

    if (root == NULL)
        return false;
    if (equal(root->point, point))
        return true;

    // current dimenson
    int cd = depth % k;

    // traversing points by comparision with root wrt dimension
    if (point[cd] < root->point[cd])
        return searchRec(root->left, point, depth + 1);

    return searchRec(root->right, point, depth + 1);
}

// main search function to search recursively
bool search(node *root, int point[])
{
    // initial depth 0
    return searchRec(root, point, 0);
}

int main()
{
    struct node *root = NULL;
    printf("Enter dimnesion : ");
    scanf("%d", &k);
    printf("\n");
    int n;
    printf("Enter number of points : ");
    scanf("%d", &n);
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        int arr[k];
        printf("Enter %d th set of data point : ", i + 1);
        printf("\n");
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &arr[i]);
        }
        root = insert_main(root, arr);
        printf("\n");
    }

    printf("Enter the set of data point you want to find : ");
    int find[k];
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &find[i]);
    }

    printf("\n");
    if (search(root, find))
    {
        printf("Found \n ");
    }
    else
    {
        printf("Not found \n");
    }
    return 0;
}