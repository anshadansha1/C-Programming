//PROGRAM 7_23 :Use calloc to read n numbers and find the mode.
#include<stdio.h>
#include<malloc.h>
int i,j;

int mode_fn(int *p,int n){
	int a[n],k,count,max_count=0;
	for(i=0;i<n;i++){
		count=0;
		for(j=i;j<n;j++){
			if(*(p+i)==*(p+j))
				count++;
		}
		if(count>=max_count){
			if(count>max_count)
				k=0;
			a[k]=*(p+i);
			max_count=count;
			k++;
		}
	}
	//when there is only one mode
	if(k==1){
		printf("\nMode of given data = %d",a[0]);
	}
	//when there is more than one modes
	else
	{
		printf("\nmodes of given data are : ");
		for(i=0;i<k;i++)
			printf("\t%d",a[i]);
	}
	
}
int main(){
	int n,*p;
	printf("\nEnter n(how much number to read) : ");
	scanf("%d",&n);
	p=(int *)calloc(n,sizeof(int));//Allocating dynamic memory using malloc()
	printf("\nEnter %d numbers -> ",n);
	for(i=0;i<n;i++){
		printf("\nEnter number %d : ",i+1);
		scanf("%d",p+i);
	}
	printf("\nEntered values are : ");
	//displaying values
	for(i=0;i<n;i++){
		printf("\t%d",*(p+i));
	}
	mode_fn(p,n);//deallocating memory
	free(p);
	return 0;
}
