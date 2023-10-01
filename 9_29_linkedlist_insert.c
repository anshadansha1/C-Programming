/*PROGRAM 9_29 :Write a program with functions  to insert a new node 
a.at the beginning of a Singly Linked List.
b.At the end of the linked list
c.after a specified element in a linked list.
*/
#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;

void insert_at_begin();
void insert_at_end();
void insert_after_el();
void disp();
int menu();

int main(){
    int ch,n,e,i;
    for(ch=menu();ch!=5;ch=menu()){
        switch(ch){
            case 1:
                printf("\nEnter element to insert at the beginning of linked list : ");
            	scanf("%d",&e);
            	insert_at_begin(e);
            	break;
            case 2:
                printf("\nEnter how many elements to insert(n) : ");
                scanf("%d",&n);
                printf("\nEnter elements to insert at the end of linked list : \n");
                for(i=0;i<n;i++){
                    scanf("%d",&e);
                    insert_at_end(e);
                }
                break;
            case 3:
            	printf("\nEnter the element to search : ");
            	scanf("%d",&e);
            	insert_after_el(e);
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
    printf("\nLINKED LIST OPERATIONS->\n1.INSERT AT BEGINNING.\n2.INSERT AT END.\n3.INSERT AFTER A SPECIFIED ELEMENT.\n4.DISPLAY.\n5.EXIT");
    printf("\n\nEnter any choice : ");
    scanf("%d",&ch);
    return ch;
}
void insert_at_begin(int e){
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	t->data=e;
	t->next=head;
	head=t;
}
void insert_at_end(int e){
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

void insert_after_el(int e){
	struct node *t,*s;
	if(head==NULL)
		printf("\nLinked list is Empty.\n");
	else{
		
		t=head;
		while(t!=NULL && t->data!=e)
			t=t->next;
		if(t==NULL)
			printf("\n\nElement %d NOT FOUND.\n",e);
		else if(t->data==e){
			printf("\nElement found.\nEnter the element to insert after %d :",e);
			int new_e;
			scanf("%d",&new_e);
			s=(struct node *)malloc(sizeof(struct node));
			s->data=new_e;
			s->next=t->next;
			t->next=s;
		}
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

