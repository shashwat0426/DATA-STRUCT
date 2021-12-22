 #include <stdio.h>
#include <stdlib.h>
int create(int);
void Listdisplay(void);
struct node
{
    int data;
    struct node *next;
};
struct node *head,*temp;
int create(int n)
{
    struct node *newnode;
    temp=head=0;
    int i;
    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data for the node %d :",i+1);
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    newnode->next=head;
    head=temp;
    printf("THE CIRCULAR LINKED IS CREATED");
    display();
}
void display()
{
    temp=head;
    printf("\nTHE CURRENT CIRCULAR LINKED LIST IS : ");
    do
    {
        temp=temp->next;
        printf("%d ",temp->data);
    }while(temp!=head);
    printf("\n\n\n");
}
void start()                //begining me strt
{
    struct node *newnode;
    newnode =(struct node*)malloc(sizeof(struct node));
    printf("enter the data that you want to insert at the start:\n");
    scanf("%d",&newnode->data);
    newnode->next=head->next;
    head->next=newnode;
    display();

}
void end()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nenter the data that you want to enter at the end : ");
    scanf("%d",&newnode->data);
    newnode->next=head->next;
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
        if(temp->next==head)
        {
            temp=temp->next;
             head=newnode;
            temp->next=newnode;
            temp=newnode;
            break;

        }
    }
    display();
}
void position(int p)
{
    int i;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next= NULL;
    printf("\nenter the data that you want to enter :");
    scanf("%d",&newnode->data);
    temp=head;
    for(i=0;i<p+1;i++)
    {
        if(i==p)
        {
            newnode->next=temp->next;
            temp->next=newnode;
        }
        temp=temp->next;
    }
    display();
}
void befaft()
{
    int p;
    printf("enter the position before and next where want to enter the data:");
    scanf("%d",&p);
    position(p);
    position(p-1);
}
int main()
{
    int n;
    printf("enter the number of nodes to be created ");
    scanf("%d",&n);
    create(n);
    start();
    end();
    befaft();
}
