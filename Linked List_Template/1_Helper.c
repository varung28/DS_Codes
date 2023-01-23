/*

1_Helper.c
*/

#include "SinglyLinkedList.h"

void InsertFirst(PPNODE Head,int no)
{
printf("\nInside InsertFirst function");
//code
PNODE newn=NULL;
newn=(PNODE)malloc(sizeof(NODE));
newn->data=no;
newn->Next=NULL;

if(*Head==NULL)//LL was empty
{
printf("\n\t\tLL was empty");
*Head=newn;
}else{
	newn->Next=*Head;
	*Head=newn;
}
}//close function
void InsertLast(PPNODE Head,int no)
{
printf("\nInside InsertLast function");
//code
PNODE newn=NULL;
PNODE temp=*Head;

newn=(PNODE)malloc(sizeof(NODE));
newn->data=no;
newn->Next=NULL;

if(*Head==NULL)
{
printf("\n\t\tLL was empty");
*Head=newn;
}else{
while(temp->Next!=NULL)
	{
	 temp=temp->Next;
	}//while close
	temp->Next=newn;
}//else close
}
void InsertAtPosition(PPNODE Head,int no,int iPos)
{
printf("\nInside InsertAtPosition function");
//code
    int iSize = 0, i = 0;
    PNODE newn = NULL;
    PNODE Temp = *Head;
iSize=Count(*Head);

if(iPos<1 || (iPos>iSize+1))
{
	return;
}

if(iPos==1)
{
	InsertFirst(Head,no);
}else if(iPos==iSize+1)
{
	InsertLast(Head,no);
}else{
newn=(PNODE)malloc(sizeof(NODE));
newn->data=no;
newn->Next=NULL;

for(i=1;i<iPos-1;i++)
{
	Temp=Temp->Next;
}
newn->Next=Temp->Next;
Temp->Next=newn;
}//else
}//function

int Count(PNODE Head)
{
int c=0;
while(Head!=NULL)
{
	c++;
	Head=Head->Next;
}
return c;
}

void Display(PNODE Head)
{
printf("\nNodes of Linked List :\n\n");
while(Head!=NULL)
{
printf("|%d|->",Head->data);
Head=Head->Next;
}
printf("\n");
}

void DisplaySave(PNODE First)
{
//code
printf("\nSaving the data");
}