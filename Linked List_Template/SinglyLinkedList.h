/*
SinglyLinkedList.h

*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node* Next;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

//function prototypes
void InsertFirst(PPNODE,int);
void InsertLast(PPNODE,int);
void InsertAtPosition(PPNODE,int,int);
void DeleteFirst(PPNODE,int);
void DeleteLast(PPNODE,int);
void DeleteAtPosition(PPNODE,int,int);

int Count(PNODE);
void DisplaySave(PNODE);
void Display(PNODE);