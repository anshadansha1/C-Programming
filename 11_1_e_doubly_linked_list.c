//PROGRAM 11_1_e :Doubly linked list
#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node list;
list *head=NULL;

void insert_to_dll();
void delete_from_dll();
void disp();
int menu();
int main(){
int ch,n,e,i;
    for(ch=menu();ch!=4;ch=menu()){
        switch(ch){
            case 1:
                printf("\nEnter how many elements to INSERT(n) : ");
                scanf("%d",&n);
                printf("\nEnter elements to INSERT to Doubly linked List : \n");
                for(i=0;i<n;i++){
                    scanf("%d",&e);
                    insert_to_dll(e);
                }
                break;
            case 2:
                printf("\nEnter the element to DELETE : ");
                scanf("%d",&e);
                delete_from_dll(e);
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
    printf("\nDOUBLY LINKED LIST OPERATIONS->\n1.INSERT to DLL.\n2.Delete from DLL.\n3.DISPLAY.\n4.EXIT.");
    printf("\n\nEnter any choice : ");
    scanf("%d",&ch);
    return ch;
}
void insert_to_dll(int e){
    list *t; //pointer to structure.
    if(head==NULL){
        head=(list *)malloc(sizeof(list)); //allocating new node to HEAD
        head->data=e;//copy data
        head->next=NULL;//make next of new node as NULL
        head->prev=NULL;//make prev of new node as NULL
    }
    else{
        t=head;
        while(t->next!=NULL){//traversing
            t=t->next;
            }
        t->next=(list *)malloc(sizeof(list)); //allocating memory to new node 
        t->next->data=e; //copying data
        t->next->next=NULL; //make next of new node as NULL
        t->next->prev=t;//make the prev of new node as current last node 

    }
    
}
void delete_from_dll(int e){
    list *t;
    if(head==NULL){ //case_1:list is empty
        printf("\nDoubly Linked List is Empty.Cannot perform Deletion\n");
    }
    else if(head->data==e && head->next==NULL){//case_2:Delete first element,when there is only one element
        printf("\nDeleted element %d.\n",head->data);
        head=NULL;
    }
    else if(head->data==e){//case_3:Delete first element,when there is more than one element
        printf("\nDeleted element %d.\n",head->data);
        //here we no need to traverse
        head=head->next; //moving head to second element
        head->prev=NULL; //making prev as NULL
    }
    else{
        t=head->next;
        while(t!=NULL &&t->data!=e){
            t=t->next;
        }
        if(t==NULL) //case_4:Element Not found
            printf("\nElement %d NOT FOUND.Deletion Failed\n",e);
        else if(t->next==NULL){
            //case_5:Delete Last element
            printf("\nDeleted element %d.\n",t->data);
            t->prev->next=t->next;
        }else{
            //case_6:Delete Intermediate element
            printf("\nDeleted element %d.\n",t->data);
            t->prev->next=t->next;
            t->next->prev=t->prev;
        }
    }
}

void disp(){
	list *t;
	if(head==NULL)
		printf("\nDoubly Linked List is empty.\n");
	else{
		t=head;
        printf("\nDisplaying Created Doubly Linked List : \n");
		while(t!=NULL){ //traversing 
			printf("\t%d",t->data);
			t=t->next;
		}
	}
}
//DISPLAY_IN BOTH DIRECTION
// void disp(){
// 	list *t,*k;
// 	if(head==NULL)
// 		printf("\nDoubly Linked List is empty.\n");
// 	else{
// 		t=head;
//         printf("\nDisplaying Created Doubly Linked List : \n");
// 		while(t!=NULL){ //traversing 
// 			printf("\t%d",t->data);
// 			if(t->next==NULL){
//                 k=t;
//             }
//             t=t->next;
// 		}
//         printf("\n");
//         while(k!=head){
//             printf("\t%d",k->data);
//             k=k->prev;
//             if(k==head)
//                 printf("\t%d",k->data);

//         }

// 	}
// }
