//PROGRAM 12_5 : Binary search tree insertion using names and display the names in ascending order using inorder traversal.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20
struct node
{
    char data[SIZE];
    struct node *left, *right;
};
typedef struct node tree;
tree *root = NULL;
void insert(char e[SIZE])
{
    tree *t, *p;
    if (root == NULL)
    {
        root = (tree *)malloc(sizeof(tree));
        strcpy(root->data, e);
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        t = root;
        while (t != NULL)
        {
            p = t;
            if (strcmp(t->data, e) == 0)
            {
                printf("Duplicate Key");
                return;
            }
            else if (strcmp(t->data, e) > 0)
            {
                t = t->left;
            }
            else
            {
                t = t->right;
            }
        }
        if (strcmp(p->data, e) > 0)
        {
            p->left = (tree *)malloc(sizeof(tree));
            strcpy(p->left->data, e);
            p->left->left = NULL;
            p->left->right = NULL;
        }
        else
        {
            p->right = (tree *)malloc(sizeof(tree));
            strcpy(p->right->data, e);
            p->right->left = NULL;
            p->right->right = NULL;
        }
    }
}
void inorder(tree *r)
{
    if (r == NULL)
        return;
    inorder(r->left);
    printf("\t%s", r->data);
    inorder(r->right);
}
int main()
{
    int ch,i,n;
    char a[50];
    while (1)
    {
        printf("\nBST operations using names : \n1.Insert\n2.Inorder\n3.Exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter how many Names to insert(n) : ");
                scanf("%d",&n);
                printf("\nEnter %d names -> \n",n);
                for(i=0;i<n;i++){
                     printf("-> ");
                     scanf("%s", a);
                     insert(a);
                }
            break;
        case 2:
            printf("\nInorder of entered names are : \n");
            inorder(root);
            break;
        case 3:
            printf("\nExiting!!!");
            exit(0);
            break;
        default:
            printf("\nInvalid Choice.Try again");
        }
    }
}