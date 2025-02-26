#include <stdio.h>
#include <stdlib.h>

typedef int StackElementType;

typedef struct StackNode *StackPointer;

typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
void TraverseStack(StackPointer Stack);

int main()
{
    int plithos,i,item;
    StackPointer Stack1,Stack2;

    CreateStack(&Stack1);
    CreateStack(&Stack2);

    printf("DWSE PLITHOS:");
    scanf("%d",&plithos);

    for(i=0;i<plithos;i++)
    {
        printf("DWSE TO %do stoixeio :",i+1);
        scanf("%d",&item);
        Push(&Stack1,item);
    }

    printf("******1i stoiba******\n");
    TraverseStack(Stack1);

    while(!EmptyStack(Stack1))
    {
        Pop(&Stack1,&item);
        Push(&Stack2,item);
    }

    printf("******2i stoiba******\n");
    TraverseStack(Stack2);
}
void CreateStack(StackPointer *Stack)
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}
void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
