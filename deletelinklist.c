#include <stdio.h>
#include <stdlib.h>
void display(void);
struct node
{
    int data;
    struct node *next;
};
struct node *head,*temp;


void create(int n)
{
    int i;
    struct node *newnode;
    for(i=0;i<n;i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        printf("enter the data for the node %d : ",i+1);
        scanf("%d",&newnode->data);
        if(head==0)
        {
            temp=head=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    display();
}

void display()
{
    temp=head;
    printf("\nthe current linked list is :");
    while(temp!=NULL)
    {
        printf(" %d ",temp->data);
        temp=temp->next;

    }
    printf("\n\n");
}
void delstart()
{
    temp=head;
    head=temp->next;
    free(temp);
    printf("\nthe first node has been deleted\n\n");
    display();
}
void dellast()
{
    struct node *link;
    link = (struct node*)malloc(sizeof(struct node));
    link=temp=head;
    while(temp->next!=NULL)
    {
       temp=temp->next;
       if(temp->next==NULL)
       {
           link->next=NULL;
           free(temp);
           break;
       }
       link=temp;
    }
    printf("\nthe last node has been removed\n\n");
    display();
}

void delposition1()
{
    int p,i;
    struct node *link;
    link = (struct node*)malloc(sizeof(struct node));
    printf("\nenter the position that you want delete prev node:");
    scanf("%d",&p);
    temp=link=head;
    for(i=0;i<p-1;i++)
    {
        if(p==1)
        {
            delstart();
        }
        else
        {
            if(i==p-1-1)
            {
                link->next=temp->next;
                free(temp);
                break;
            }
            link=temp;
            temp=temp->next;
        }

    }
    printf("\n the node prev position %d has been deleted",p);
    display();
}
void delposition2()
{
    int p,i;
    struct node *link;
    link = (struct node*)malloc(sizeof(struct node));
    printf("\nenter the position that you want delete after node:");
    scanf("%d",&p);
    temp=link=head;
    for(i=0;i<p+1;i++)
    {
        if(p==1)
        {
            delstart();
        }
        else
        {
            if(i==p)
            {
                link->next=temp->next;
                free(temp);
                break;
            }
            link=temp;
            temp=temp->next;
        }

    }
    printf("\n the node after position %d has been deleted",p);
    display();
}
int main()
{
    int n;
    printf("enter the number of nodes you want to create :\n");
    scanf("%d",&n);
    create(n);
    delstart();
    dellast();
   //delposition();
    delposition1();
    delposition2();
}
