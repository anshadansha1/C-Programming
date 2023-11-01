//PROGRAM 4_1 : DEFINE STRUCTURE FOR DATES(PROVIDE FUNCTIONS FOR READING,DISPLAYING AND COMPARING TWO DATES )
#include<stdio.h>

struct Date
{
    int day, month, year;
};

void readDate(struct Date *date) {

    printf("\nEnter day of date(dd) : ");
    scanf("%d",&(*date).day);
    printf("\nEnter month of date(mm) : ");
    scanf("%d",&(*date).month);
    printf("\nEnter year of date(yyyy) : ");
    scanf("%d",&(*date).year);
}

void printDate(struct Date date) {

    printf("%2d/%2d/%2d\n", date.day, date.month, date.year);
}
int isDateEqual(struct Date d1, struct Date d2 )
{
    return (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year);
}
int main() {

    struct Date d1,d2;
	printf("\nEnter details of First date (dd/mm/yyyy) \n");
    readDate(&d1);
    printf("\nEnter details of Second date (dd/mm/yyyy) \n");
    readDate(&d2);
	printf("\nFirst date : ");
    printDate(d1);
    printf("\nSecond date : ");
    printDate(d2);

    if(isDateEqual(d1,d2))
        printf("\nEntered Dates are Same");
    else
        printf("\nEntered Dates are not same");

}
