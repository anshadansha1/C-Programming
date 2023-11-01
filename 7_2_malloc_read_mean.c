//PROGRAM 7_2 : Use malloc to read n integers and find the mean.
#include<stdio.h>
#include<malloc.h>
int main(){
    int n,x=0,i,*p;
    float mean;
    printf("\nEnter how much integers to enter(value for n): ");
    scanf("%d",&n);
    p=(int *)malloc(sizeof(int)*n);//Allocating dynamic memory using malloc()
    printf("\nEnter values for integers -> ");
    for(i=0;i<n;i++){
            printf("\nEnter value of integer %d: ",i+1);
            scanf("%d",p+i);
            x=x+*(p+i);
        }
    printf("\nEntered integer values are : ");
    for(i=0;i<n;i++){
            printf("\t%d",*(p+i));
        }
    mean=x/n;
    printf("\nMean of given integer values = %f",mean);
    return 0;
}