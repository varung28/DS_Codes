//StudentDBHelper.c
#include "StudentDBHeader.h"

int iSize=0;
int fd=0;
//definitions below
int Count(PNODE Head)
{
	return iSize;
}

void DisplayAtRollNo(PNODE Head,int no)
{
//code
int i=iSize;
PNODE Temp=NULL;	Temp=Head;
if(i==0)
{ printf("\nAlready Empty"); return; }
while(i!=0)
{
	if(Temp->RollNo==no)
	{
	printf("\n|RollNo\t|Name\t|Age\t|");
	printf("\n+______\t+____\t+___\t+");	
	printf("\n|%d\t|%s\t|%d\t|",(Temp->RollNo),(Temp->fName),(Temp->Age));
	break;
	}
	i--;
	Temp=Temp->Next;
}//while
if(Temp==NULL)
	printf("\nRollNo Not Found ");
}//funct

void Display(PNODE Head)
{
int c=iSize;
if(c==0)
{
	printf("\nDatabase is Currently Empty.");	return;
}
PNODE Temp=Head;
printf("\n|RollNo\t|Name\t|Age\t|");
printf("\n+______\t+____\t+___\t+");
while(c!=0)
{
printf("\n|%d\t|%s\t|%d\t|",(Temp->RollNo),(Temp->fName),(Temp->Age));
Temp=Temp->Next;
c--;
}	
}

void InsertFirst(PPNODE Head,int no,char name[],int age)
{
PNODE newn=NULL;
newn=(PNODE)malloc(sizeof(NODE));
if(newn==NULL)
{
	printf("\nmalloc failed ");	return;
}
newn->RollNo=no;
newn->Age=age;
newn->Next=NULL;
int i=0;
while(name[i]!='\0')
{
	newn->fName[i]=name[i];
	i++;
}
i=0;
/*while(bldGrp[i]!='\0')
{
	newn->bloodGrp[i]=bldGrp[i];
	i++;
}	*/

PNODE Temp=NULL;
Temp=*Head;
if(*Head==NULL)
{
	printf("\n\t\tLL is Empty");
	*Head=newn;
}else{
		printf("\n\t\tLL is NOT Empty");
newn->Next=*Head;
*Head=newn;
}//else
iSize++;
printf("\nEntry added successfully");
printf("\nPrinting List aft Done :\n");
Display(*Head);
}


void InsertLast(PPNODE Head,int no,char name[],int age)
{
PNODE newn=NULL;
newn=(PNODE)malloc(sizeof(NODE));
if(newn==NULL)
{
	printf("\nmalloc failed ");	return;
}
newn->Next=NULL;
newn->RollNo=no;
newn->Age=age;
int i=0;
while(name[i]!='\0')
{
	newn->fName[i]=name[i];
	i++;
}

/*i=0;
while(bldGrp[i]!='\0')
{
	newn->bloodGrp[i]=bldGrp[i];
	i++;
}	*/
if(*Head==NULL)
{
	*Head=newn;
}else{
PNODE Temp=NULL;
Temp=*Head;
while(Temp->Next!=NULL)
{
	Temp=Temp->Next;
}
Temp->Next=newn;
}//else	
iSize++;	
printf("\nEntry Added\nPrinting aft Done :\n");
Display(*Head);
}
void InsertAtLocation(PPNODE Head,int no,char name[],int age,int iPos)
{
int c=iSize;

if(iPos<1 ||iPos>(c+1))
{
	printf("\nInvalid Position");	return;
}

if(iPos==1)
{
	InsertFirst(Head,no,name,age);
}else if(iPos==(c+1))
{
	InsertLast(Head,no,name,age);
}else{
PNODE newn=NULL;
newn=(PNODE)malloc(sizeof(NODE));
if(newn==NULL)
{
	printf("\nmalloc failed");	return;
}
newn->Next=NULL;
newn->RollNo=no;
newn->Age=age;
int i=0;
while(i!='\0')
{	newn->fName[i]=name[i]; i++; }
PNODE Temp=NULL;
Temp=*Head;
for(i=1;i<iPos-1;i++)
{
	Temp=Temp->Next;
}
newn->Next=Temp->Next;
Temp->Next=newn;
iSize++;
printf("\nEntry Added successfully\n");
Display(*Head);
}//else	
}

void DeleteFirst(PPNODE Head)
{
if(iSize==0)
{
	printf("\nAlready Empty");
	return;
}else if(iSize==1)
{
	free (*Head);	*Head=NULL;
}else{
PNODE Temp=NULL;
Temp=*Head;
*Head=Temp->Next;
free(Temp);	
}
iSize--;
printf("\nDelete Successfull ."); Display(*Head);
}
void DeleteLast(PPNODE Head)
{
	if(iSize==0)
{
	printf("\nAlready Empty");
	return;
}else if(iSize==1)
{
	free (*Head);	*Head=NULL;
}else{
PNODE Temp=NULL;
Temp=*Head;
while((Temp->Next)->Next!=NULL)
{
	Temp=Temp->Next;
}
free ((Temp->Next));
Temp->Next=NULL;
}//else
iSize--;
printf("\nDelete Successfull ."); Display(*Head);
}
void DeleteAtLocation(PPNODE Head,int iPos)
{
int c=iSize;
if(c==0)
{ printf("\nAlready Empty"); return; }
if(iPos<1 || iPos>=c)
{ printf("\n\t####Invalid Position####"); return;	
}
if(iPos==1)
{
	DeleteFirst(Head);
}else if(iPos==c)
{
	DeleteLast(Head);
}else{
PNODE Temp=NULL;
PNODE Target=NULL;
Temp=*Head;
for(int i=1;i<iPos-1;i++)
{
	Temp=Temp->Next;
}
Target=Temp->Next;
Temp->Next=Target->Next;
free(Target);
iSize--;
printf("\nDelete Successfull ."); Display(*Head);
}//else
}
void DeleteAtRollNo(PPNODE Head,int no)
{
//code

PNODE Temp=NULL;	Temp=*Head;
PNODE Target=NULL;
if(iSize==0)
{ printf("\nAlready Empty"); return; }
if(Temp->RollNo==no)
{
	DeleteFirst(Head);
}else{
	while((Temp->Next)->RollNo!=no)
	{
Temp=Temp->Next;		
	}
Target=Temp->Next;
Temp->Next=Target->Next;
free (Target);
iSize--;
printf("\nDelete successfull\n");	Display(*Head);
return;
}
if(Temp==NULL)
	printf("\nRollNo Not Found ");
}

void DisplaySave(PNODE Head)
{
//code
printf("\ninside SaveFunction");
fd=open("StudentTableOne.txt",777);
if(fd!=0)
{
 	printf("\nFile opended with fd :%d",fd);
}else{
	printf("\nFailed to Open File ");	
}

printf("\nclosing file now ");
close(fd);

}
