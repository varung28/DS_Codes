//StudentDBHeader.h
#include<stdio.h>
#include<stdlib.h>
struct Student
{
int RollNo;
char fName[50];
int Age;
char bloodGrp[3];


struct Student* Next;
};
typedef struct Student NODE;
typedef struct Student* PNODE;
typedef struct Student** PPNODE;

//function declarations

void Display(PNODE);
void DisplayAtRollNo(PNODE,int);
int Count(PNODE);

void InsertFirst(PPNODE,int,char[],int);
void InsertLast(PPNODE,int,char[],int);
void InsertAtLocation(PPNODE,int,char[],int,int iPos);

void DeleteFirst(PPNODE);
void DeleteLast(PPNODE );
void DeleteAtLocation(PPNODE ,int );
void DeleteAtRollNo(PPNODE,int);

void DisplaySave(PNODE);
