//PROGRAM 5_2 : ADD TWO POLYNOMIALS USING ARRAY
#include <stdio.h>
int n1,n2,n3,coef1[20],expon1[20],coef2[20],expon2[20],coef3[20],expon3[20];

int read();
void sort();
void disp();
void add();

int main(){
	int n=0;
	n1=read(coef1,expon1,n);
	sort(coef1,expon1,n1);
	disp(coef1,expon1,n1);
	printf("\nEnter details of other polynomial to add ---->\n");
	n2=read(coef2,expon2,n);
	sort(coef2,expon2,n2);
	disp(coef2,expon2,n2);
	
	printf("\n\nNow , Adding two polynomials :  ");
	add();
	sort(coef3,expon3,n3);
	disp(coef3,expon3,n3);
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

void add(){
	int i=0,j=0,k=0;
	while(i<n1 && j<n2){
		if(expon1[i] == expon2[j])
		{
			coef3[k] = coef1[i] + coef2[j];
			expon3[k] = expon1[i];
			i++;
			j++;
			k++;
		}
		else if(expon1[i] > expon2[j]){
			coef3[k] = coef1[i];
			expon3[k] = expon1[i];
			i++;
			k++;
		}
		else
		{
			coef3[k] = coef2[j];
			expon3[k] = expon2[j];
			j++;
			k++;
		}
	}
	while(i<n1){
		coef3[k] = coef1[i];
		expon3[k] = expon1[i];
		i++;
		k++;
	}
	while(j<n2){
		coef3[k] = coef2[j];
		expon3[k] = expon2[j];
		j++;
		k++;
	}
	n3=k;
}

