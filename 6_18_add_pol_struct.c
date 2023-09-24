//PROGRAM 6_18 :18.Add two polynomials using structure
#include<stdio.h>
struct poly{
    int coef;
    int expon;

};
int read();
void sort();
void disp();
int add();

int main(){
    struct poly p1[10],p2[10],p3[10];
    int n1,n2,n3;
    n1=read(p1);
    disp(p1,n1);
    n2=read(p2);
    disp(p2,n2);
    printf("\nAdding the given two polynomials............");
    n3=add(p1,p2,p3,n1,n2);
    disp(p3,n3);
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

int add(struct poly p1[10], struct poly p2[10], struct poly p3[10], int n1, int n2)
{
    int i=0, j=0, k=0;
    while (i < n1 && j < n2) 
    {
        if (p1[i].expon== p2[j].expon) 
        {
            p3[k].coef = p1[i].coef + p2[j].coef;
            p3[k].expon = p1[i].expon;
            i++;
            j++;
            k++;
        }
        else if (p1[i].expon > p2[j].expon)
        {
            p3[k].coef = p1[i].coef;
            p3[k].expon = p1[i].expon;
            i++;
            k++;
        }
        else 
        {
            p3[k].coef = p2[j].coef;
            p3[k].expon = p2[j].expon;
            j++;
            k++;
        }      
    }
    while (i < n1) 
    {
        p3[k].coef = p1[i].coef;
        p3[k].expon = p1[i].expon;
        i++;
        k++;
    }
    while (j < n2) 
    {
        p3[k].coef = p2[j].coef;
        p3[k].expon = p2[j].expon;
        j++;
        k++;
    }
    return (k);
}
