//PROGRAM 7_25 :Use realloc to implement varchar for any length.
#include<stdio.h>
#include<malloc.h>

int main(){

    int i=0;
    char *ptr,*ptr_new,ch;
    printf("\nEnter a string : ");
    ptr=(char *)malloc(sizeof(char)*2);

    do{
        scanf("%c",&ch);
        *(ptr+i)=ch;
        i++;
        ptr_new =(char *)realloc(ptr,sizeof(char)*(i+2));
    }while(ch !='\n');
    
    *(ptr+i)='\0';//adding \0 to make it as string
    printf("\nThe entered string is : %s",ptr_new);
    return 0;

}