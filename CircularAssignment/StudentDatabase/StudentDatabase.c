/*

StudentDatabase.c

*/

//#include<stdio.h>
//#include<stdlib.h>
#include "StudentDBHeader.h"

//int iSize=0; will be ReDefinition here
int main()
{
PNODE First=NULL;
int rollno=0,age=0,iOpt=1,iPos=0,iAns=0;
char Name[50];
char BGroup[3];
char flag;


while(iOpt!=0)
{
//Name=(char *)malloc(sizeof(char)*50);
		printf("\n______________________________________________\n");
	    printf("\n____This is Application For Student's Database_____\n");
        printf("Please select one of below:\n");
		printf("********************************\n");
        printf("1 : Add a Student Entry at 1st Position .\n");
        printf("2 : Add a Student Entry at Last position.\n");
        printf("3 : Add a Student Entry at Specific position.\n");
        printf("4 : Delete 1st Student Entry .\n");
        printf("5 : Delete Last Student Entry.\n");
        printf("6 : Delete a Specific Student Entry .\n");
        printf("7 : Display All Student Entries .\n");
        printf("8 : Get No of Total Student Entries .\n");
		printf("9 : Display Student details of Roll No :\n");
		printf("10: Delete entry of a Roll No :\n");
		printf("11: Save Database \n");
        printf("0 : Save and Exit the application\n	");
		printf("\n\nEntered Option :");
        scanf("%d",&iOpt);
        printf("********************************\n");	

switch(iOpt)
{
case 1:
	printf("\nEnter Roll No for New Student :");
	scanf("%d",&rollno);
	printf("\nEnter Full Name of New Student :");
	scanf(" %[^'\n']s",Name);
	printf("\nEnter Age of New Student :");
	scanf(" %d",&age);
//	printf("\nEnter Blood Group of New Student :");
//	scanf(" %[^'\n']s",BGroup);	
	InsertFirst(&First,rollno,Name,age);
	break;

case 2:
	printf("\nEnter Roll No for New Student :");
	scanf("%d",&rollno);
	printf("\nEnter Full Name of New Student :");
	scanf(" %[^'\n']s",Name);
	printf("\nEnter Age of New Student :");
	scanf(" %d",&age);
//	printf("\nEnter Blood Group of New Student :");
//	scanf(" %[^'\n']s",BGroup);	
	InsertLast(&First,rollno,Name,age);
	break;

case 3:
		printf("\nEnter Location :");
		scanf("%d",&iPos);
	printf("\nEnter Roll No for New Student :");
	scanf("%d",&rollno);
	printf("\nEnter Full Name of New Student :");
	scanf(" %[^'\n']s",Name);
	printf("\nEnter Age of New Student :");
	scanf(" %d",&age);
//	printf("\nEnter Blood Group of New Student :");
//	scanf(" %[^'\n']s",BGroup);
	InsertAtLocation(&First,rollno,Name,age,iPos);
		break;
case 4:
		DeleteFirst(&First);
		break;
case 5:
		DeleteLast(&First);
		break;
		
case 6:
		printf("\nEnter Location :");
		scanf("%d",&iPos);;
		DeleteAtLocation(&First,iPos);
		break;
case 7:
		Display(First);
		break;

case 8:
		iAns=Count(First);
		printf("\nTotal No of Studnet :%d",iAns);	
		break;	
		
case 9:
		printf("\nEnter RollNo of Student to get details :");
		scanf("%d",&rollno);
		DisplayAtRollNo(First,rollno);	
		break;
		
case 10:
		printf("\nEnter RollNo of Student to Delete Entry :");
		scanf("%d",&rollno);
		DeleteAtRollNo(&First,rollno);

		break;

case 11:
		
		DisplaySave(First);
	printf("\nData Saved\n");
		break;
		
case 0:
	printf("\nThank You for using Linked List App\nyou want to save data before closing ?\nN:(No i have saved)\nY:(Yes Save it again)\n");
	
	DisplaySave(First);
	printf("\nData Saved\nClosing Application");
	
	printf("\nClosing Application");
	exit(0);
	
	break;

default:
		printf("\nInvalid Input\nTry again");
		break;
	
}//switch
}//while


return 0;
}

