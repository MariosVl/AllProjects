#include <stdio.h>
#include <stdlib.h>
#define NumberOfNodes 10
#define NilValue -1

typedef int ListElementType;
typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void TraverseLinked(ListPointer List, NodeType Node[]);
void printALL(NodeType Node[]);
boolean Search(ListPointer FreePtr,ListPointer List, NodeType Node[NumberOfNodes],ListElementType item,ListPointer *PredPtr);

int main()
{
    ListPointer List, FreePtr,PredPtr;
    NodeType Node[NumberOfNodes];
    int item,i;
    char answer;
    InitializeStoragePool(Node,&FreePtr);
    CreateList(&List);
  printf("--------------Question C-------------\n");
  printf("--------------Storage pool-----------\n");
  printf("1o STOIXEIO LISTAS=%d , 1H FREE POSITION=%d\n",List,FreePtr);
  printf("H STORAGE POLL EXEI TA EJHS STOIXEIA\n");
  printALL(Node);
  printf("--------------Question D-------------\n");
  printf("--------------Linked list-----------\n");
  TraverseLinked(List,Node);

 printf("--------------Question E-------------\n");
do
{
    do
    {
        printf("Give a Number:");
        scanf("%d",&item);
        if(!Search(FreePtr,List,Node,item,&PredPtr))
        {
            Insert(&List,Node,&FreePtr,PredPtr,item);
        }
        printf("Do you want to continue?:(Y/N)");
          getchar();
        scanf("%c",&answer);

    }while(answer!='t'&&answer!='T'&& answer!='N'&& answer!='n');

       }while(answer!='N'&&answer!='n');
 printf("--------------Question F-------------\n");
 printf("--------------Storage pool-----------\n");
printf("1o STOIXEIO LISTAS= %d ,1H FREE POSITION= %d\n",List,FreePtr);
printf("H STORAGE POLL EXEI TA EJHS STOIXEIA\n");
printALL(Node);
printf("--------------Question G-------------\n");
printf("--------------Linked list-----------\n");
TraverseLinked(List,Node);
 printf("--------------Question H-------------\n");
if(EmptyList(List))
{
    printf("Empty List\n");
}
else
{
    printf("Not an empty list\n");
}
 printf("--------------Question É-------------\n");
if(FullList(FreePtr))
{
    printf("Full list\n");
}
else
{
    printf("Not a full list\n");
}
 printf("--------------Question J-------------\n");
 printf("---------------Search for a number------\n");
for(i=0;i<2;i++)
{
printf("Give a number:");
scanf("%d",&item);
if(Search(FreePtr,List,Node,item,&PredPtr))
{
    printf("The number is in the list and its predecessor is in position %d\n",PredPtr);

}
else
{
    printf("The number is not in the list\n ");

}

   }

}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)


{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=-1;
    *FreePtr=0;
}

void CreateList(ListPointer *List)

{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)

{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)

{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])

{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}


void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)

{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}



void TraverseLinked(ListPointer List, NodeType Node[])

{
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d: %d->%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}

void printALL(NodeType Node[])
{
     int i;
    for(i=0;i<NumberOfNodes;i++)
    {
        printf("(%d: %d->%d) ",i,Node[i].Data, Node[i].Next);

    }
    printf("\n");


}
boolean Search(ListPointer FreePtr,ListPointer List, NodeType Node[NumberOfNodes],ListElementType item,ListPointer *PredPtr)
{
    ListPointer CurrPtr;
    boolean stop=TRUE,found=FALSE;
    *PredPtr=NilValue;
 if(!EmptyList(List))
 {
        CurrPtr=List;

    while(CurrPtr!=NilValue  && stop)
    {
        if(Node[CurrPtr].Data>=item)
        {

            stop=FALSE;
            if(Node[CurrPtr].Data==item)
            {
            found=TRUE;
            }
        }
        else
        {
            *PredPtr=CurrPtr;
            CurrPtr=Node[CurrPtr].Next;
        }
    }

 }

    return found;

}
