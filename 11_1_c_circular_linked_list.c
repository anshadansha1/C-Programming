//PROGRAM 11_1_c : Circular Linked List

#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node list;
list *head=NULL;

void insert_to_cll();
void delete_from_cll();
void disp();
int menu();
int main(){
int ch,n,e,i;
    for(ch=menu();ch!=4;ch=menu()){
        switch(ch){
            case 1:
                printf("\nEnter how many elements to INSERT(n) : ");
                scanf("%d",&n);
                printf("\nEnter elements to INSERT to Circular linked List : \n");
                for(i=0;i<n;i++){
                    scanf("%d",&e);
                    insert_to_cll(e);
                }
                break;
            case 2:
                printf("\nEnter the element to DELETE : ");
                scanf("%d",&e);
                delete_from_cll(e);
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
    printf("\nCIRCULAR LINKED LIST OPERATIONS->\n1.INSERT to CLL.\n2.Delete from CLL.\n3.DISPLAY.\n4.EXIT.");
    printf("\n\nEnter any choice : ");
    scanf("%d",&ch);
    return ch;
}
void insert_to_cll(int e){
    list *t; //pointer to structure.
    if(head==NULL){
        head=(list *)malloc(sizeof(list)); //allocating memory to HEAD
        head->data=e;//copy data
        head->next=head;//make next of head as head ,to make a circular link 
    }
    else{
        t=head;
        while(t->next!=head){//traversing until t->next becomes head ,since it is CLL
            t=t->next;
            }
        t->next=(list *)malloc(sizeof(list)); //allocating memory to new node 
        t->next->data=e; //copying data to new node
        t->next->next=head; //making next of new node as head

    }
    
}
void delete_from_cll(int e){
    list *t;
    if(head==NULL){ //case_1:list is empty
        printf("\nCircular Linked List is Empty.Cannot perform Deletion\n");
    }
    else if(head->data==e && head->next==head){//case_2:Delete first element,when there is only one element
        printf("\nDeleted element %d.\n",head->data);
        head=NULL;
    }
    else if(head->data==e){//case_3:Delete first element,when there is more than one element
        t=head;
        while(t->next!=head){//traversing 
            t=t->next;
        }
        printf("\nDeleted element %d.\n",head->data);
        t->next=head->next; //updating last node address to next of head
        head=head->next;
    }
    else{
        t=head;
        while(t->next!=head &&t->next->data!=e){
            t=t->next;
        }
        if(t->next==head) //case_4:Element Not found
            printf("\nElement %d NOT FOUND.Deletion Failed\n",e);
        else{ 
            printf("\nDeleted element %d.\n",t->next->data);
            t->next=t->next->next;//case_5:Delete intermediate or Last element
        }
    }
}

void disp(){
	list *t;
	if(head==NULL)
		printf("\nCircular Linked List is empty.\n");
	else{
		t=head;
        printf("\nDisplaying Created Circular Linked List : \n");
		while(t->next!=head){ //traversing until t->next becomes head
			printf("\t%d",t->data);
			t=t->next;
		}
	}printf("\t%d\n",t->data); //To display the last element.
}
//DISPLAY_2
// void disp(){
// 	list *t;
// 	if(head==NULL)
// 		printf("\nCircular Linked List is empty.\n");
// 	else{
// 		t=head;
//         printf("\nDisplaying Created Circular Linked List : \n");
// 		do{ 
// 			printf("\t%d",t->data);
// 			t=t->next;
// 		}while(t!=head);
// 	}
// }