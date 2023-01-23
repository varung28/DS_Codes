/*

SinglyCircularLLX.c

*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//#include<malloc.h>
struct node
{
	int data;
	struct node* Next;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;
typedef int BOOL;
#define TRUE 1
#define FALSE 0

void InsertFirst(PPNODE Head,PPNODE Tail,int no)
{
PNODE newn=NULL;
newn=(PNODE)malloc(sizeof(NODE));
if(newn==NULL)
{
	cout<<"\nMallocFailed";
	return;
}
newn->data=no;
newn->Next=NULL;

if((*Head==NULL)&&(*Tail==NULL))
{
	*Head=newn;
	*Tail=newn;
	(*Tail)->Next=*Head;
}else{
	newn->Next=*Head;
	*Head=newn;
	(*Tail)->Next=newn;
}
}

int Count(PNODE Head,PNODE Tail)
{
int c=0;
PNODE Temp=Head;
do{
c++;
Temp=Temp->Next;
}while(Temp!=Tail->Next);

return c;
}

void DisplayX(PNODE Head,PNODE Tail)
{
int size=0;
size=Count(Head,Tail);
while(size!=0)
{
		printf("|%d |->",Head->data);
Head=Head->Next;
size--;
}
printf("\n");
}
void InsertLast(PPNODE Head,PPNODE Tail,int no)
{
PNODE newn=NULL,Temp=NULL;
Temp=*Head;
newn=(PNODE)malloc(sizeof(NODE));
if(newn==NULL)
{
	cout<<"\nMalloc Failed";
	return;
}
newn->data=no;
newn->Next=NULL;

if((*Head==NULL)&& *Tail==NULL)
{
	*Head=newn;
	*Tail=newn;
	(*Tail)->Next=*Head;
}else{
	(*Tail)->Next=newn;
	*Tail=newn;
	(*Tail)->Next=*Head;
}
}



void DeleteFirst(PPNODE Head,PPNODE Tail)
{
PNODE Temp=NULL;
Temp=*Head;
PNODE Target=NULL;

if(*Head==NULL)
{
	cout<<"\nEmplty LL";
	return;
}else{
	(*Head)=Temp->Next;
	free(Temp);
}
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
PNODE TempH=*Head;
PNODE TempT=*Tail;

if(*Head==NULL && *Tail==NULL)
{
	cout<<"\nEmpty LL";
	return;
}else{
	while((TempH->Next)!=TempT)
	{
		TempH=TempH->Next;
	}
	free(TempT);
	*Tail=TempH;
	(*Tail)->Next=*Head;
}
}

void InsertAtPosition(PPNODE Head,PPNODE Tail,int iPos,int no)
{
}

void DeleteAtPosition(PPNODE Head,PPNODE Tail,int iPos)
{
int i=0,isize=0;
isize=Count(*Head,*Tail);


if(iPos>isize)
{
	cout<<"\nInvalid Position";
	return;
}else if(iPos==1)
{
	DeleteFirst(Head,Tail);
}else if(iPos==isize)
{
		DeleteLast(Head,Tail);
}else{
	
}
}
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
