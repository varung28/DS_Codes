/*

Singly Circular Linked List program in C++

1SingyCLL.cpp
*/
#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node* Next;
}NODE,*PNODE;
//typedef struct node NODE;
//typedef struct node * PNODE;
class SinglyCL
{
private:
	int iSize;
	PNODE Head;
	PNODE Tail;
public:
	SinglyCL()
	{
		iSize=0;
		Head=NULL;
		Tail=NULL;
	}

void InsertFirst(int no)
{
PNODE newn=new NODE;
newn->data=no;
newn->Next=NULL;

if(Head==NULL && Tail==NULL)
{//blank LL
Head=newn;
Tail=newn;	
}else{
//LL has min 1 node
newn->Next=Head;
Head=newn;
}
iSize++;
Tail->Next=Head;
cout<<"\nNew List aft Insert :\n"; Display();
}	

void InsertLast(int no)
{
PNODE newn=new NODE;
newn->data=no;
newn->Next=NULL;

if(Head==NULL && Tail==NULL)
{//blank LL
Head=newn;
Tail=newn;
	
}else{
//LL has min 1 node

Tail->Next=newn;
Tail=newn;

}//else
Tail->Next=Head;
iSize++;
cout<<"\nNew List aft Insert :\n"; Display();
}//funct
//-------------
int Count()
{
return iSize;	
}
void Display()
{
int c=Count();
if(c==0)
{
	cout<<"\n######\tList Empty\t######";
	return;
}
PNODE Temp=Head;
for(int i=1;i<=c;i++)
{
cout<<"|"<<Temp->data<<"|->";
Temp=Temp->Next;
}
cout<<"\n_(back to head)";	
}
void DeleteFirst()
{
PNODE Target=NULL;
if(iSize==0)
{
	cout<<"\n######\tAlready Empty\t######";
	return;
}else if(iSize==1){
	delete (Head);
	Head=NULL;
	Tail=NULL;
	
}else{
	//Tail->Next=Head->Next;
	Head=Head->Next;
	delete (Tail->Next);

}
Tail->Next=Head;
iSize--;
cout<<"\nNew List aft Delete :\n"; Display();
}
void DeleteLast()
{
PNODE Target=NULL;
if(iSize==0)
{
	cout<<"\n######\tAlready Empty\t######";
	return;
}else if(iSize==1){
	delete (Tail);
	Head=NULL;
	Tail=NULL;
	
}else{
PNODE Temp=Head;
for(int i=1;i<iSize-1;i++)
{
	Temp=Temp->Next;
}
delete (Tail);
Tail=Temp;
}
Tail->Next=Head;	
iSize--;
cout<<"\nNew List aft Delete :\n"; Display();	
}
void DeleteAtLocation(int iPos)
{
int i=1;
if(iPos<1 || iPos>iSize)
{	cout<<"\n\t*** Invalid Position ***\n"; return;	}

if(iSize==0)
{
	cout<<"\n######\tList Already Empty\t######";
	return;
}else if(iPos==1)
{
	DeleteFirst();
}else if(iPos==iSize)
{
	DeleteLast();
}else{
	PNODE Temp=Head;
PNODE Target=NULL;
for(i=1;i<iPos-1;i++)
{
Temp=Temp->Next;
}
	Target=Temp->Next;
	Temp->Next=Target->Next;
	delete (Target);
	iSize--;
cout<<"\nNew List aft Delete :\n"; Display();	
}//else
}//func
void InsertAtLocation(int iPos,int no)
{
int i=1;

if(iPos<1 || (iSize+1)<iPos)
{	cout<<"\n\t*** Invalid Position ***\n"; return;	}

if(iPos==1)
{
	InsertFirst(no);
}else if(iPos==(iSize+1)){
	InsertLast(no);	
}else{
PNODE newn=new NODE;
newn->Next=NULL; newn->data=no;
PNODE Temp=Head;
for(int i=0;i<iPos-1;i++)
{
	Temp=Temp->Next;
}
newn->Next=Temp->Next;
Temp->Next=newn;
iSize++;
cout<<"\nNew List aft Insert :\n"; Display();	
}
}//func
	
};
int main()
{
SinglyCL CL1;
int iOpt=1,ians=0,iPos=0,ino=0;	

while(iOpt!=0)
{
	cout<<"\nEnter one of the Below Option: ";
	cout<<"\n__________________________________";
	cout<<"\n1. Insert First ";
	cout<<"\n2. Insert Last ";
	cout<<"\n3. Insert at Location :";
	cout<<"\n4. Delete First :";
	cout<<"\n5. Delete Last :";
	cout<<"\n6. Delete at Location :";
	cout<<"\n7. Display All Nodes :";
	cout<<"\n8. Get Count of Nodes :";
//	cout<<"\n9. Get 1st of Nodes :";
//	cout<<"\n10. Get Count of Nodes :";
	cout<<"\n0. Exit the Application :";
	cout<<"\n__________________________________";
	cout<<"\nEntered Option :";
	cin>>iOpt;

switch(iOpt)
{
case 1:
		cout<<"\nEnter element to InsertFirst :";
		cin>>ino;
		CL1.InsertFirst(ino);
		break;
case 2:
		cout<<"\nEnter element to InsertLast :";
		cin>>ino;
		CL1.InsertLast(ino);
		break;
		
case 3:
		cout<<"\nEnter element for InsertAtLocation :";
		cin>>ino;
		cout<<"\nEnter Position :";
		cin>>iPos;
		CL1.InsertAtLocation(iPos,ino);
		break;
case 4:
		cout<<"\n Deleting 1st Node :";
		CL1.DeleteFirst();
		break;
case 5:
		cout<<"\n Deleting Last Node :";
		CL1.DeleteLast();
		break;
case 6:
		
		cout<<"\nEnter Position for DeleteAtLocation :";
		cin>>iPos;
		CL1.DeleteAtLocation(iPos);
		break;

case 7:
		cout<<"\nDisplaying all Nodes below :\n ";
		CL1.Display();
		break;

case 8:
		ians=CL1.Count();
		cout<<"\nTotal No of Nodes :"<<ians;
		break;
case 0:
		cout<<"\nThank You for using Linked List Application\nExitting ";
		exit(0);
		break;

default:
		cout<<"\nInvalid Option\nEnter again :";
		break;
}//switch
	
}//while
	
return 0;
}
