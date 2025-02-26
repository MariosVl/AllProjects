#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int code;
    int priority;

}PERIEXOMENO;

typedef PERIEXOMENO QueueElementType;

typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void TraverseQ(QueueType Queue);
void insert_prot(QueueType *Queue, QueueElementType Item);

int main()
{
    int i,plithos;
    QueueElementType KOMVOS;
    QueueType Queue;

    CreateQ(&Queue);

    printf("DWSE PLITHOS:");
    scanf("%d",&plithos);

    for(i=0;i<plithos;i++)
    {
        printf("DWSE KWDIKO %dou komvou:",i+1);

        do
        {
            scanf("%d",&KOMVOS.code);
        }while(KOMVOS.code<100||KOMVOS.code>999);

        printf("DWSE ARITHMO PROTERAIOTHTAS:");
        scanf("%d",&KOMVOS.priority);

        insert_prot(&Queue,KOMVOS);
    }

    printf("---------Priority Queue-----------------\n");
    TraverseQ(Queue);
}

void CreateQ(QueueType *Queue)
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
{
	return (Queue.Front==NULL);
}

void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d %d", CurrPtr->Data.priority,CurrPtr->Data.code);
      	      printf("\n");
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}

void insert_prot(QueueType *Queue, QueueElementType Item)
{
  QueuePointer CurrPtr,PredPtr,TempPtr;
  boolean flag=TRUE;

  TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
  TempPtr->Data=Item;
  TempPtr->Next=NULL;

  if(EmptyQ(*Queue))
  {
      Queue->Front=TempPtr;
      Queue->Rear=TempPtr;

  }
  else
  {
      PredPtr=Queue->Front;
      CurrPtr=Queue->Front;
      if(Item.priority<Queue->Front->Data.priority)
      {
          TempPtr->Next=Queue->Front;
          Queue->Front=TempPtr;

      }
      else
      {
          while(CurrPtr!=NULL &&flag)
          {
              if(Item.priority<CurrPtr->Data.priority)
              {
                  TempPtr->Next=PredPtr->Next;
                  PredPtr->Next=TempPtr;
                  flag=FALSE;
              }
              PredPtr=CurrPtr;
              CurrPtr=CurrPtr->Next;
          }

          if(flag)
          {
              PredPtr->Next=TempPtr;
              TempPtr->Next=NULL;
              Queue->Rear=TempPtr;
          }
      }
  }
}





