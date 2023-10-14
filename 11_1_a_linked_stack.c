//PROGRAM 11_1_a : Linked Stack
#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node stack;
stack *top=NULL; //pointer top pointing to structure Stack.

void push_to_linkedstack();
void pop_from_linkedstack();
void peek_from_linkedstack();
void disp();
int menu();
int main(){
int ch,n,e,i;
    for(ch=menu();ch!=5;ch=menu()){
        switch(ch){
            case 1:
                printf("\nEnter how many elements to PUSH(n) : ");
                scanf("%d",&n);
                printf("\nEnter elements to PUSH to linked Stack : \n");
                for(i=0;i<n;i++){
                    scanf("%d",&e);
                    push_to_linkedstack(e);
                }
                break;
            case 2:
                pop_from_linkedstack();
                break;
            case 3:
                peek_from_linkedstack();
                break;
            case 4:
                disp();
                break;
            case 5:
            	printf("\nExiting.....\n");
                break;
            default:
                printf("\nInvalid Input.TRY AGAIN\n");
                break;
                
        }
    }
	return 0;	
}

int menu()
{
    int ch;
    printf("\nLINKED STACK OPERATIONS->\n1.PUSH to Linked Stack.\n2.POP from Linked Stack.\n3.PEEK from Linked stack\n4.DISPLAY.\n5.EXIT.");
    printf("\n\nEnter any choice : ");
    scanf("%d",&ch);
    return ch;
}
void push_to_linkedstack(int e){
    stack *t; //creating another pointer to structure stack
    t=(stack *)malloc(sizeof(stack)); //allocating memory to new node 
    t->data=e; //copying data to new node
    t->next=top; //make the next of new node as current top. 
    top=t; //assign the address of new node to top.
}
void pop_from_linkedstack(){
    if(top==NULL){
        printf("\nLinked Stack is Empty.Cannot perform POP\n");
    }
    else{
        printf("\nPoped element %d.\n",top->data);
        top=top->next;
    }
}
void peek_from_linkedstack(){
    if(top==NULL){
        printf("\nLinked Stack is Empty.Cannot perform PEEK\n");
    }
    else{
        printf("\nPEEKed element is  %d.\n",top->data);
    }
}
void disp(){
	struct node *t;
	if(top==NULL)
		printf("\nLinked Stack is empty.\n");
	else{
		t=top;
        printf("\nDisplaying Created Linked Stack : \n");
		while(t!=NULL){
			printf("\t%d",t->data);
			t=t->next;
		}
	}printf("\n");
}
