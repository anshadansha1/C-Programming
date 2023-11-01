//PROGRAM 4_2 : DEFINE STRUCTURE FOR EMPLOYEES(search,sort and delete)
#include <stdio.h>
#include <string.h>
#define MAX 100

struct Employee {
	int eno;
	char ename[30];
	double esal;
	int dno; 
};

void insertEmp(struct Employee employees[],int i,int n){
	if(i==n){
		printf("\nMemory is full.Cannot insert");
		return ;
	}
	printf("\nEnter the details of the Employee:----");
	printf("\nEmployee Number : ");
	scanf("%d",&employees[i].eno);
	printf("Employee Name : ");
	scanf("%s",employees[i].ename);
	printf("Employee Salary : ");
	scanf("%lf",&employees[i].esal);
	printf("Department Number : ");
	scanf("%d",&employees[i].dno);
	
}

void searchEmpByNo(struct Employee employees[],int n,int eno){
	int i;
	for(i=0;i < n;i++){
		if(employees[i].eno==eno){
			printf("-------Searched Employee FOUND--------\n");
			printf("Employee Number : %d\nEmployee Name : %s\nEmployee Salary : %f\nDepartment Number : %d\n",employees[i].eno,employees[i].ename,employees[i].esal,employees[i].dno);
			return;
		}
	}
	printf("Searched Employee with empno %d NOT FOUND.\n",eno);
}

void sortEmpByName(struct Employee employees[],int n){
	int i,j;
	for(i=0;i < n - 1;i++){
		for(j=0;j < n - i - 1;j++){
			if(strcmp(employees[j].ename,employees[j+1].ename) > 0){
				struct Employee temp = employees[j];
				employees[j] = employees[j+1];
				employees[j+1]=temp;
			}
		}
	}
	
}


void sortEmpBySal(struct Employee employees[],int n){
	int i ,j;
	for (i=0; i < n - 1;i++){
		for(j=0;j < n - i -1;j++){
			if(employees[j].esal > employees[j+1].esal){
				struct Employee temp = employees[j];
				employees[j] = employees[j+1];
				employees[j+1] = temp;
				
			}
		}
	}
}

int deleteEmpByNum(struct Employee employees[],int n,int eno){
	int i,j;
	for(i=0 ; i < n ; i++){
		if(employees[i].eno==eno){
			for(j=i;j < n - 1;j++){
				employees[j] = employees[j+1];
			}
			n--;
			printf("Employee with eno: %d deleted SUCCESSFULLY.\n",eno);
			return n;
		}
	}
	printf("\nEmployee with eno : %d NOT FOUND.\n ",eno);
	return n;
}

void displayEmp(struct Employee employees[],int n){
	int i;
	printf("Employee Details : \n");
	printf("ENO\tENAME\tESALARY\t\tDNO\n");
	for(i=0;i < n ;i++){
		printf("%d\t%s\t%f\t%d\n",employees[i].eno,employees[i].ename,employees[i].esal,employees[i].dno);
		
	}
}

int main(){
	struct Employee employees[MAX];
	int n,i=0;
	
	printf("\nEnter the number of employees (MAX 100) : ");
	scanf("%d",&n);
	
	int choice,eno;
	do{
		printf("\n____________MENU__________\n");
		printf("1.INSERT \n2.SEARCH(by eno) \n3.SORT(by name) \n4.SORT(by salary) \n5.DELETE(by eno) \n6.DISPLAY \n7.EXIT \n_______\nEnter Your Choice : ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:
				insertEmp(employees,i,n);
				i++;
				break;
			
			case 2:
				printf("\nEnter the Employee number to be searched : ");
				scanf("%d",&eno);
				searchEmpByNo(employees,i,eno);
				break; 
				
			case 3:
				sortEmpByName(employees,i);
				printf("Employees sorted by name SUCCESSFULLY.\n");
				break;
				
			case 4:
				sortEmpBySal(employees,i);
				printf("Employees sorted by salary SUCCESSFULLY.\n");
				break;
				
			case 5:
				printf("\nEnter the Employee number of employee to be deleted : ");
				scanf("%d",&eno);
				i = deleteEmpByNum(employees,i,eno);
				break;
			
			case 6:
				displayEmp(employees,i);
				break;
			
			case 7:
				printf("\nExiting..........\n");
				break;
			
			default:
				printf("INVALID CHOICE.PLEASE TRY AGAIN\n");
				
		}
	}while(choice != 7 );
	return 0;
}
