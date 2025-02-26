#include <stdio.h>
#include <stdlib.h>

typedef int ListElementType;

typedef struct ListNode *ListPointer;
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
ListElementType RemoveMins(ListPointer *InList);

int main()
{
    int plithos,i,stoixeio;
    ListPointer List;
    ListElementType min;

    CreateList(&List);

  printf("DWSE TO PLITHOS TWN STOIXEIWN THS  LISTAS:");
  scanf("%d",&plithos);

  for(i=0;i<plithos;i++)
  {
      printf("DWSE TON ARITHMO GIA EISAGWGH STHN ARXI THS LISTAS 1:");
      scanf("%d",&stoixeio);
      LinkedInsert(&List,stoixeio,NULL);
  }
  printf("Traversing list\n");
  LinkedTraverse(List);

  printf("Removing min from list\n");
  min=RemoveMins(&List);
  printf("Min was %d\n",min);

  printf("Traversing list with min removed\n");
  LinkedTraverse(List);

}
void CreateList(ListPointer *List)

{
	*List = NULL;
}

boolean EmptyList(ListPointer List)

{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)

{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));

   TempPtr->Data = Item;
	if (PredPtr==NULL)
    {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else
    {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)

{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)

{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;

         while ( CurrPtr!=NULL )
        {
             printf("%d ",CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
   printf("\n");
}


ListElementType RemoveMins(ListPointer *InList)
{
    ListPointer CurrPtr,PredPtr;
    ListElementType min;
    CurrPtr=*InList;
    min=CurrPtr->Data;
    while(CurrPtr!=NULL)
    {
        if(CurrPtr->Data<=min)
        {
            min=CurrPtr->Data;
        }
        CurrPtr=CurrPtr->Next;
    }
    CurrPtr=*InList;
    PredPtr=NULL;
    while(CurrPtr!=NULL)
    {
        if(CurrPtr->Data==min)
        {
             CurrPtr=CurrPtr->Next;
            LinkedDelete(InList,PredPtr);
        }
        else
        {      PredPtr=CurrPtr;
               CurrPtr=CurrPtr->Next;

        }



    }

    return min;
}

