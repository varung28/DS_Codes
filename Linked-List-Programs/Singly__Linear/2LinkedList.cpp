/*
SinglyLinear LL in C++

2LinkedList.cpp

*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node
{
int data;
struct node* Next;
//struct node* Prev;
};
typedef struct node NODE;
typedef struct node* PNODE;
//typedef struct node** PPNODE;
/*
typedef struct node
{
	int data;
	struct node *next;
	struct node *next;
}NODE,*PNODE,**PPNODE;
*/
class SinglyLL
{
	private:
		PNODE Head;
		int iSize=0;
	public:
			int count=0;
		SinglyLL()
		{
			Head=NULL;
			iSize=0;
		}
void InsertFirst(int no)
		{

		PNODE newn=NULL;
		newn=new NODE;
		newn->data=no;
		newn->Next=NULL;
		
		
		if(this->Head==NULL)
		{
		this->Head=newn;
		}else{
		newn ->Next = this->Head;
        this->Head = newn;	
		}
iSize++;			
		}
		
void DeleteFirst()
{
		if(this->Head!=NULL)
		{
		PNODE temp=Head;	
		Head=Head->Next;
		delete temp;
	iSize--;		
		}else{
			return;
		}
			
}//fuctn

void DeleteLast()
{		
		if(this->Head!=NULL)
		{
		return;
		}else if(Head->Next==NULL)
		{
		delete Head;
		Head=NULL;
		iSize--;
		}
		else{
		PNODE temp=Head;	
		while(temp->Next->Next!=NULL)
		{
			temp=temp->Next;
		}
		delete (temp->Next);
		temp->Next=NULL;
		iSize--;
		}

}
	
void InsertLast(int no)
{

		PNODE newn=NULL;
		newn=new NODE;
		newn->data=no;
		newn->Next=NULL;
		PNODE temp=Head;
		
		
		if(this->Head==NULL)
		{
		this->Head=newn;
		}else{
	
		while(temp->Next!=NULL)
		{
			temp=temp->Next;
		}
		temp->Next=newn;
	
		}
iSize++;			
}
		


		int Count()
		{
			return iSize;
		}
		
		void Display()
		{
		PNODE temp=Head;
		
		while(temp->Next!=NULL)
		{
		cout<<"| "<<temp->data<<"|->";					
		temp=temp->Next;
		}
		cout<<"\n->NULL";
		}

};
int main()
{
int iOpt=1,iPos=0,ino=0,ians=0;

SinglyLL L1;

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
        printf("0 : Exit the application\n	");
        scanf("%d",&iOpt);
        printf("********************************\n");	
		
switch(iOpt)
{

case 1:
	cout<<"\nEnter data to Insert :";
	cin>>ino;
		L1.InsertFirst(ino);
		break;

case 2:
		cout<<"\nEnter data to Insert :";
		cin>>ino;
		L1.InsertLast(ino);
		break;

case 3:

		break;
case 4:
		L1.DeleteFirst();
		break;
case 5:
		L1.DeleteLast();
		break;
		
case 6:
		break;
case 7:
		L1.Display();
		break;

case 8:
		ians=L1.Count();
		cout<<"\nCount of Nodes in LL :"<<ians;	
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
