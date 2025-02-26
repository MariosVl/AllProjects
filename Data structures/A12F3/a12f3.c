#include <stdio.h>
#include <stdlib.h>
#define QueueLimit 4

typedef struct {
    int arrival,stay;
    int start,end;
}QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
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
void TraverseQ(char name[],QueueType Queue);
void WaitInQueue(QueueType *Queue);
QueueType ServiceInQueue(QueueType *Queue);

int main()
{
    QueueType Wait, Service;

    CreateQ(&Wait);
    CreateQ(&Service);

    WaitInQueue(&Wait);
    char name1[]="Waiting";
    TraverseQ(name1,Wait);

    Service=ServiceInQueue(&Wait);
    TraverseQ(name1,Wait);
    char name2[]="Service";
    TraverseQ(name2,Service);

}

void CreateQ(QueueType *Queue)
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue");
}

void TraverseQ(char name[],QueueType Queue) {
	int current,client=0;

    if(!EmptyQ(Queue))
    {
      printf("%s Queue\n",name);
	  current = Queue.Front;
	  printf("Client \t\tStart\tEnd\tArrival\tStay\n");
	  while (current != Queue.Rear)
      {
         client++;
         printf("Client %d\t%d\t%d\t%d\t%d\t ",client, Queue.Element[current].start, Queue.Element[current].end, Queue.Element[current].arrival, Queue.Element[current].stay);
		 current = (current + 1) % QueueLimit;
         printf("\n");
	   }
    }
    else
    {

        printf("%s Queue is empty ",name);

    }
    printf("\n");

}
void WaitInQueue(QueueType *Queue)
{
    QueueElementType TR;
    int i;

    TR.start=-1;
    TR.end=-1;

    for(i=0;i<QueueLimit-1;i++)
    {
        printf("Give arrival time, stay time for client %d:",i+1);
        scanf("%d,%d",&TR.arrival,&TR.stay);
        AddQ(Queue,TR);
    }

}
QueueType ServiceInQueue(QueueType *Queue)
{
    int serviceStart=0;
    QueueElementType item;
    QueueType Queue2;

    CreateQ(&Queue2);

    while(!EmptyQ(*Queue))
    {
       RemoveQ(Queue,&item);
       if(item.arrival>serviceStart)
        {
        item.start=item.arrival;

        }
        else
        {

        item.start=serviceStart;

         }

    item.end=item.start+item.stay;
    serviceStart=item.end;
    AddQ(&Queue2,item);

    }

    return Queue2;

}


