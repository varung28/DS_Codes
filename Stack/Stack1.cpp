/*
Stack Programs in C++
Stack1.cpp

*/

#include<iostream>
using namespace std;

typedef struct Node
{
int data;
struct Node* Next;
}NODE,* PNODE;

/*typedef struct Stack NODE;
typedef struct Stack* PNODE;
typedef struct Stack** PPNODE;*/
class Stack
{
private:
	PNODE Head;
	int iSize;
public:
	Stack();
	~Stack();
	void Push(int);//InsertFirst(...,int)
	int Pop();//DeleteFirst(..)
	int Count();
	void Display();
	void SaveDisplay();
};
Stack::Stack()
{
	this->iSize=0;
	this->Head=NULL;
}
Stack::~Stack()
{
}
void Stack::Push(int no)
{
PNODE newn=new NODE;
newn->data=no;
newn->Next=NULL;
	
	newn->Next=Head;
	Head=newn;
iSize++;
}
int Stack::Pop()
{
int r=-1;
if(iSize==0)//Stack empty
{ return r; }
else{
	PNODE Temp=Head;
	Head=Head->Next;
r=Temp->data;
	delete Temp;
iSize--;
return r;
}
}
void Stack::Display()
{
if(iSize==0)
{ cout<<"\nStack is Empty."; return; }
cout<<"\nDisplaying all elements in Stack below :\n";
PNODE Temp=Head;
while(Temp!=NULL)
{
	cout<<Temp->data<<"\n";
	Temp=Temp->Next;
}cout<<"__end of stack";
}
int Stack::Count()
{
return this->iSize;
}
void Stack::SaveDisplay()
{
	
}

int main()
{
Stack s;
int iOpt=1,ino=0,ians=0;

while(iOpt!=0)
{
cout<<"\n______Stack Application_______";
cout<<"\nSelect one of the option :";
cout<<"\n1. Push the element .";	
cout<<"\n2. Pop the element .";	
cout<<"\n3. Display all elements .";	
cout<<"\n4. get Count of Total element .";	
cout<<"\n5. Save and Exit .";	
cout<<"\n0.  Exit .";	
cout<<"\n_______________";
cout<<"\nEnter option :";
cin>>iOpt;

switch(iOpt)
{
case 1:
		cout<<"\nEnter element to Push :";
		cin>>ino;
		s.Push(ino);
		break;
case 2:
		ians=s.Pop();
		if(ians==-1)
			cout<<"\n Stack is Empty .";
		else
			cout<<"\nElement "<<ians<<" was popped/Removed .";
		break;
case 3:
		
		s.Display();
		break;		
case 4:
		ians=s.Count();
		if(ians==0)
			cout<<"\n Stack is Empty .";
		else
			cout<<"\nTotal elements in Stack :"<<ians;
		break;	
case 5:
		s.SaveDisplay();
		cout<<"\ndata Saved.";
		break;
		
case 0:
		cout<<"\nThank you For using Stack Application.";
		exit(0);
		break;
		
default:
		cout<<"\nInvalid Option\nEnter again ";
		break;
}//switch
}//while

return 0;
}
