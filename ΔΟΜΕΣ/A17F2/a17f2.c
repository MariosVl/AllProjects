#include <stdio.h>
#include <stdlib.h>
#define StackLimit 50
#define plithos 20

typedef enum
{
    FALSE,TRUE
}boolean;

typedef int StackElementType;

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
StackType CopyStack(StackType *Stack);
void Traverse(StackType Stack);

int main()
{
    StackType s1, s2;
    int i;

    CreateStack(&s1);
    CreateStack(&s2);

    for(i=0;i<plithos;i++)
    {
        Push(&s1,i);
    }

    printf("Stack s1\n");
    printf("plithos sto stack : %d\n",plithos);
    Traverse(s1);

    s2=CopyStack(&s1);

    printf("After copy s1 to s2 \n");

    printf("Stack s1\n");
    printf("plithos sto stack : %d\n",plithos);
    Traverse(s1);

    printf("Stack s2\n");
    printf("plithos sto stack : %d\n",plithos);
    Traverse(s2);

}
StackType CopyStack(StackType *Stack)
{
    int i,item;
    StackType Stack1,Stack2;
    CreateStack(&Stack1);
    CreateStack(&Stack2);
    while(Stack->Top>=0)
    {
        Pop(Stack,&item);
        Push(&Stack1,item);

    }
    while(Stack1.Top>=0)
    {
        Pop(&Stack1,&item);
        Push(Stack,item);
        Push(&Stack2,item);

    }
    return Stack2;

}
void Traverse(StackType Stack)
{
    int i;
    for(i=0;i<=Stack.Top;i++)
    {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
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
