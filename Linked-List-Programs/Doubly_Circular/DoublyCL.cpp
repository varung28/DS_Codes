/*
151th LB
DoublyCircular LinkedList

DoublyCL.cpp
*/

#include<iostream>
using namespace std;

//typedef struct node
struct node
{
int data;
struct node* Next;
struct node* Prev;	
};
typedef struct node NODE;
typedef struct node* PNODE;

class DoublyCL
{
private:
	int iSize;
	PNODE Head;
	PNODE Tail;
		
public:
	DoublyCL()
	{
		iSize=0;
		Head=NULL;
		Tail=NULL;
	}
//declarations
	int Count();
	void Display();
	void InsertFirst(int);
	void InsertLast(int);
	void InsertAtLocation(int,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtLocation(int);
};
	
int DoublyCL::Count()
	{
		return iSize;
	}
void DoublyCL::InsertFirst(int no)
	{
PNODE newn=new NODE;
newn->data=no;
newn->Next=NULL;
newn->Prev=NULL;
int c=iSize;

cout<<"\ninside function\nnewn->data: "<<newn->data;
if(Head==NULL && Tail==NULL)
{
cout<<"\nLL was empty";
	Head=newn;	
	Tail=newn;
}else{
cout<<"\nLL Was not empty";
	newn->Next=Head;
	Head=newn;
}
	Tail->Next=Head;
	Head->Prev=Tail;
	iSize++;
cout<<"\nPrinting aft Done:\n";
Display();
}
void DoublyCL::InsertLast(int no)
	{
PNODE newn=new NODE;
newn->Next=NULL;
newn->Prev=NULL;
newn->data=no;

if(iSize==0)
{
	Head=newn;
	Tail=newn;
}else{
Tail->Next=newn;
newn->Prev=Tail;
Tail=newn;
}
	Head->Prev=Tail;
	Tail->Next=Head;
	iSize++;
cout<<"\nPrinting aft Done :\n";
Display();	
}
void DoublyCL::DeleteFirst()
	{
if(iSize==0)
{
	cout<<"\nEmptyList "; return;
}else if(iSize==1){
	delete (Head); delete (Tail);
	Head=NULL;	Tail=NULL;
}else{
	Head=Head->Next;
	delete(Head->Prev);
Head->Prev=Tail;
Tail->Next=Head;
iSize--;	
cout<<"\nPrinting after Deletion :\n";
Display();
}//else
iSize--;
cout<<"\nPrinting after Deletion :\n";
Display();
}
void DoublyCL::DeleteLast()
	{
if(iSize==0)
{
	cout<<"\nEmptyList "; return;
}else if(iSize==1){
 delete (Tail);
	Head=NULL;	Tail=NULL;
iSize--; cout<<"\nList is Now empty";
}else{
Tail=Tail->Prev;
delete (Tail->Next);
Tail->Next=Head;
Head->Prev=Tail;	
iSize--;
cout<<"\nPrinting after Deletion :\n";
Display();
}//else

	}
void DoublyCL::Display()
	{
	if(Head==NULL || Tail==NULL)
	{
		cout<<"\nList Empty or corrupt";
		return;
	}
	int c=iSize;
	PNODE Temp=Head;
	do
	{
	cout<<"|"<<Temp->data<<"|->";
	Temp=Temp->Next;
	c--;
	}while(c!=0);
	}
void DoublyCL::InsertAtLocation(int no,int iPos)
	{
int i=1,size=iSize;

if(iPos>0 && iPos<(iSize+1))
{
	if(iPos==1)
	{
	InsertFirst(no);
	}else if(iPos==iSize+1)
	{
	InsertLast(no);
	}else{
	PNODE newn=new NODE;
	newn->Next=NULL; newn->Prev=NULL;
	newn->data=no;
	
	PNODE Temp=Head;
	for(i=1;i<iPos-1;i++)
	{
		Temp=Temp->Next;
	}
newn->Next=Temp->Next;//newnRHS
(Temp->Next)->Prev=newn;//
Temp->Next=newn;//tempRHS
		
newn->Prev=Temp;//newnLHS
	iSize++;
Display();
}//else 2
	
}else{
	cout<<"\nInvalid Position";
	return;
}//else 1
}
void DoublyCL::DeleteAtLocation(int iPos)
	{
int i=1,size=iSize;
if(iPos>0 && iPos<(size+1))
{
	if(iPos==1)
	{
		DeleteFirst();
	}else if(iPos==iSize)
	{
		DeleteLast();
	}else{
	PNODE Temp=Head;
	for(i=1;i<iPos-1;i++)
	{
		Temp=Temp->Next;
	}
	Temp->Next=(Temp->Next)->Next;
	delete ((Temp->Next)->Prev);
	(Temp->Next)->Prev=Temp;
iSize--;
cout<<"\nPrinting aft Done :\n";
Display();
}
}else{
cout<<"\nInvalid Position"; return;
}//else 1
}

int main()
{
int iOpt=1,iPos=0,ians=0,ino=0;
DoublyCL L1;

while(iOpt!=0)
{
cout<<"\nEnter one of below:\n";
cout<<"\n1. Insert First ";	
cout<<"\n2. Insert Last ";	
cout<<"\n3. Insert at Location";	
cout<<"\n4. Delete First ";	
cout<<"\n5. Delete Last ";	
cout<<"\n6. Delete at Location ";	
cout<<"\n7. Display all Nodes ";	
cout<<"\n8. Print Count of Nodes ";	
cout<<"\n0. Exit Application ";	
cout<<"\nSelect option :";
cin>>iOpt;

switch(iOpt)
{
case 1:
		cout<<"\nEnter element :";
		cin>>ino;
		L1.InsertFirst(ino);
		break;
case 2:
		cout<<"\nEnter element :";
		cin>>ino;
		L1.InsertLast(ino);
		break;
case 3:
		cout<<"\nEnter element :";
		cin>>ino;
		cout<<"\nInter positon :";
		cin>>iPos;
		L1.InsertAtLocation(ino,iPos);
		break;
case 4:
		L1.DeleteFirst();
		break;
case 5:
		L1.DeleteLast();
		break;		

case 6:

		cout<<"\nEnter positon :";
		cin>>iPos;
		L1.DeleteAtLocation(iPos);
		break;
		
case 7:
		cout<<"\nPrinting all Nodes :\n";
		L1.Display();

case 8:
		ians=L1.Count();
		cout<<"\nTotalNo of Nodes :"<<ians;
		break;
default:
		cout<<"\nInvalid Option\nTry again";
		break;
}//switch

	
}//while

return 0;
}
