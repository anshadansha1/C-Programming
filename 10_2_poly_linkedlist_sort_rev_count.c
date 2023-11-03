// PROGRAM 10_2 :Linked list using names - insert, delete, display, sort, reverse, count.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char data[20];
    struct node *next;
};
typedef struct node list;
list *head = NULL;
void insert_l(char e[20])
{
    list *t;
    if (head == NULL)
    {
        head = (list *)malloc(sizeof(list));
        strcpy(head->data, e);
        head->next = NULL;
    }
    else
    {
        t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = (list *)malloc(sizeof(list));
        strcpy(t->next->data, e);
        t->next->next = NULL;
    }
}
void display()
{
    printf("\nDisplaying Names : ");
    list *t;
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        t = head;
        while (t != NULL)
        {
            printf("\t%s", t->data);
            t = t->next;
        }
        printf("\n");
    }
}
void count()
{
    list *t;
    int c = 0;

    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        t = head;
        while (t != NULL)
        {
            c++;
            t = t->next;
        }
        printf("\nCount %d\n", c);
    }
}
void delete_l(char e[20])
{
    list *t;
    if (head == NULL)
    {
        printf("List is empty");
    }
    else if (strcmp(head->data, e) == 0)
    {   
        printf("\nDeleted : %s\n", head->data);
        head = head->next;
    }
    else
    {
        t = head;
        while (t->next != NULL && strcmp(t->next->data, e) != 0)
        {
            t = t->next;
        }
        if (t->next == NULL)
        {
            printf("\nNot found");
        }
        else if (strcmp(t->next->data, e) == 0)
        {
            printf("\nDeleted %s\n", t->next->data);
            t->next = t->next->next;
        }
    }
}
void reverseList()
{
    list *prevNode, *curNode;
    if (head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;
        prevNode->next = NULL;
        while (head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = head;
        }

        head = prevNode;
    }
    printf("\nReversed names are : ");
    display();
}
void sortList()
{
    list *current = head, *index = NULL;
    char temp[20];

    if (head == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            index = current->next;
            while (index != NULL)
            {
                if (strcmp(current->data, index->data) > 0)
                {
                    strcpy(temp, current->data);
                    strcpy(current->data, index->data);
                    strcpy(index->data, temp);
                }
                index = index->next;
            }
            current = current->next;
        }
    }
    printf("\nNames sorted successfully.\n");
}
int main()
{
    int ch = 0;
    char e[20], key[20];
    for (; ch != 7;)
    {
        printf("\nLinked List using Names Operations:\n1.Insert Name\n2.Delete\n3.Display \n4.Count\n5.Reverse\n6.Sort list\n7.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            fflush(stdin);
            printf("\nEnter the element to be inserted: ");
            gets(e);
            insert_l(e);
            break;

        case 2:
            fflush(stdin);
            printf("\nEnter the element to be delete: ");
            gets(key);
            delete_l(key);
            break;
        case 3:
            display();
            break;
        case 4:
            count();
            break;
        case 5:
            reverseList();
            break;
        case 6:
            sortList();
            break;
        case 7:
            break;
        default:
            printf("\nInvalid input.try again.");
        }
    }
    return 0;
}