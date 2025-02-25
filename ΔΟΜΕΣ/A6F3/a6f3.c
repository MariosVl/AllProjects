#include <stdio.h>
#include <stdlib.h>
#define QueueLimit 10

typedef int QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
	int Count;
} QueueType;

typedef enum
{
    FALSE, TRUE
} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

int main()
{
    int i,item;
    QueueType Queue;

    CreateQ(&Queue);

    for(i=0;i<QueueLimit;i++)
    {
        AddQ(&Queue,i);
    }

    printf("---a---\n");
    TraverseQ(Queue);
    printf("Front=%d , Rear=%d , Count=%d\n",Queue.Front,Queue.Rear,Queue.Count);

    printf("---b---\n");
    AddQ(&Queue,52);
    TraverseQ(Queue);
    printf("Front=%d , Rear=%d , Count=%d\n",Queue.Front,Queue.Rear,Queue.Count);

    printf("---c---\n");
    RemoveQ(&Queue,&item);
    TraverseQ(Queue);
    printf("Removed Item=%d , Front=%d , Rear=%d , Count=%d\n",item,Queue.Front,Queue.Rear,Queue.Count);

    printf("---d---\n");
    AddQ(&Queue,25);
    TraverseQ(Queue);
    printf("Front=%d , Rear=%d , Count=%d\n",Queue.Front,Queue.Rear,Queue.Count);

    printf("---e---\n");
    AddQ(&Queue,85);
    TraverseQ(Queue);
    printf("Front=%d , Rear=%d , Count=%d\n",Queue.Front,Queue.Rear,Queue.Count);

    printf("---f---\n");

    while(!EmptyQ(Queue))
    {
        RemoveQ(&Queue,&item);
        TraverseQ(Queue);
        printf("Removed Item=%d , Front=%d , Rear=%d , Count=%d\n",item,Queue.Front,Queue.Rear,Queue.Count);

    }

}
void CreateQ(QueueType *Queue)
{
	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->Count=0;
}

boolean EmptyQ(QueueType Queue)
{
	return (Queue.Count==0);
}

boolean FullQ(QueueType Queue)
{
	return (Queue.Count==QueueLimit);
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
        Queue->Count=Queue->Count-1;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
		Queue->Count=Queue->Count+1;

	}
	else
		printf("Full Queue\n");
}
void TraverseQ(QueueType Queue)
{

	int current,i;

	printf("Queue: ");

	if(EmptyQ(Queue))
    {
        printf("Empty Stack");
    }
    else
    {

	  current = Queue.Front;
	  for(i=0;i<Queue.Count;i++)
       {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
       }
    }

      printf("\n");

}
