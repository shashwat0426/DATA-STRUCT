
#include <stdio.h>
#include <malloc.h>
#define ISEMPTY printf("\nEMPTY LIST:");

struct node
{
    int value;
    struct node *next;
};
typedef struct node snode;
snode* create_node(int);;
void insert_node_last();
void delete_last();
void display();
snode *newnode, *ptr, *prev, *temp;
snode *first = NULL, *last = NULL;

 int main()
 {
    int ch;
    char ans = 'Y';

    while (ans == 'Y'||ans == 'y')
    {
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.Display");
        printf("\n4.Exit\n");
        printf("\nEnter your choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert_node_last();
            display();
            break;
        case 2:
            delete_last();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\n...Exiting...\n");
            return 0;
            break;
        }
    }
    return 0;
 }

snode* create_node(int val)
{
    newnode = (snode *)malloc(sizeof(snode));
    if (newnode == NULL)
    {
        printf("\nMemory was not allocated");
        return 0;
    }
    else
    {
        newnode->value = val;
        newnode->next = NULL;
        return newnode;
    }
}
void insert_node_last()
{
    int val;

    printf("\nEnter the value for the Node:");
    scanf("%d", &val);
    newnode = create_node(val);
    if (first == last && last == NULL)
    {
        first = last = newnode;
        first->next = NULL;
        last->next = NULL;
    }
    else
    {
        last->next = newnode;
        last = newnode;
        last->next = NULL;
    }
 printf("INSERTED\n");
}
void delete_last()
{
    int i;

    if (first == NULL)
    {
        ISEMPTY;
        printf(":No element to delete\n");
    }
    else
    {
        ptr=first;
        if(first->next==NULL)
        {
            printf("%d deleted \n",ptr->value);
            first=ptr->next;
        }
        else
        {
            while(ptr->next!=NULL)
            {
                prev=ptr;
                ptr=ptr->next;
            }
            printf("%d deleted \n",ptr->value);
            prev->next=NULL;
            free(ptr);
        }

    }
}
void display()
{
    if (first == NULL)
    {
        ISEMPTY;
        printf(":No element in the stack to display\n");
    }
    else
    {
        printf("Stack contains\n");
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        {
            printf("%d\t", ptr->value);
        }
    }
}

