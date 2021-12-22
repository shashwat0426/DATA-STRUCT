#include <stdio.h>
#include <stdlib.h>
void display(void);
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head,*temp,*tail;

void create(int n)
{
    int i;
    struct node *newnode;
    for(i=0;i<n;i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("enter the data for node %d : ",i+1);
        scanf("%d",&newnode->data);
        newnode->prev=0;
        newnode->next=0;
        if(head==0)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
        if(i==n-1)
            tail=temp;
    }
    printf("THE DOUBLY LINKED LIST HAs BEEN CREATED\n\n");
    display();
}

/*function to display the data of the doubly linked list*/
void display()
{
    temp=head;
    printf("\nTHE CURRENT DOUBLY LINKED LIST Is : ");
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
/*reversed doubly linked list*/
void reverse()
{
    temp=tail;
    printf("\nTHE REVERSED DOUBLY LINKED LIST IS : ");
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
}

/*insert node at the start*/
void start(void)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter the data you want to enter at the beginning of the node:\n");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    printf("The data has been inserted in the node.....displaying the current linked list");
    display();
}

/*inserting node at the end of the linked list*/
void end(void)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter the data you want to enter at the end of the node :\n");
    scanf("%d",&newnode->data);
    newnode->next=0;
    newnode->prev=tail;
    tail->next=newnode;
    tail=newnode;
    printf("the doubly linked lsit has been updated ......displaying the list:\n");
    display();
}

/*inserting node at certain position in the linked list*/
void position(void)
{
    int p,i;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter the position at which you want to insert the data :\n");
    scanf("%d",&p);
    printf("enter the data that yo want to insert in the list:\n");
    scanf("%d",&newnode->data);
    newnode->next=0;
    newnode->prev=0;
    temp=head;
    for(i=0;i,p;i++)
    {
        if(i==p-1)
        {
            newnode->next=temp;
            newnode->prev=temp->prev;
            temp=temp->prev;
            temp->next=newnode;
            temp=newnode->next;
            temp->prev=newnode;
            break;
        }
        temp=temp->next;

    }
    display();
}

int main()
{
    int n,choice,c;
    printf("enter the number of nodes you want to create:\n");
    scanf("%d",&n);
    create(n);
    while(choice)
   {

    printf("Enter the choice\n(1) to insert at beginning\n(2) to delete from the end\n(3)to insert a node at any given position\n(4)to delet before and after any given position");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        start();
        break;
    case 2:
        end();
        break;
    case 3:
        position();
        break;
    case 4:
        reverse();
        break;
    }
    printf("enter 0 to exit :\n");
    scanf("%d",&choice);
   }
}

