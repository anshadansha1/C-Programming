//PROGRAM 11_1_d : Circular Linked Queue
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node queue;
queue *f=NULL,*r=NULL;

void enqueue_to_clq();
void dequeue_from_clq();
void disp();
int menu();
int main(){
int ch,n,e,i;
    for(ch=menu();ch!=4;ch=menu()){
        switch(ch){
            case 1:
                printf("\nEnter how many elements to ENQUEUE(n) : ");
                scanf("%d",&n);
                printf("\nEnter elements to enqueue to Circular linked Queue : \n");
                for(i=0;i<n;i++){
                    scanf("%d",&e);
                    enqueue_to_clq(e);
                }
                break;
            case 2:
                dequeue_from_clq();
                break;
            case 3:
                disp();
                break;
            case 4:
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
    printf("\nCIRCULAR LINKED QUEUE OPERATIONS->\n1.ENQUEUE to CLQ.\n2.DEQUEUE from CLQ.\n3.DISPLAY.\n4.EXIT.");
    printf("\n\nEnter any choice : ");
    scanf("%d",&ch);
    return ch;
}

void enqueue_to_clq(int e){
    queue *t; 
    if(f==NULL){
        f=(queue *)malloc(sizeof(queue)); //allocating memory to HEAD
        f->data=e;//copy data
        f->next=f;
        r=f;
    }
    else{
        t=(queue *)malloc(sizeof(queue));
        t->data=e;
        t->next=f;
        r->next=t;
        r=t;
    }
    
}
void dequeue_from_clq(){
    if(f==NULL){ //case_1:empty queue
        printf("\nQueue is empty.Dequeue not possible .\n");
    }
    else if(f->next==f){//case_2:dequeue first element when there is only one element
        printf("\nDequeued %d\n",f->data);
        f=r=NULL;  
    }
    else{
        //case_3:dequeue first element when there are several elements
        printf("\nDequeued %d\n",f->data);
        f=f->next;
        r->next=f;
    }
}
void disp(){
	struct node *t;
	if(f==NULL)
		printf("\nCircular Linked Queue is empty.\n");
	else{
		t=f;
        printf("\nDisplaying Created Circular Linked Queue : \n");
		do{
			printf("\t%d",t->data);
			t=t->next;
		}while(t!=f);
	}printf("\n");
}