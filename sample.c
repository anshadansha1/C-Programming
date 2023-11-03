struct node *i = head;
struct node *t1 = head;
while(i->next != NULL)
{
struct node *t2 = i;
struct node *j = i->next;
while(j != NULL)
{
if(i->data > j->data)
{
t2->next = j->next;
if(head == i)
t1 = head = j;
else
t1->next = j;
j->next = i;
i = t1;
}
else
t2 = j;
j = j->next;
}
t1 = i;
i = i->next;
}