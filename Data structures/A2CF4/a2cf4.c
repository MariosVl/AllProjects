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
void LinkedTraverse(ListPointer List);
void concat_list(ListPointer List, ListPointer BList, ListPointer *FinalList);
int main()
{
  ListPointer List1,List2,FinalList;
  int plithos1, plithos2,i,stoixeio;

  CreateList(&List1);
  CreateList(&List2);
  CreateList(&FinalList);

  printf("DWSE TO PLITHOS TWN STOIXEIWN THS 1HS LISTAS:");
  scanf("%d",&plithos1);

  for(i=0;i<plithos1;i++)
  {
      printf("DWSE TON ARITHMO GIA EISAGWGH STHN ARXI THS LISTAS 1:");
      scanf("%d",&stoixeio);
      LinkedInsert(&List1,stoixeio,NULL);
  }

  printf("DWSE TO PLITHOS TWN STOIXEIWN THS 2HS LISTAS:");
  scanf("%d",&plithos2);

  for(i=0;i<plithos2;i++)
  {
      printf("DWSE TON ARITHMO GIA EISAGWGH STHN ARXI THS LISTAS 2:");
      scanf("%d",&stoixeio);
      LinkedInsert(&List2,stoixeio,NULL);
  }
  printf("LISTA 1:\n");
  LinkedTraverse(List1);

  printf("LISTA 2:\n");
  LinkedTraverse(List2);

  printf("SYNENWMENH LISTA:\n");
  concat_list(List1,List2,&FinalList);

}
void CreateList(ListPointer *List)

{
	*List = NULL;
}
boolean EmptyList(ListPointer List)
{
    return(List==NULL);
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


void concat_list(ListPointer List, ListPointer BList, ListPointer *FinalList)
{
    ListPointer CurrPtr;

    CurrPtr=List;
    while(CurrPtr!=NULL)
    {
        LinkedInsert(FinalList,CurrPtr->Data,NULL);
        CurrPtr=CurrPtr->Next;

    }
    CurrPtr=BList;
    while(CurrPtr!=NULL)
    {
        LinkedInsert(FinalList,CurrPtr->Data,NULL);
        CurrPtr=CurrPtr->Next;
    }

    LinkedTraverse(*FinalList);
}
