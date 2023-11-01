//PROGRAM 7_1 : Implement a) malloc , b) calloc and c) free functions 
#include<stdio.h>
#include<malloc.h>
int main(){
    int n,i,*p1,*p2;
    printf("\nDynamic memory allocation.\nEnter value for n(how many memory locations?): ");
    scanf("%d",&n);
    p1=(int *)malloc(sizeof(int)*n);//Allocating dynamic memory using malloc()
    p2=(int *)calloc(n,sizeof(int));//Allocating dynamic memory using calloc()
    
    if(p1!=NULL){
        printf("\nmalloc-Dynamic memory allocation successfull.\nEnter %d values : ",n);
        for(i=0;i<n;i++){
            printf("\nEnter p1[%d]: ",i);
            scanf("%d",p1+i);
        }
        printf("\nEntered values are : \t");
        for(i=0;i<n;i++){
            printf("%d\t",*(p1+i));
        }

    }
    else{
        printf("\nmalloc-Dynamic memory allocation Failed");

    }
    if(p2!=NULL){
        printf("\n\ncalloc-Dynamic memory allocation successfull.\nEnter %d values : ",n);
        for(i=0;i<n;i++){
            printf("\nEnter p1[%d]: ",i);
            scanf("%d",p1+i);
        }
        printf("\nEntered values are : \t");
        for(i=0;i<n;i++){
            printf("%d\t",*(p1+i));
        }
    }
    else{
        printf("\ncalloc-Dynamic memory allocation Failed");

    }
    /*The memory allocated will not be released automatically after using memory.
    The space remains there and cannot be used*/
    free(p1);//Deallocating or Releasing memory using free()
    free(p2);
    return 0;
}