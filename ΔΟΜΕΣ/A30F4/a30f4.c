#include <stdio.h>
#include <stdlib.h>

#define NumberOfNodes 10
#define NilValue -1
#define StackLimit 50

typedef struct
{
    int AM;
    float grade;

} Student;

typedef Student ListElementType;

typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

typedef int StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;


void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void TraverseLinked(ListPointer List, NodeType Node[]);
void printALL(NodeType Node[]);

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);

float FindMins(ListPointer List, NodeType Node[NumberOfNodes],StackType *Stack);

int main()
{
  ListPointer PredPtr=NilValue, FreePtr,List;
  int i,stoixeio;
  float min;
  ListElementType item;
  NodeType Node[NumberOfNodes];
  StackType Stack;

  InitializeStoragePool(Node,&FreePtr);
  printf("--------------Question C-------------\n");
  printf("--------------Storage pool-----------\n");
  printf("1o STOIXEIO LISTAS=%d , 1H FREE POSITION=%d\n",List,FreePtr);
  printf("H STORAGE POLL EXEI TA EJHS STOIXEIA\n");
  printALL(Node);

  CreateList(&List);
  printf("--------------Question D-------------\n");
  printf("--------------Linked list-----------\n");
  TraverseLinked(List,Node);

  printf("--------------Question E-------------\n");
  for(i=0;i<5;i++)
  {
      printf("DWSE AM GIA EIDAGWGH STHN LISTA:");
      scanf("%d",&item.AM);
      printf("DWSE VATHMO GIA EIDAGWGH STHN LISTA:");
      scanf("%f",&item.grade);
      Insert(&List,Node,&FreePtr,PredPtr,item);
  }

  printf("--------------Question F-------------\n");
  printf("--------------Storage pool-----------\n");
  printf("1o STOIXEIO LISTAS=%d , 1H FREE POSITION=%d\n",List,FreePtr);
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

printf("--------------Question I-------------\n");
if(FullList(FreePtr))
{
    printf("Full list\n");
}
else
{
    printf("Not a full list\n");
}

printf("--------------Question J-------------\n");
min=FindMins(List,Node,&Stack);
printf("Min value= %.1f\n",min);
printf("AM with min grade:");
while(!EmptyStack(Stack))
{
    Pop(&Stack,&stoixeio);
    printf("%d ",stoixeio);
}
printf("\n");
printf("--------------Question K-------------\n");
TraverseStack(Stack);

printf("--------------Question L-------------\n");
printf("--------------Storage pool-----------\n");
printf("1o STOIXEIO LISTAS=%d , 1H FREE POSITION=%d\n",List,FreePtr);
printALL(Node);

printf("--------------Question M-------------\n");
printf("--------------Linked list-----------\n");
TraverseLinked(List,Node);

}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.AM=-1;
        Node[i].Data.grade=-1.0;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.AM=-1;
    Node[NumberOfNodes-1].Data.grade=-1.0;
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
        printf("(%d:<%d,%.1f>->%d) ",CurrPtr,Node[CurrPtr].Data.AM,Node[CurrPtr].Data.grade, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}


void CreateStack(StackType *Stack)

{
    Stack -> Top = -1;

}

boolean EmptyStack(StackType Stack)

{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)

{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)

{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=Stack.Top;i>=0;i--) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
void printALL(NodeType Node[])
{
     int i;
    for(i=0;i<NumberOfNodes;i++)
    {
        printf("(%d:<%d,%.1f>->%d) ",i,Node[i].Data.AM,Node[i].Data.grade, Node[i].Next);

    }
    printf("\n");

}
float FindMins(ListPointer List, NodeType Node[NumberOfNodes],StackType *Stack)
{
    ListPointer CurrPtr;
    float min;
    int item;
    CreateStack(Stack);

    if(!EmptyList(List))
    {
         CurrPtr=List;
         min=Node[CurrPtr].Data.grade;
        while(CurrPtr!=NilValue)
        {
           if(Node[CurrPtr].Data.grade<=min)
           {


               if((Node[CurrPtr].Data.grade==min)|| EmptyStack(*Stack) )
               {
                   Push(Stack,Node[CurrPtr].Data.AM);
               }

               else
               {
                   while(!EmptyStack(*Stack))
                   {
                       Pop(Stack,&item);


                   }
                    Push(Stack,Node[CurrPtr].Data.AM);
               }
              min=Node[CurrPtr].Data.grade;
           }
            CurrPtr=Node[CurrPtr].Next;
        }
    }
    else
    {
        printf("Empty List");
    }
    return min;
}
