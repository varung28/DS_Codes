/*

ElementsLL.cpp
*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//#include<malloc.h>
struct element
{
	int aNo;
//	char aName[10];
char* aSymbol[5];
	struct element* Next;
//	struct element* Prev;
};
typedef struct element NODE;
typedef struct element* PNODE;
typedef struct element** PPNODE;
int lSize=0;
void Display(PNODE);
void InsertLast(PPNODE,PPNODE,char[],int);

void InsertLast(PPNODE Head,char* aSymb[5],int no)
{
PNODE newn=NULL;
newn=(PNODE)malloc(sizeof(NODE));
newn->Next=NULL;
newn->aNo=no;
int i=0;
while(aSymb[i]!='\0')
{
	newn->aSymbol[i]=aSymb[i];
aSymb++; newn->aSymbol++;	i++;
}
if(*Head==NULL )
{
	*Head=newn;
}else{
	newn->Next=*Head;
	*Head=newn;
}
lSize++;
cout<<"\nPrinting aft Insert :\n";
Display(*Head);
}
void Display(PNODE Head)
{
int c=lSize;
PNODE Temp=NULL;
Temp=Head;
while(c!=0)
{
	cout<<"\nAtomicNo :"<<Temp->aNo<<"\tName :"<<Temp->aSymbol<<" .";
Temp=Temp->Next;
c--;
}
}
int main()
{
int N=0,aNo=0;
PNODE First;
First=NULL;
PNODE Last;
Last=NULL;
char aSymbol[5];
cout<<"\nEnter no of elements you want to enter :";
cin>>N;
while(N!=0)
{


cout<<"\nEnter Symbol of Element :";
cin>>aSymbol;
cout<<"\nEnter Atomic No of Element :";
cin>>aNo;
InsertLast(&First,&Last,aSymbol,aNo);	
N--;	
}

cout<<"\nDone Inserting All :";
cout<<"\nPrinting elements :";
Display(First);

return 0;
}
