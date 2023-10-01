/*PROGRAM 9_30 :Write a program with functions to delete a node
a.From the beginning of the linked list
b.From the end of the linked list
c.The node with specified data element
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
void del_from_begin();
void del_from_end();
void del_specific();
void disp();
int menu();

int main(){
    int ch,n,e,i;
    for(ch=menu();ch!=8;ch=menu()){
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
				del_from_begin();
            	break;
            case 5:
            	del_from_end();
            	break;
            case 6:
            	printf("\nEnter the  element to delete :  ");
            	scanf("%d",&e);
            	del_specific(e);
            	break;
            case 7:
                disp();
                break;
			case 8:
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
    printf("\nLINKED LIST OPERATIONS->\n1.INSERT AT BEGINNING.\n2.INSERT AT END.\n3.INSERT AFTER A SPECIFIED ELEMENT.");
    printf("\n4.DELETE from beginning .\n5.DELETE from end.\n6.DELETE node with specific element.\n7.DISPLAY.\n8.EXIT");
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

void del_from_begin(){
	if(head==NULL)
		printf("\nLinked List is Empty.\n");
	
	else{
		printf("\nSUCCESSFULLY DELETED element %d\n\n",head->data);
		head=head->next;
	}
}
void del_from_end(){
	struct node *t;
	if(head==NULL)
		printf("\nLinked list is Empty.\n");
	else if(head->next==NULL){
		printf("\nSUCCESSFULLY DELETED element %d\n\n",head->data);
		head=NULL;	
	}
	else{
		t=head;
		while(t->next->next!=NULL){
			t=t->next;
		}
		printf("\nSUCCESSFULLY DELETED element %d\n\n",t->next->data);
		t->next=NULL;
		
	}
}

void del_specific(int e){
	struct node *t;
	if(head==NULL)
		printf("\nLinked list is Empty.\n");
	else if(head->data==e){
		printf("\nSUCCESSFULLY DELETED element %d\n\n",e);
		head=head->next;
	}
	else{
		t=head;
		while(t->next!=NULL && t->next->data!=e){
			t=t->next;
		}
		if(t->next==NULL)
			printf("\nElement NOT FOUND .\n");
		else{
			printf("\nSUCCESSFULLY DELETED element %d\n\n",e);
			t->next=t->next->next;
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

