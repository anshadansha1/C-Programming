/*PROGRAM 9_5 :Sort the elements in a linked list using
a.changing the values (swapping the values)
b.Changing the address (Swapping the address)
*/
#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insert();
void sort_by_swap_values();
void sort_by_swap_address();
void disp();
int menu();

int main(){
    int ch,n,e,i;
    for(ch=menu();ch!=5;ch=menu()){
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
                sort_by_swap_values();
                break;
            case 4:
                sort_by_swap_address();
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
    printf("\nLINKED LIST OPERATIONS->\n1.INSERT.\n2.DISPLAY.\n3.SORT BY SWAPPING VALUES.\n4.SORT BY SWAPPING ADDRESS\n5.EXIT.");
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
void sort_by_swap_values(){
    struct node *i,*j; //Creating two pointers to structure.
    int temp;
    if(head==NULL){
        printf("\nLinked list is Empty.Sorting NOT POSSIBLE.");
    }
    else{
        for(i=head;i!=NULL;i=i->next){
            for(j=i;j!=NULL;j=j->next){
                if(i->data > j->data){
                    temp=i->data;
                    i->data=j->data;
                    j->data=temp;
                }
            }    
        }
        printf("\nSorting Successfull completed.\n");
    }

}
void sort_by_swap_address(){
    struct node *i2, *j2, *temp2;
    struct node *prev_i2 = NULL; // Pointer to the previous node of i2
    if (head == NULL) {
        printf("\nLinked list is Empty. Sorting NOT POSSIBLE.\n");
    }
    else {
        for (i2 = head; i2 != NULL; i2 = i2->next) {
            for (j2 = i2->next; j2 != NULL; j2 = j2->next) {
                if (i2->data > j2->data) {
                    // Swap the addresses (pointers) of current and index
                    temp2 = i2->next;
                    i2->next = j2->next;
                    j2->next = temp2;

                    // If head node is swapped, update the head
                    if (i2 == head) {
                        head = j2;
                    }
                    if (prev_i2 != NULL) {
                        prev_i2->next = j2;
                    }
                    
                }
               prev_i2 = j2;
               j2 = j2->next;
            }
        }
        printf("\nSorting successfully completed by swapping addresses.\n");
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
