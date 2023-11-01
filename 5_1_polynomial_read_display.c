//PROGRAM 5_1 : READ A POLYNOMIAL AND DISPLAY IT USING ARRAY
#include <stdio.h>

int read();
void sort();
void disp();

int main(){
	int n=0,coef[20],expon[20];
	n=read(coef,expon,n);
	disp(coef,expon,n);
	return 0;
}

int read(int coef[],int expon[],int n){
	int i;
	printf("\nEnter the number of terms in the expression : ");
	scanf("%d",&n);
	printf("\n________Enter the polynomial expression__________\n");
	for(i=0;i<n;i++){
		printf("\nEnter details of term %d :-\nCoefficient : ",i+1);
		scanf("%d",&coef[i]);
		printf("\nExponent : ");
		scanf("%d",&expon[i]);
	}
	return n;
	
}

void sort(int coef[],int expon[],int n){
	int i,j,t1,t2;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(expon[j]<expon[j+1]){
				t1=expon[j];
				expon[j]=expon[j+1];
				expon[j+1]=t1;
				
				t2=coef[j];
				coef[j]=coef[j+1];
				coef[j+1]=t2;
			}
		}
	}
}

void disp(int coef[],int expon[],int n){
	int i;
	sort(coef,expon,n);
	printf("\nPolynomial is : ");
	for(i=0;i<n;i++){
		if(expon[i]==0){
			if(coef[i]<0){
				printf(" - %d",-coef[i]);
			}
			else if(coef[i]>0){
				if(i==0){
					printf("%d",coef[i]);
				}else{
					printf(" + %d",coef[i]);
				}
			}
		}
		else if(expon[i]>0){
			if(coef[i]<0){
				printf(" - %dx^%d",-coef[i],expon[i]);
			}
			else if(coef[i]>0){
				if(i==0){
					printf("%dx^%d",coef[i],expon[i]);
				}else{
					printf(" + %dx^%d",coef[i],expon[i]);
				}
			}
		}
		else{
			if(coef[i]<0){
				printf(" - %dx^%d",-coef[i],-expon[i]);
			}else if(coef[i]>0){
				if(i==0){
				printf("%d/x^%d",coef[i],-expon[i]);
				}
			}else{
				printf(" + %d/x^%d",coef[i],-expon[i]);
			}
		}
	}
}



