#include <stdio.h>
#include <stdlib.h>
#define StackLimit 15

typedef int StackElementType;

typedef enum
{
   FALSE,TRUE
}boolean;

typedef struct
{
    int Top;
    StackElementType Element[StackLimit];
}StackType;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);
void PrintDetails(int x,int plithos,StackType Stack);
void Unchanged_Stack(StackType *Stack,StackType *Stack1,int *x, int limit);
void Changed_Stack(StackType *Stack, int *x,int limit,int *plithos);

int main()
{
   int i,x,plithos=0,n,item;
   StackType Stack,Stack1;
   CreateStack(&Stack);
   CreateStack(&Stack1);
   for(i=0;i<StackLimit;i++)
   {
       Push(&Stack,i*10);
       plithos++;
   }
    printf("plithos sto stack %d\n",plithos);
    TraverseStack(Stack);
    printf("\n");
    do{

       printf("Give nth element (n<=6)");
       scanf("%d",&n);

    }while(n>(Stack.Top-1)/2);

    Changed_Stack(&Stack,&x,2,&plithos);
    printf("Question a :");
    PrintDetails(x,plithos,Stack);

    Unchanged_Stack(&Stack,&Stack1,&x,2);
    printf("Question b :");
    PrintDetails(x,plithos,Stack);

    Changed_Stack(&Stack,&x,n,&plithos);
    printf("Question c :");
    PrintDetails(x,plithos,Stack);

    Unchanged_Stack(&Stack,&Stack1,&x,n);
    printf("Question d :");
    PrintDetails(x,plithos,Stack);

    Unchanged_Stack(&Stack,&Stack1,&x,plithos);
    printf("Question e :");
    PrintDetails(x,plithos,Stack);

    Unchanged_Stack(&Stack,&Stack1,&x,plithos-2);
    printf("Question f :");
    PrintDetails(x,plithos,Stack);

    Changed_Stack(&Stack,&x,plithos,&plithos);
    printf("Question g :");
    PrintDetails(x,plithos,Stack);

}
void Unchanged_Stack(StackType *Stack,StackType *Stack1,int *x,int limit)
{
    int i,item;

    for(i=0;i<limit;i++)
    {
        Pop(Stack,&item);
        Push(Stack1,item);
    }

    *x=item;

    for(i=0;i<limit;i++)
    {
        Pop(Stack1,&item);
        Push(Stack,item);
    }

}

void Changed_Stack(StackType *Stack, int *x,int limit,int *plithos)
{
    int i,item;

    for(i=0;i<limit;i++)
    {
        Pop(Stack,&item);
        *plithos=*plithos-1;
    }

    *x=item;

}

void PrintDetails(int x,int plithos,StackType Stack)
{
     printf("x=%d\n",x);
     printf("plithos sto stack %d\n",plithos);
     TraverseStack(Stack);
     printf("\n");
     printf("\n");

}

void TraverseStack(StackType Stack)
{
    int i;

    for(i=0;i<=Stack.Top;i++)
    {
        printf("%d ",Stack.Element[i]);
    }

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
    if (!FullStack(*Stack))
    {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    }
    else
        printf("Full Stack...");

}

void Pop(StackType *Stack, StackElementType *Item)

{
    if (!EmptyStack(*Stack))
    {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    }
    else
        printf("Empty Stack...");

}


