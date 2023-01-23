/*

DoublyCircularLinkedList.c

*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//#include<malloc.h>
struct node
{
	int data;
	struct node *Next,*Prev;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;
//typedef int BOOL;
int LSize=0;
void DisplayX(PNODE,PNODE);
#define TRUE 1
#define FALSE 0

void InsertFirst(PPNODE Head,PPNODE Tail,int no)
{
PNODE newn=NULL;
newn=(PNODE)malloc(sizeof(NODE));
if(newn==NULL)
{
	cout<<"\nmalloc Failed";	return;
}
newn->Next=NULL;
newn->Prev=NULL;
newn->data=no;

if(*Head==NULL && *Tail==NULL)
{
	*Head=newn;
	*Tail=newn;
	(*Tail)->Next=(*Head);
	(*Head)->Prev=(*Tail);
}else{
	newn->Next=*Head;
	(*Head)->Prev=newn;
	*Head=newn;
	(*Tail)->Next=*Head;
	(*Head)->Prev=*Tail;
}
LSize++;
cout<<"\nPrinting All:\n";
DisplayX(*Head,*Tail);
}

int Count(PNODE Head,PNODE Tail)
{
//int c=0;
/*if(Head==NULL || Tail==NULL)
{
	cout<<"\nError :";
	return -1;
}
PNODE Temp=NULL;
Temp=Head;

while(Temp->Next!=Tail)
{
Temp=Temp->Next;
c++;	
}
return c;*/
return LSize;
}

void DisplayX(PNODE Head,PNODE Tail)
{
int c=LSize;
PNODE Temp=NULL;
Temp=Head;
while(c!=0)
{
cout<<"| "<<Temp->data<<" |->";	
Temp=Temp->Next;
c--;	
}
cout<<"\n^__";
}
void InsertLast(PPNODE Head,PPNODE Tail,int no)
{
PNODE newn=NULL;
newn=(PNODE)malloc(sizeof(NODE));
if(newn==NULL)
{
cout<<"\nMallocFailed "; return;
}
newn->Next=NULL;
newn->Prev=NULL;
newn->data=no;

if(*Head==NULL && *Tail==NULL)
{
	*Head=newn;
	*Tail=newn;
	(*Head)->Prev=*Tail;
	(*Tail)->Next=*Head;
}else{
	(*Tail)->Next=newn;
	newn->Prev=(*Tail);
	(*Tail)=newn;
	(*Tail)->Next=*Head;
	(*Head)->Prev=*Tail;
}
LSize++;
DisplayX(*Head,*Tail);
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
PNODE Temp=NULL;
Temp=*Head;

if(LSize==0)
{
	cout<<"\nAlready Empty ";
	return;
}else if(LSize==1)
{
	free (*Head); free(*Tail);
	*Head=NULL; *Tail=NULL;
}else{
	*Head=(*Head)->Next;
	(*Tail)->Next=*Head;
	(*Head)->Prev=*Tail;
	free (Temp);
}
LSize--;
cout<<"\nPrinting aft Deletion :\n";
DisplayX(*Head,*Tail);
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
PNODE Temp=NULL;
Temp=*Tail;

if(LSize==0)
{ cout<<"\nAlready Empty:"; return;
}else if(LSize==1)
{
	free(*Head); free(*Tail);
	*Head=NULL; *Tail=NULL;
}else{
*Tail=(*Tail)->Prev;
(*Tail)->Next=*Head;
(*Head)->Prev=*Tail;
free(Temp);
}
LSize--;
cout<<"\nPrinting aft Deletion:\n"; DisplayX(*Head,*Tail);
}

void InsertAtPosition(PPNODE Head,PPNODE Tail,int iPos,int no)
{
int i=1,size=0;
size=LSize;
if(iPos>0 && iPos<size+1)
{
	if(iPos==1)
	{
	InsertFirst(Head,Tail,no);
	}else if(iPos==size)
	{
	InsertLast(Head,Tail,no);
	}else{
PNODE newn=NULL;
newn=(PNODE)malloc(sizeof(NODE));
if(newn==NULL)
{ cout<<"\nMalloc failed"; return; }
newn->Next=NULL; newn->Prev=NULL;
newn->data=no;

PNODE Temp=NULL;
Temp=*Head;	
	for(i=1;i<iPos-1;i++)
	{ Temp=Temp->Next; }
	newn->Next=Temp->Next;
	newn->Prev=Temp;
	Temp->Next=newn;
	(Temp->Next)->Prev=newn;
LSize++;
cout<<"\nPrinting aft Done:\n";
DisplayX(*Head,*Tail);
}
}else{
cout<<"\nInvalid Position"; return;
}
}

void DeleteAtPosition(PPNODE Head,PPNODE Tail,int iPos)
{
int i=1,size=0;
size=LSize;

if(iPos>0 && iPos<=size)
{
	if(iPos==1)
	{
	DeleteFirst(Head,Tail);
	}else if(iPos==size)
	{
	DeleteLast(Head,Tail);
}else{
PNODE Temp=*Head;
for(i=1;i<iPos-1;i++)
{
	Temp=Temp->Next;
}
Temp->Next=(Temp->Next)->Next;
free ((Temp->Next)->Prev);
(Temp->Next)->Prev=Temp;
LSize--;
cout<<"\nPrinting aft Done:\n";
DisplayX(*Head,*Tail);
}
}else{
	cout<<"\nInvalid Position";
return;
}//else 1
}//
/*
int SearchFirstOcc(PPNODE Head,PPNODE Tail,int k)
{
int c=0;	
do
{
	c++;
	if(Head->data==k)
	{ break; }
	Head=Head->Next;
}while(Head!=Tail->Next);

if(Head==Tail->Next)
{
	return c;
}else{
	return -1;
}
}
int SearchAllOcc(PPNODE Head,PPNODE Tail,int k)
{
int c=0;
do
{
	if((*Head)->data==k)
	{
		c++;
	}
	Head=Head->Next;
}while(Head!=Tail->Next);	

return c;
}
*/

//main below
int main()
{
PNODE First=NULL;
PNODE Last=NULL;
int iOpt=1,iAns=0,iPos=0,ino=0;

while(iOpt!=0)
{
	       printf("\n********************************\n");
        printf("Please select the option\n");
        printf("1 : Insert the node at first position\n");
        printf("2 : Insert the node at last position\n");
        printf("3 : Insert the node at given position\n");
        printf("4 : Delete the fisrt node\n");
        printf("5 : Delete the last node\n");
        printf("6 : Delete the node at given position \n");
        printf("7 : Display the contents of linked list \n");
        printf("8 : Count the nodes of linked list \n");
		printf("9 : Search First Occurance of :\n");
		printf("10 :Search Last Occurance of :\n");
        printf("0 : Exit the application\n	");
        scanf("%d",&iOpt);
        printf("********************************\n");	

switch(iOpt)
{
case 1:
	cout<<"\nEnter data to Insert :";
	cin>>ino;
	InsertFirst(&First,&Last,ino);
		break;

case 2:
		cout<<"\nEnter data to Insert :";
		cin>>ino;
		InsertLast(&First,&Last,ino);
		break;

case 3:
		cout<<"\nEnter Location :";
		cin>>iPos;
		cout<<"\nEnter data for Node :";
		cin>>ino;
		InsertAtPosition(&First,&Last,iPos,ino);
		break;
case 4:
		DeleteFirst(&First,&Last);
		break;
case 5:
		DeleteLast(&First,&Last);
		break;
		
case 6:
		cout<<"\nEnter Location :";
		cin>>iPos;
		DeleteAtPosition(&First,&Last,iPos);
		
		break;
case 7:
		DisplayX(First,Last);
		break;

case 8:
		iAns=Count(First,Last);
		cout<<"\nCount of Nodes in LL :"<<iAns;	
		break;	
case 9:
		cout<<"\nEnter No to get 1st Occurance :";
		cin>>ino;
//		iAns=SearchFirstOcc(&First,&Last,ino);
		printf("\n1st occurance of %d : %dth Node ",ino,iAns);
		break;
		
case 10:
		cout<<"\nEnter No to get All Occurance :";
		cin>>ino;
//		iAns=SearchAllOcc(&First,&Last,ino);
		printf("\n1st occurance of %d : %dth Node ",ino,iAns);
		
		break;
		
case 0:
	 cout<<"\nThank You For Using our Linked List Application ";
		exit(0);
		break;

default:
		cout<<"\nInvalid Input\nTry again";
		break;
	
}//switch
}//while


return 0;
}
