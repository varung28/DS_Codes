/*
DoublyCircularClass.cpp
*/

#include<iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	char key;
	struct Node *Next;
	struct Node *Prev;
};

template <class T>
class genericDoublyC
{
private:
	int iSize;
	struct Node<T> *Head;
	struct Node<T> *Tail;	
	
public:
	genericDoublyC();
	~genericDoublyC();
		bool showList();
		bool showReverseList();
	int Count();
	int FirstOccurance(int);
	int LastOccurance(int);	
	
	bool InsertFirst(T no,char k);
	bool InsertLast(T,char);	
	int InsertAtPosition(T,char,int);
	
	bool DeleteFirst();
	bool DeleteLast();	
	bool DeleteAtPosition(int);
	
};
/////////////////////////////////////////////////
//Constructor and Destructor :
//Date :26-05-2021
template <class T>
genericDoublyC<T>::genericDoublyC()
{
iSize=0;
Head=NULL; Tail=NULL; 
Tail->Next=Head; Head->Prev=Tail;
}
template <class T>
genericDoublyC<T>::~genericDoublyC()
{
	
int c=iSize;
struct Node<T> *Temp=NULL;	
while(c>0)
{
Temp=Head;
Head=Head->Next;	
delete Temp;
c--;	
}	
}
///////////////////////////////////////////////////
//Regular Functions :
template <class T>
int genericDoublyC<T>::Count()
{
	return iSize;
}
template <class T>
bool genericDoublyC<T>::showList()
{
if(iSize==0)
	return false;
struct Node<T>* Temp=Head;
while(Temp!=NULL)
{
	cout<<(Temp->data)<<"|"<<(Temp->key)<<"|->";
	Temp=Temp->Next;
}
cout<<"->(backtoHead)\n";
return true;	
}
template <class T>
bool genericDoublyC<T>::showReverseList()
{
if(iSize==0)
	return false;
struct Node<T>* Temp=Tail;
while(Temp!=NULL)
{
	cout<<(Temp->data)<<"|"<<(Temp->key)<<"|<->";
	Temp=Temp->Prev;
}
cout<<" |(backToTTail)\n";
return true;	
}
/////////////////////////////////////////////////////
// Occurance Functions :
// Date : 26-05-2021
template <class T>
int genericDoublyC<T>::FirstOccurance(int no)
{
if(iSize==0)
{ return -1; }	
struct Node<T> *Temp=Head;
int c=-2,i=1;
while(c<=iSize)
{
if((Temp->data)==no)
{ 
c=i;
break;
 }
Temp=Temp->Next;	
i++;	
}
return c;
}

template <class T>
int genericDoublyC<T>::LastOccurance(int no)
{
if(iSize==0)
{ return -1; }	
struct Node<T> *Temp=Tail;
int i=1,c=-2;
while(c<=iSize)
{
if((Temp->data)==no)
{
	c=i;
break;
}
Temp=Temp->Prev;
i++;	
}
return c;
}
////////////////////////////////////////////////
//Insert Node Functions:
//Date :26-05-2021 
//
template <class T>
bool genericDoublyC<T>::InsertFirst(T no,char k)
{
struct Node<T> *newn=new struct Node<T>;
if(newn==NULL)
{ return false; }
newn->data=no;
newn->key=k;
newn->Next=NULL; newn->Prev=NULL;
if(iSize==0)
{
	Head=newn;	Tail=newn;
}else{
newn->Next=Head;
Head=newn;
}
iSize++; Head->Prev=Tail;
Tail->Next=Head;
return true;
}
template <class T>
bool genericDoublyC<T>::InsertLast(T no,char k)
{
struct Node<T>* newn=new struct Node<T>;
if(newn==NULL)
{ return false; }
newn->data=no;
newn->key=k; newn->Next=NULL; newn->Prev=NULL;
if(iSize==0)
{
	Tail=newn; Head=newn;	
}else{
Tail->Next=newn;
newn->Prev=Tail;
Tail=newn;
}
iSize++;
Tail->Next=Head; Head->Prev=Tail;
return true;
}

template <class T>
int genericDoublyC<T>::InsertAtPosition(T no,char k,int iPos)
{
if(iPos<1 || iPos>(iSize+1))
{ return -1; }
	
if(iPos==1)
{
	InsertFirst(no,k);
}else if(iPos==iSize)
{
	InsertLast(no,k);
}else{
struct Node<T>* newn=new struct Node<T>;
if(newn==NULL)
{ return 1; }
newn->data=no;
newn->key=k;
newn->Next=NULL; newn->Prev=NULL;
struct Node<T>* Temp=Head;
for(int i=1;i<iPos-1;i++)
{ Temp=Temp->Next; }
newn->Next=(Temp->Next);
(Temp->Next)->Prev=newn;
newn->Prev=Temp;
Temp->Next=newn;
iSize++;
}
return 0;
}
//////////////////////////////////////////////////
//Delete Node Functions below :
//Date :26-05-2021 
template <class T>
bool genericDoublyC<T>::DeleteFirst()
{
if(iSize==0)
{ return false; }

Head=(Head->Next);
delete (Tail->Next);
Head->Prev=Tail; Tail->Next=Head;
iSize--;
return true;
}
template <class T>
bool genericDoublyC<T>::DeleteLast()
{
if(iSize==0)
{ return false; }
//struct Node<T>* Temp=Tail;
Tail=(Tail->Prev);
delete (Head->Prev);
Tail->Next=Head; Head->Prev=Tail;
iSize--;
return true;	
}
template <class T>
bool genericDoublyC<T>::DeleteAtPosition(int iPos)
{
bool r=true;
if(iPos<1 || iPos>iSize)
{ return false; }
if(iPos==1)
{
	r=DeleteFirst();
}else if(iPos==iSize)
{
	r=DeleteLast();
}else{
struct Node<T> *Temp=Head;
for(int i=1;i<iPos-1;i++)
{ Temp=Temp->Next; }
struct Node<T> *Target=(Temp->Next);
(Temp->Next)=Target->Next;
(Target->Next)->Prev=Temp;
delete Target;
iSize--;	
}
return r;
}
///////////////////////////////////////////////
//main() below :
int main()
{
	cout<<"\nInside main() ";


return 0;
}