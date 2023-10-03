//PROGRAM 9_31 :Write a program to create a singly linked list of n nodes and display it in reverse order.
#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insert();
void reverse_list();
void disp();
int menu();

int main(){
    int ch,n,e,i;
    for(ch=menu();ch!=4;ch=menu()){
        switch(ch){
            case 1:
                printf("\nEnter how many elements to insert(n) : ");
                scanf("%d",&n);
                printf("\nEnter elements to insert at the end of linked list : \n");
                for(i=0;i<n;i++){
                    scanf("%d",&e);
                    insert(e);
                }
                break;
            case 2:
                disp();
                break;
            case 3:
                reverse_list();
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
    printf("\nLINKED LIST OPERATIONS->\n1.INSERT.\n2.DISPLAY.\n3.REVERSE LIST.\n4.EXIT.");
    printf("\n\nEnter any choice : ");
    scanf("%d",&ch);
    return ch;
}
void insert(int e){
	struct node *t; //creating another pointer for traversing to last element 
	if(head==NULL){
		head=(struct node *)malloc(sizeof(struct node));  //1.allocating memory to head
		head->data=e; //2.copying element to head->data 
		head->next=NULL; //3.making next of head as NULL
	}
	else{
		t=head; 
		while(t->next != NULL) //1.Traversing upto the last element
			t=t->next;
		t->next=(struct node *)malloc(sizeof(struct node)); //2.Allocating memory to the next of last node
		t->next->data=e; //3.copying element to newly created node's data part
		t->next->next=NULL;	 //4.making next of newly created node as NULL
	}	
}
void reverse_list(){
    struct node *temp=NULL;
    struct node *temp2=NULL;
    if(head==NULL)
    {
        printf("\nLinked List is empty.Reversing NOT POSSIBLE.");
    }
    else{
        while(head!=NULL){
            temp2=head->next;
            head->next=temp;
            temp=head;
            head=temp2;
        }
        head=temp; //At last head will be null and temp will be having address of last node.So make head as temp. 
        printf("\nLinked List Reversed Successfully.\n");
    }
}

void disp(){
	struct node *t;
	if(head==NULL)
		printf("\nLinked list is empty.\n");
	else{
		t=head;
        printf("\nDisplaying Created Linked List : \n");
		while(t!=NULL){
			printf("\t%d",t->data);
			t=t->next;
		}
	}printf("\n");
}

