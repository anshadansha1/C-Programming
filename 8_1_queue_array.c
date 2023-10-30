//PROGRAM 8_1 :Implement Queue using array.
#include<stdio.h>
#define MAX_V 100 
int q[MAX_V];
int f=-1,r=-1,i;

void enqueue();
void dequeue();
void disp();
int menu();


int main(){
    int ch,n;
    for(ch=menu();ch!=4;ch=menu()){
        switch(ch){
            case 1:
                printf("\nEnter how many elements to enqueue(n) : ");
                scanf("%d",&n);
                for(i=0;i<n;i++){
                    enqueue();
                }
                break;
            case 2:
				dequeue();
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
    printf("\nQUEUE OPERATIONS->\n1.ENQUEUE.\n2.DEQUEUE.\n3.DISPLAY.\n4.EXIT");
    printf("\n\nEnter any choice : ");
    scanf("%d",&ch);
    return ch;
}

void enqueue(){
	if(r+1==MAX_V){
		printf("\nQUEUE IS FULL.CANNOT PERFORM ENQUEUE\n");
	}
	else{
		if(f==-1){
			f=0;
		}
		printf("\nEnter the value to ENQUEUE : ");
		scanf("%d",&q[++r]);//incrementing value of r each time when enqueue happens
	}
}
void dequeue(){
	if(f==-1){
		printf("\nQUEUE IS EMPTY.CANNOT PERFORM DEQUEUE");
		
	}else{
		printf("\nDEQUEUED element : %d ",q[f]);
		//When there is only one element
		if(f==r){
			f=r=-1;
		}
		//when there is more than one element in queue
		else{
			for(i=0;i<r;i++){
				q[i]=q[i+1];
			}
			r--;//decrement value of r when dequeue happens
		}
	}
}
void disp(){
	if(f==-1){
		printf("\nQUEUE IS EMPTY.");
	}
	else{
			printf("\nDisplaying elements in QUEUE : ");
			for(i=0;i<=r;i++){
				printf("\t%d",q[i]);
			}
	}
}
