//PROGRAM 12_2 : Binary search tree insertion and display in-order without using recursion
#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node tree;

struct stack{
    tree *r;
    struct stack *next;
};
typedef struct stack stack;
tree *root=NULL;
stack *top=NULL;

void insert();
void push();
tree * pop();
void inorder();
void inorder_wur();
int menu();

int main(){
    int ch,e,n,i;
    for(ch=menu();ch!=4;ch=menu()){
        switch(ch){
            case 1:
                printf("\nEnter how many elements to insert(n) : ");
                scanf("%d",&n);
                for(i=0;i<n;i++){
                     printf("\nEnter the element to insert : ");
                     scanf("%d",&e);
                     insert(e);
                }
                break;
            case 2:
                printf("\n\nInorder  of entered BST is : ");
                inorder(root);
                break;
            case 3:
                printf("\n\ninorder Without Using Reccursion of entered BST is : ");
                inorder_wur(root);
                break;
            case 4:
                printf("\nExiting....");
                break;
            default:
                printf("\nInvalid Input . Try again.\n");


        }
    }

    
    return 0;
}
int menu(){
    int ch;
    printf("\nBST OPERATIONS ->.\n1.INSERT.\n2.INORDER(Using reccusrion).\n3.INORDER(Without using reccusrion).\n4.EXIT");
    printf("\nEnter any choice :");
    scanf("%d",&ch);
    return ch;

}

void insert(int e){
    tree *p,*x;
    if(root==NULL){
        root=(tree *)malloc(sizeof(tree));
        root->data=e;
        root->left=NULL;
        root->right=NULL;
    }
    else{
        p=root;
        while(p!=NULL){
            x=p;
            if(e < p->data){
                p=p->left;
            }
            else{
                p=p->right;
            }
        }
        if(e > x->data){
            x->right=(tree *)malloc(sizeof(tree));
            x->right->data=e;
            x->right->left=NULL;
            x->right->right=NULL;
        }
        else{
            x->left=(tree *)malloc(sizeof(tree));
            x->left->data=e;
            x->left->left=NULL;
            x->left->right=NULL;
        }
    }
}

void push(tree *t){
    stack *temp=(stack *)malloc(sizeof(stack));
    temp->r=t;
    temp->next=top;
    top=temp;
}
tree * pop(){
    tree *t=NULL;
    if(top!=NULL){
        t=top->r;
        top=top->next;
    }
    return t;
}
void inorder(tree *r){
    
    if(r!=NULL){
        inorder(r->left);
        printf("\t%d",r->data);
        inorder(r->right);
    }
}
void inorder_wur(tree *root){
    tree *t;
    for(t=root;t!=NULL;t=t->left){
        push(t);
    }
    t=pop();
    while(t!=NULL){
        printf("\t%d",t->data);
        for(t=t->right;t!=NULL;t=t->left){
            push(t);
        }
        t=pop();
    }
}

