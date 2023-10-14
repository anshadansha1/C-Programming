//PROGRAM 11_1_f :Circular Doubly linked list
#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node list;
list *head=NULL;

void insert_to_cdll();
void delete_from_cdll();
void disp();
int menu();
int main(){
int ch,n,e,i;
    for(ch=menu();ch!=4;ch=menu()){
        switch(ch){
            case 1:
                printf("\nEnter how many elements to INSERT(n) : ");
                scanf("%d",&n);
                printf("\nEnter elements to INSERT to Circular Doubly linked List : \n");
                for(i=0;i<n;i++){
                    scanf("%d",&e);
                    insert_to_cdll(e);
                }
                break;
            case 2:
                printf("\nEnter the element to DELETE : ");
                scanf("%d",&e);
                delete_from_cdll(e);
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
    printf("\nCIRCULAR DOUBLY LINKED LIST OPERATIONS->\n1.INSERT to CDLL.\n2.Delete from CDLL.\n3.DISPLAY.\n4.EXIT.");
    printf("\n\nEnter any choice : ");
    scanf("%d",&ch);
    return ch;
}
void insert_to_cdll(int e){
    list *t; //pointer to structure.
    if(head==NULL){
        head=(list *)malloc(sizeof(list)); //allocating new node to HEAD
        head->data=e;//copy data
        head->next=head;//make next of new node as head
        head->prev=head;//make prev of new node as head
    }
    else{
        t=head;
        while(t->next!=head){//traversing until t->next is head
            t=t->next;
            }
        t->next=(list *)malloc(sizeof(list)); //allocating memory to new node 
        t->next->data=e; //copying data
        t->next->next=head; //make the next of new node as head
        t->next->prev=t; //make the prev of new node as current last node(t)
        head->prev=t->next;//make the prev of first node as the new node's address 


    }
    
}
void delete_from_cdll(int e){
    list *t;
    if(head==NULL){ //case_1:list is empty
        printf("\nCircular Doubly Linked List is Empty.Cannot perform Deletion\n");
    }
    else if(head->data==e && head->next==head){//case_2:Delete first element,when there is only one element
        printf("\nDeleted element %d.\n",head->data);
        head=NULL;
    }
    else if(head->data==e){//case_3:Delete first element,when there is more than one element
        printf("\nDeleted element %d.\n",head->data);
        //No need traversal
        head->prev->next=head->next;
        head->next->prev=head->prev;
        head=head->next;

    }
    else{
        t=head->next;
        while(t!=head &&t->data!=e){//traversing
            t=t->next;
        }
        if(t==head) //case_4:Element Not found
            printf("\nElement %d NOT FOUND.Deletion Failed\n",e);
       else{
            //case_5:Delete Intermediate or Last element
            printf("\nDeleted element %d.\n",t->data);
            t->prev->next=t->next;
            t->next->prev=t->prev;
        }
    }
}

void disp(){
	list *t;
	if(head==NULL)
		printf("\nCircular Doubly Linked List is empty.\n");
	else{
		t=head;
        printf("\nDisplaying Created Circular Doubly Linked List : \n");
		do{ 
			printf("\t%d",t->data);
			t=t->next;
		}while(t!=head);
	}
}
