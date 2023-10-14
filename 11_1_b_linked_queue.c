//PROGRAM 11_1_b : Linked Queue
#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node queue;
enum op{enqueue=1,dequeue,display,EXIT};//enum is used to assign names to integral constants
queue *f=NULL,*r=NULL;

void enqueue_to_linkedqueue();
void dequeue_from_linkedqueue();
void disp();
int menu();
int main(){
    int ch,e;
    for(ch=menu();ch!=EXIT;ch=menu()){
        switch(ch){
            case enqueue:
                    printf("\nEnter the element to enqueue: ");
                    scanf("%d",&e);
                    enqueue_to_linkedqueue(e);
                    break;
            case dequeue:
                    dequeue_from_linkedqueue();
                    break;
            case display:
                    disp();
                    break;
            case EXIT:
                    printf("\nExiting......");
                    break;
            default:
                    printf("\nInvalid Input.Try Again.\n");


        }

    }
    return 0;
}
int menu(){
    int ch;
    printf("\nLinked Queue Operations ->\n1.ENQUEUE.\n2.DEQUEUE.\n3.DISPLAY.\n4.EXIT.\n");
    printf("\n\nEnter any choice : ");
    scanf("%d",&ch);
    return ch;
}
void enqueue_to_linkedqueue(int e){
    queue *t=(queue *)malloc(sizeof(queue));//allocate a new node
    t->data=e;//copy the data to new node
    t->next=NULL;//make next of new node as NULL
    if(f==NULL){
        //assign new node address to f and r
        f=t;
        r=t;
    }
    else{
        r->next=t;
        r=t;
    }
}
void dequeue_from_linkedqueue(){
    if(f==NULL){
        printf("\nQueue is empty.Dequeue not possible .\n");
    }
    else{
        printf("\nDequeued %d",f->data);
        f=f->next;
        if(f==NULL){
            r=NULL;
        }
    }
}
void disp(){
	struct node *t;
	if(f==NULL)
		printf("\nLinked Queue is empty.\n");
	else{
		t=f;
        printf("\nDisplaying Created Linked Queue : \n");
		while(t!=NULL){
			printf("\t%d",t->data);
			t=t->next;
		}
	}printf("\n");
}