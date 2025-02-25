#include <stdio.h>
#include <stdlib.h>
#define StackLimit 50

typedef enum
{
    FALSE,TRUE
}boolean;

typedef char StackElementType;

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
boolean Alfanumeric_Inversion(StackType *Stack,char ch);

int main()
{
  StackType Stack;
  char ch;
  CreateStack(&Stack);

  scanf("%c",&ch);
  getchar();

  if(Alfanumeric_Inversion(&Stack,ch))
  {
      printf("TRUE");
  }

  else
  {
      printf("FALSE");
  }

}

boolean Alfanumeric_Inversion(StackType *Stack,char ch)
{
    char item,previous;
    boolean flag,key=TRUE;

    while(ch!='C'&&key==TRUE)
    {
        if(ch=='#')
        {
            key=FALSE;
        }
        else
        {
            Push(Stack,ch);
            scanf("%c",&ch);
            getchar();
        }
    }

    if(ch=='#')
    {
        return FALSE;
    }
    else
    {

        do
        {

             scanf("%c",&ch);
             getchar();
             if(Stack->Top>=0)
             {
             Pop(Stack,&item);
             previous=ch;
             }


        }while(ch==item);

        if(Stack->Top==-1)
        {
            if(previous==item&&ch=='#')
            {
               flag=TRUE;
            }
            else
            {
                flag=FALSE;
            }
        }
        else
        {
            flag=FALSE;
        }

    }

        return flag;
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


