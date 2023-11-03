// PROGRAM 10_1 :Polynomial using linked list - addition and multiplication.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    float coeff;
    int exp;
    struct node *next;
};
typedef struct node node;
struct node *sort(struct node *head, float co, int ex)
{
    struct node *temp;
    struct node *newP = malloc(sizeof(struct node));
    newP->coeff = co;
    newP->exp = ex;
    newP->next = NULL;

    if (head == NULL || ex > head->exp)
    {
        newP->next = head;
        head = newP;
    }
    else
    {
        temp = head;
        while (temp->next != NULL && temp->next->exp >= ex)
            temp = temp->next;
        newP->next = temp->next;
        temp->next = newP;
    }
    return head;
}
struct node *poly(struct node *head)
{
    int n, i;
    float coeff;
    int expo;
    printf("\nEnter the number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%f", &coeff);
        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &expo);
        head = sort(head, coeff, expo);
    }
    return head;
}
void disp(struct node *head)
{
    if (head == NULL)
        printf("No Polynomial.");
    else
    {
        struct node *temp;
        for (temp = head; temp->next != NULL; temp = temp->next)
        {
            printf("(%.0fx^%d)+", temp->coeff, temp->exp);
        }
        if (temp->exp == 0)
            printf("%.0f", temp->coeff);
        printf("\n");
    }
}
void polyAdd(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *sum = NULL;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->exp == ptr2->exp)
        {
            sum = sort(sum, ptr1->coeff + ptr2->coeff, ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->exp > ptr2->exp)
        {
            sum = sort(sum, ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->next;
        }
        else if (ptr1->exp < ptr2->exp)
        {
            sum = sort(sum, ptr2->coeff, ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        sum = sort(sum, ptr1->coeff, ptr1->exp);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        sum = sort(sum, ptr2->coeff, ptr2->exp);
        ptr2 = ptr2->next;
    }

    printf("\nAdded polynomial is: ");
    disp(sum);
}
node *polyMult(node *head1, node *head2, node *pro)
{
    node *ptr1 = head1;
    node *ptr2 = head2;
    if (head1 == NULL || head2 == NULL)
    {
        printf("\nNo polynomial\n");
        return NULL;
    }
    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            float coeffPro = ptr1->coeff * ptr2->coeff;
            int expoSum = ptr1->exp + ptr2->exp;
            pro = sort(pro, coeffPro, expoSum);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
        ptr2 = head2;
    }

    return pro;
}
node *add(node *pro, node *res)
{
    node *temp1, *temp2;
    temp1 = pro;
    while (temp1->next != NULL)
    {
        temp2 = temp1->next;
        while (temp2 != NULL)
        {
            if (temp1->exp == temp2->exp)
            {
                float coeffSum = temp1->coeff + temp2->coeff;
                res = sort(res, coeffSum, temp1->exp);
                temp1 = temp1->next;
                break;
            }
            else
            {
                res = sort(res, temp1->coeff, temp1->exp);
                break;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    res = sort(res, temp1->coeff, temp1->exp);
    return res;
}
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    node *pro = NULL;
    node *res = NULL;

    printf("\nEnter the First polynomial details--->\n ");
    head1 = poly(head1);

    printf("\nEnter the second polynomial--->\n ");
    head2 = poly(head2);
    disp(head1);
    disp(head2);
    polyAdd(head1, head2);
    pro = polyMult(head1, head2, pro);
    node *res2 = NULL;
    res = add(pro, res);
    res2 = add(res, res2);
    printf("\nProduct is: ");
    disp(res2);
    return 0;
}
