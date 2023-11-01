//PROGRAM 6_4 : Multiply two polynomials 
#include<stdio.h>
struct poly
{
	int coeff;
	int expo;
};
int read(struct poly p[])
{
	int i,n;
	printf("\nEnter the number of terms in the expression: ");
	scanf("%d",&n);
	printf("\nEnter a polynomial expression:\n------------------------");
	for(i=0;i<n;i++)
	{
		printf("\nEnter term %d:\nCoefficient: ",i+1);
		scanf("%d",&p[i].coeff);
		printf("\nExponent: ");
		scanf("%d",&p[i].expo);
	}
	return n;
}
void sort(struct poly p[], int n)
{
    int i,j;
	struct poly temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].expo<p[j+1].expo)
			{
			    temp=p[j];
			    p[j]=p[j+1];
			    p[j+1]=temp;
			}
		}
	}
}
void disp(struct poly p[], int n)
{
	int i;
	sort(p,n);
	printf("\nPolynomial is: ");
	for(i=0;i<n;i++)
	{
        if(p[i].expo==0)
        {
            if(p[i].coeff<0)
	            printf(" - %d",-p[i].coeff);
	        else if(p[i].coeff>0)
            {
                if(i==0)
                    printf("%d",p[i].coeff);
	            else
	                printf(" + %d",p[i].coeff);   
	        }
        }
        else if(p[i].expo>0)
	    {
	        if(p[i].coeff<0)
	            printf(" - %dx^%d",-p[i].coeff,p[i].expo);
		    else if(p[i].coeff>0)
		    {
		        if(i==0)
	                printf("%dx^%d",p[i].coeff,p[i].expo);
	            else
	                printf(" + %dx^%d",p[i].coeff,p[i].expo);
		    }
	    }
	    else 
	    {
	        if(p[i].coeff<0)
		        printf(" - %d/x^%d",-p[i].coeff,-p[i].expo);
		    else if(p[i].coeff>0)
		    {
		        if(i==0)
	                printf("%d/x^%d",p[i].coeff,-p[i].expo);
	            else
	                printf(" + %d/x^%d",p[i].coeff,-p[i].expo);
		    }
	    }
	}
}
void multiply(struct poly p1[], struct poly p2[], struct poly p3[], int n1, int n2)
{
    int n3,i,j,k=0;
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            p3[k].expo=p1[i].expo+p2[j].expo;
            p3[k].coeff=p1[i].coeff*p2[j].coeff;
            k++;
        }
    }
    n3=k;
    i=0;
    sort(p3,n3);
    while(i<n3-1)
    {
        if(p3[i].expo==p3[i+1].expo)
        {
            p3[i].coeff=p3[i].coeff+p3[i+1].coeff;
            j=i+1;
            while(j<n3-1)
            {
                p3[j].expo=p3[j+1].expo;
                p3[j].coeff=p3[j+1].coeff;
                j++;
            }
            n3--;
        }
        else
        {
            i++;
        }
    }
    disp(p3,n3);
}
int main()
{
	struct poly p1[10], p2[10], p3[20];
	int n1, n2;
	printf("\nEnter the details of First Polynomial--->\n");
	n1=read(p1);
	disp(p1,n1);
	printf("\n\nEnter the details of  Second Polynomial--->\n");
	n2=read(p2);
	disp(p2,n2);
	printf("\nProduct\n-------");
	multiply(p1,p2,p3,n1,n2);
	return 0;
}