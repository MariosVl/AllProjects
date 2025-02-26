#include<stdio.h>
int main()
{
    int pin[20];
    int i,a;
    for(i=0;i<10;i++)
    {
        pin[i]=(i);

    }
    scanf("%d",&a);
    for(i=9;i>=a-1;i--)
    {
        pin[i+1]=pin[i];

    }
    pin[a-1]=456;
    for(i=0;i<11;i++)
    {
        printf("%d ",pin[i]);
    }
    printf("\n");
     scanf("%d",&a);
    for(i=a-1;i<11;i++)
    {
        pin[i]=pin[i+1];
    }
     for(i=0;i<10;i++)
    {
        printf("%d ",pin[i]);
    }

}
