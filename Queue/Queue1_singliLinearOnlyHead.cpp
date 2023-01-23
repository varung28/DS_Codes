/*
OOP programs of Queue Structure

Queue1_singliLinearOnlyHead.cpp

*/
#include<iostream>
using namespace std;

typedef struct Node
{
int data;
struct Node* Next;

}NODE,*PNODE;

class Queue
{
private:
	PNODE Head;
	//PNODE Tail;
	int iSize;
	
public:
	Queue();
	~Queue();
	int Count();
	void Display();
	void Enqueue(int);//InsertLast(..,int);
	int Dequeue();	//DeleteFirst(...)
	int Peek();

};
Queue::Queue()
{
	iSize=0;
	Head=NULL;	//Tail=NULL;
}
Queue::~Queue()
{
cout<<"\nInside destructor ";	
PNODE Temp=NULL;
while(Head!=NULL)
{
Temp=Head;
Head=Head->Next;
delete Temp;	
}
//iSize=0;
}
int Queue::Count()
{
	return (this->iSize);
}
void Queue::Display()
{
if(iSize==0)
{ cout<<"\nQueue is Empty. "; return; }
PNODE Temp=Head;
int c=iSize;
cout<<"\n________\n";
cout<<"| Temple|";
cout<<"\n|\t_";
do{
cout<<"|"<<(Temp->data)<<"|<--";
Temp=Temp->Next;
c--;
}while(c!=0);
cout<<"\n_________\n";
}
void Queue::Enqueue(int no)//InsertLast
{
PNODE newn=new NODE;
newn->data=no;
newn->Next=NULL;
if(iSize==0)
{
	Head=newn;
}else{
PNODE Temp=Head;
while(Temp->Next!=NULL)
{
	Temp=Temp->Next;
}
Temp->Next=newn;
}
iSize++;
Display();
}
int Queue::Dequeue()//DeleteFirst
{
if(iSize==0)
{ return -1; 
}else{
PNODE Temp=Head;
int r=Temp->data;
Head=Temp->Next;
delete Temp;
iSize--;
Display();
return r;
}
}	
int Queue::Peek()
{
int h=0;
if(iSize==0)
{ return -1;
}else{
h=(Head->data);	
return h;	
}
}

int main()
{
Queue* q=new Queue();
int iOpt=1,ians=0,ino=0;

while(iOpt!=0)
{
cout<<"\n____Queue Application_____";
cout<<"\nSelect any below option :";
cout<<"\n1. Enqueue an Element .";
cout<<"\n2. Dequeue an Element .";
cout<<"\n3. Display the Queue .";
cout<<"\n4. Get Count of Queue .";
cout<<"\n5. Peek next in Queue Element .";
cout<<"\n6. Save the data .";
cout<<"\n0. Exit the Application .";
cout<<"\n__________________";
cout<<"\nEntered option :";
cin>>iOpt;

switch(iOpt)
{
case 1:
		cout<<"\nEnter value of new Element :";
		cin>>ino;
		q->Enqueue(ino);
		break;
		
case 2:
		ians=q->Dequeue();
		if(ians==-1)
			cout<<"\nQueue Already Empty .";
		else
			cout<<"\nElement "<<ians<<" was DeQueued .";
		
		break;
case 3:
		q->Display();
		break;		

case 4:
		ians=q->Count();
		cout<<"\nTotal No of Elements in Queue :"<<ians;
		break;				

case 5:
		ians=q->Peek();
		if(ians==-1)
			cout<<"\nQueue is Empty .";
		else
			cout<<"\nElement "<<ians<<" is Next in Queue .";
		break;
		
case 0:
		cout<<"\nThank You for Using QueueApplication .";
		delete q;
		break;
		
default:
		cout<<"\nInvalid Input\nEnter Again";
		break;
	
}//switch	
}//while


return 0;
}
