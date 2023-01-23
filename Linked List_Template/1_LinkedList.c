/*

1_LinkedList.c
*/
#include "SinglyLinkedList.h"


int main()
{
int iOption=1,idata=0,ipos=0,ians=0;
char flag;
PNODE First=NULL;
while(iOption!=0)
{
printf("\n_________________________________________________________\n");
printf("\nWelcome to Linked List Application of SinglyLinked List (in C)\n");
printf("_________________________________________________________");
printf("\n1. Insert Node at 1st Position");
printf("\n2. Insert Node at Last Position");
printf("\n3. Insert Node at Any Position");
printf("\n4. Delete Node at 1st Position");
printf("\n5. Delete Node at Last Position");
printf("\n6. Delete Node at Any Position");
printf("\n7. Display All Nodes");
printf("\n8. Print Count of Total Nodes");
printf("\n9. Display and Save current Nodes in a File");
printf("\n0. Exit from the application");
printf("\n_________________________________________________________");
printf("\nSelect one of the Above option: ");
scanf("%d",&iOption);

switch(iOption)
{

case 1:
	printf("\nEnter the no you want to Insert :");
	scanf("%d",&idata);
	InsertFirst(&First,idata);
	break;

case 2:
	printf("\nEnter the no you want to Insert :");
	scanf("%d",&idata);
	InsertLast(&First,idata);
	break;

case 3:
	printf("\nEnter the no you want to Insert :");
	scanf("%d",&idata);
	printf("\nEnter Position you want for new data :");
	scanf("%d",&ipos);
	InsertAtPosition(&First,idata,ipos);
	break;

case 7:
	Display(First);
	break;

case 8:
	ians=Count(First);
	printf("\nTotal No of Nodes in LinkedList :%d",ians);
	break;

case 0:
	printf("\nThank You for using Linked List App\nyou want to save data before closing ?\nN:(No i have saved)\nY:(Yes Save it again)\n");
	scanf(" %c",&flag);
	if(flag=='Y' || flag=='y')
	{
	DisplaySave(First);
	printf("\nData Saved\nClosing Application");
	exit(0);
	}else if(flag=='N' || flag=='n'){
	printf("\nClosing Application");
	exit(0);
	}else{
	printf("\nClosing Application");
	exit(0);
	}

default:
	printf("\nInvalid Option .\nSelect again ");
	break;

}

}


return 0;
}
