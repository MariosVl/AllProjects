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
void insert_list_m_elements(ListPointer *List,int n);

int main()
{
    ListPointer List;
    int plithos,stoixeio,i,n;
    CreateList(&List);

     printf("DWSE TO PLITHOS TWN STOIXEIWN THS  LISTAS:");
     scanf("%d",&plithos);

     for(i=0;i<plithos;i++)
     {
      printf("DWSE TON ARITHMO GIA EISAGWGH STHN ARXI THS LISTAS :");
      scanf("%d",&stoixeio);
      LinkedInsert(&List,stoixeio,NULL);
     }

    printf("*********Arxiki Lista*********\n");
    LinkedTraverse(List);

    printf("DWSE THN THESI META THN OPOIA THA EISAXTHOYN TA STOIXEIA :");
    scanf("%d",&n);


    insert_list_m_elements(&List,n);


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



void insert_list_m_elements(ListPointer *List,int n)
{   int i=1,m,stoixeio;
    ListPointer CurrPtr;
    CurrPtr=*List;

    if(EmptyList(*List))
    {
        printf("EMPTY LIST");
    }
    else
    {


        while(i!=n &&CurrPtr!=NULL)
        {

         CurrPtr=CurrPtr->Next;
         i++;
         }

         if(CurrPtr!=NULL)
         {
            printf("DWSE PLITHOS TWN STOIXEIWN POY THA EISAXTHOYN:");
            scanf("%d",&m);

            for(i=0;i<m;i++)
            {
            printf("DWSE ARITHMO GIA EISAGWGI STHN LISTA:");
            scanf("%d",&stoixeio);
            LinkedInsert(List,stoixeio,CurrPtr);
            CurrPtr=CurrPtr->Next;
             }

         }
        else
        {
        printf("ERROR\n");
        }
        printf("*********Teliki Lista**********\n");
        LinkedTraverse(*List);
    }

}
