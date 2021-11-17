#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int k;

// custom stack like data structure to store nearest neighbors
struct node_in
{
    int *point;
};
struct node_s
{
    struct node_in *info;
    struct node_s *next;
};
struct node_s *top;
struct node_s *top1;
struct node_s *temp;

int count = 0;

struct node_in *create_data(int arr[])
{
    struct node_in *temp = (struct node_in *)calloc(1, sizeof(struct node_in));
    temp->point = calloc(k, sizeof(int));
    for (int i = 0; i < k; i++)
        temp->point[i] = arr[i];

    return temp;
}
void push(int arr[])
{
    if (top == NULL)
    {
        top = (struct node_s *)malloc(1 * sizeof(struct node_s));
        top->next = NULL;
        top->info = create_data(arr);
    }
    else
    {
        temp = (struct node_s *)malloc(1 * sizeof(struct node_s));
        temp->next = top;
        temp->info = create_data(arr);
        top = temp;
    }
    count++;
}
void pop()
{
    top1 = top;

    if (top1 == NULL)
    {
        printf("\n Error : Trying to pop from empty stack \n");
        return;
    }

    for (int i = 0; i < k; i++)
    {
        printf("%d ", top1->info->point[i]);
    }
    printf("\n");
    top1 = top1->next;
    top = top1;
    count--;
}
void display()
{
    top1 = top;

    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }

    while (top1 != NULL)
    {
        for (int i = 0; i < k; i++)
            printf("%d ", top1->info->point[i]);
        printf("\n");
        top1 = top1->next;
    }
}

// kd tree structure
typedef struct node
{
    int *point; // To store k dimensional point
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

bool search(node *root, int point[], int depth)
{

    if (root == NULL)
        return false;
    if (equal(root->point, point))
        return true;

    // current dimenson
    int cd = depth % k;
    push(root->point);

    printf("\n");
    // traversing points by comparision with root wrt dimension
    if (point[cd] < root->point[cd])
        return search(root->left, point, depth + 1);

    return search(root->right, point, depth + 1);
}

// main search function to search recursively
bool search_main(node *root, int point[])
{
    // initial depth 0
    return search(root, point, 0);
}
int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    // comment the below line if you want an interactive console
    freopen("input.txt", "r", stdin);

    // for interactive console
    struct node *root = NULL;
    printf("Enter dimnesion : ");
    scanf("%d", &k);
    printf("\n");

    int n;
    printf("Enter number of points : ");
    scanf("%d", &n);
    printf("\n");

    int neighbours;
    printf("Enter number of neighbours : ");
    scanf("%d", &neighbours);
    printf("\n");
    int target[n];
    for (int i = 0; i < n; i++)
    {
        int arr[k];
        printf("Enter %d th set of data point : ", i + 1);
        printf("\n");
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &target[i]);
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
    if (search_main(root, find))
    {
        printf("Found \n ");
    }
    else
    {
        printf("Not found \n");
    }

    int req = min(neighbours, count);
    printf("The %d closest data points related to this data point are : \n", neighbours);
    for (int i = 0; i < req; i++)
    {
        pop();
    }
    return 0;
}
