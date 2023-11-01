//PROGRAM 6_1 : Read a polynomial and display it using structure array 
#include<stdio.h>
struct poly{
    int coef;
    int expon;

};
int read();
void sort();
void disp();

int main(){
    struct poly p[10];
    int n;
    n=read(p);
    disp(p,n);
    return 0;
}

int read(struct poly p[]){
    int i,n;
	printf("\nEnter the number of terms in the expression : ");
	scanf("%d",&n);
	printf("\n________Enter the polynomial expression__________\n");
	for(i=0;i<n;i++){
		printf("\nEnter details of term %d :-\nCoefficient : ",i+1);
		scanf("%d",&p[i].coef);
		printf("\nExponent : ");
		scanf("%d",&p[i].expon);
	}
	return n;
}

void sort(struct poly p[],int n){
	int i,j;
    struct poly temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(p[j].expon<p[j+1].expon){
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
}

void disp(struct poly p[],int n){
    int i;
	sort(p,n);
	printf("\nPolynomial is : ");
	for(i=0;i<n;i++){
		if(p[i].expon==0){
			if(p[i].coef<0){
				printf(" - %d",-p[i].coef);
			}
			else if(p[i].coef>0){
				if(i==0){
					printf("%d",p[i].coef);
				}else{
					printf(" + %d",p[i].coef);
				}
			}
		}
		else if(p[i].expon>0){
			if(p[i].coef<0){
				printf(" - %dx^%d",-p[i].coef,p[i].expon);
			}
			else if(p[i].coef>0){
				if(i==0){
					printf("%dx^%d",p[i].coef,p[i].expon);
				}else{
					printf(" + %dx^%d",p[i].coef,p[i].expon);
				}
			}
		}
		else{
			if(p[i].coef<0){
				printf(" - %dx^%d",-p[i].coef,-p[i].expon);
			}else if(p[i].coef>0){
				if(i==0){
				printf("%d/x^%d",p[i].coef,-p[i].expon);
				}
			}else{
				printf(" + %d/x^%d",p[i].coef,-p[i].expon);
			}
		}
	}

}
