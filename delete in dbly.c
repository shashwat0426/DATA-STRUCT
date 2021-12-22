#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node * preptr;
    struct node * nextptr;
}*firstnode, *endnode;


void Listcreation(int n);
void DeleteFirstNode();
void DeleteLastNode();
void DeleteAnyNode1(int pos);
void DeleteAnyNode2(int pos);
void displayDlList(int a);

int main()
{
    int n,m,num1,a,insPlc;
    firstnode = NULL;
    endnode = NULL;
	printf("\n\n Doubly Linked List");
    printf(" Input the number of nodes: ");
    scanf("%d", &n);
    Listcreation(n);
    a=1;
    displayDlList(a);


DeleteFirstNode();
m=++a;
 displayDlList(a);
    DeleteLastNode();
     displayDlList(a);
      printf(" Input the position ( 1 to %d ) to delete prev and next node : ",n);
    scanf("%d", &insPlc);
if(insPlc<1 || insPlc>n)
    {
     printf("\n Invalid position. Try again.\n ");
    }
	      if(insPlc>=1 && insPlc<=n)
      {

    DeleteAnyNode1(insPlc);
        a=2;
    displayDlList(a);
    DeleteAnyNode2(insPlc);
    displayDlList(a);
      }
    return 0;
}

void Listcreation(int n)
{
    int i, num;
    struct node *fnNode;

    if(n >= 1)
    {
        firstnode = (struct node *)malloc(sizeof(struct node));

        if(firstnode != NULL)
        {
            printf(" Input data for node 1 : ");
            scanf("%d", &num);

            firstnode->num = num;
            firstnode->preptr = NULL;
            firstnode->nextptr = NULL;
            endnode = firstnode;
            for(i=2; i<=n; i++)
            {
                fnNode = (struct node *)malloc(sizeof(struct node));
                if(fnNode != NULL)
                {
                    printf(" Input data for node %d : ", i);
                    scanf("%d", &num);
                    fnNode->num = num;
                    fnNode->preptr = endnode;
                    fnNode->nextptr = NULL;
                    endnode->nextptr = fnNode;
                    endnode = fnNode;
                }
                else
                {
                    printf(" Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf(" Memory can not be allocated.");
        }
    }
}

void DeleteAnyNode1(int pos)
{
    struct node *curNode;
    int i;

    curNode = firstnode;
    for(i=1; i<pos-1 && curNode!=NULL; i++)
    {
        curNode = curNode->nextptr;
    }

    if(pos == 1)
    {
        DeleteFirstNode();
    }
    else if(curNode== endnode)
    {
        DeleteLastNode();
    }
    else if(curNode != NULL)
    {
        curNode->preptr->nextptr = curNode->nextptr;
        curNode->nextptr->preptr = curNode->preptr;

        free(curNode);
    }
    else
    {
        printf(" The given position is invalid!\n");
    }
}

void DeleteAnyNode2(int pos)
{
    struct node *curNode;
    int i;

    curNode = firstnode;
    for(i=1; i<pos+1 && curNode!=NULL; i++)
    {
        curNode = curNode->nextptr;
    }

    if(pos == 1)
    {
        DeleteFirstNode();
    }
    else if(curNode == endnode)
    {
        DeleteLastNode();
    }
    else if(curNode != NULL)
    {
        curNode->preptr->nextptr = curNode->nextptr;
        curNode->nextptr->preptr = curNode->preptr;

        free(curNode);
    }
    else
    {
        printf(" The given position is invalid!\n");
    }
}

void DeleteFirstNode()
{
    struct node * NodeToDel;
    if(firstnode == NULL)
    {
        printf(" Delete is not possible. No data in the list.\n");
    }
    else
    {
        NodeToDel = firstnode;
        firstnode = firstnode->nextptr;
        firstnode->preptr = NULL;
        free(NodeToDel);
    }
}

void DeleteLastNode()
{
    struct node * NodeToDel;

    if(endnode == NULL)
    {
        printf(" Delete is not possible. No data in the list.\n");
    }
    else
    {
        NodeToDel = endnode;
        endnode = endnode->preptr;
        endnode->nextptr = NULL;
        free(NodeToDel);
    }
}


void displayDlList(int m)
{
    struct node * tmp;
    int n = 1;
    if(firstnode == NULL)
    {
        printf(" No data found in the List yet.");
    }
    else
    {
        tmp = firstnode;
        if (m==1)
        {
        printf("\n Data in the list are :\n");
        }
        else
        {
         printf("\n After deletion the new list are :\n");
         }

        while(tmp != NULL)
        {
            printf(" node %d : %d\n", n, tmp->num);
            n++;
            tmp = tmp->nextptr;
        }

    }
}

