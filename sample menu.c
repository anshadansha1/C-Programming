#include <stdio.h>
#include <malloc.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node tree;
tree *root;

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
			if(e < p->data)
				p=p->left;
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

} 