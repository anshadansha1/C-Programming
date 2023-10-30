//PROGRAM 1_1 : PROGRAMS TO DEMONSTRATE THE USE OF STORAGE CLASSES IN C.
#include <stdio.h>
int gv1,gv2=3;//golbal variable
void auto_var()
{
	printf("\n-Auto variable-\n");
	auto int au = 36;//auto variable
	printf("auto variable au = %d\n",au);
}
void static_var()
{
	static int i,k=4; //static variable
	printf("\n-Static variable-\n static value of i = %d\n",i);
	printf("static value of k = %d\n",k++);
}
void register_var()
{
	int i=10;
	register int *m = &i; //register variable
	printf("\nValue of regsiter variable  = %d\n",*m);
}

int main()
{
	int y,z=20;//z is local variable to main()
	printf("\n-Local variable-\nValues of y = %d and z = %d",y,z);
	auto_var();
	static_var();
	static_var();
	static_var();
	register_var();
	printf("\n-Global variable-\nValues of gv1 = %d and gv2 = %d",gv1,gv2);
	
	return 0;
	
}
//extern storage class main file :
//*************************************************
//#include <stdio.h>
//int count ;
//extern void write_extern();
//int main() {
//count = 5;
//write_extern();
//}
//*************************************************

//extern second file :
//#include <stdio.h>
 
//extern int count;
 
//void write_extern(void) {
//printf("count is %d\n", count);
//}
//***********************************************
//OUTPUT : count is 5
