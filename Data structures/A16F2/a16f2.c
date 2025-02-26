#include <stdio.h>
#include<stdlib.h>
#define StackLimit 15

typedef enum
{
    FALSE,TRUE
}boolean;

typedef struct
{
    char Size;
    int price;
}StackElementType;

typedef struct
{
    int Top;
    StackElementType Element[StackLimit];
}StackType;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);
void PrintDetails(StackType Stack, StackType Stack1,int plithos,int plithos1);

int main()
{
    int Total_number,i,plithos=0,plithos1=0;
    char size;
    StackElementType TS;
    boolean flag=TRUE;
    StackType Stack,Stack1;
    do
    {
        printf("Give number of Items(0-15): ");
        scanf("%d",&Total_number);

    }while(Total_number>StackLimit);

    CreateStack(&Stack);
    CreateStack(&Stack1);

    printf("Give the items to store\n");
    for(i=0;i<Total_number;i++)
    {
        printf("Give price:");
        scanf("%d",&TS.price);

       do{

            getchar();
            printf("Give size:");
            scanf("%c",&TS.Size);
         }while(!(TS.Size=='L'||TS.Size=='M'||TS.Size=='S'));

         Push(&Stack,TS);
         plithos++;
    }

    printf("Items in the box\n");
    printf("plithos sto stack:%d\n",plithos);
    TraverseStack(Stack);

    printf("What size do you want?");
    getchar();
    scanf("%c",&size);

     while(flag==TRUE&&plithos>0)
     {
         Pop(&Stack,&TS);
         plithos--;
         if(TS.Size==size)
         {
            printf("Found the size:%c \n",size);
            flag=FALSE;

         }

         else
         {
            Push(&Stack1,TS);
            plithos1++;
         }
      }

        if(flag==TRUE)
        {
            printf("Not Found Size %c\n",size);
        }

       PrintDetails(Stack,Stack1,plithos,plithos1);

        while(plithos1>0)
        {
            Pop(&Stack1,&TS);
            plithos1--;
            Push(&Stack,TS);
            plithos++;
        }

        PrintDetails(Stack,Stack1,plithos,plithos1);


}

void PrintDetails(StackType Stack, StackType Stack1,int plithos,int plithos1)
{       printf("Items in the box\n");
        printf("plithos sto stack:%d\n",plithos);
        TraverseStack(Stack);
        printf("Items out of the box\n");
        printf("plithos sto stack:%d\n",plithos1);
        TraverseStack(Stack1);
}

void TraverseStack(StackType Stack)
{
    int i;

    for(i=0;i<=Stack.Top;i++)
    {
        printf("%c,%d",Stack.Element[i].Size,Stack.Element[i].price);
        printf("\n");
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


