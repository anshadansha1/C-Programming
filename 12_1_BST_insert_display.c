//PROGRAM 12_1 : 1.Binary search tree insertion and display Traversal using inorder, preorder and postorder using recursion

#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node tree;
tree *root;
void insert();
void inorder();
void preorder();
void postorder();
int menu();

int main(){
    int ch,e,n,i;
    for(ch=menu();ch!=5;ch=menu()){
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
                printf("\n\nInorder of entered BST is : ");
                inorder(root);
                break;
            case 3:
                printf("\n\nPreorder of entered BST is : ");
                preorder(root);
                break;
            case 4:
                printf("\n\nPostorder of entered BST is : ");
                postorder(root);
                break;
            case 5:
                printf("\nExiting....");
                break;
            default:
                printf("\nInvalid Input . Try again.\n");


        }
    }

    // insert(100);
    // insert(50);
    // insert(200);
    // insert(10);
    // insert(60);
    // insert(150);
    // insert(250);
    
    
    
    return 0;
}
int menu(){
    int ch;
    printf("\nBST OPERATIONS ->.\n1.INSERT.\n2.INORDER.\n3.PREORDER.\n4.POSTORDER.\n5.EXIT");
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
void inorder(tree *r){
    
    if(r!=NULL){
        inorder(r->left);
        printf("\t%d",r->data);
        inorder(r->right);
    }
}
void preorder(tree *r){
    
    if(r!=NULL){
        printf("\t%d",r->data);
        preorder(r->left);
        preorder(r->right);
    }
}
void postorder(tree *r){
    
    if(r!=NULL){
        postorder(r->left);
        postorder(r->right);
        printf("\t%d",r->data);
    }
}
