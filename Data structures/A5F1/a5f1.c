#include <stdio.h>
#include <stdlib.h>
#define megisto_plithos 1001
typedef enum
{
    FALSE,TRUE
}boolean;
typedef  boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;
void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void createFibonacciSet(int threshold,typos_synolou synolo);
boolean isFibonacci(int n, typos_synolou synolo);
void displayFibonacci(typos_synolou synolo);
int main()
{
    int max,n;
    typos_synolou Fibonacci;
    Dimiourgia(Fibonacci);
    do
    {
    printf("Dwse megistarithmo: ");
    scanf("%d",&max);
    }while(max<2||max>1000);
    createFibonacciSet(max,Fibonacci);
    displayFibonacci(Fibonacci);
    printf("Enter number to check: ");
    scanf("%d",&n);
    while(n!=-1)
    {
         if(isFibonacci(n,Fibonacci))
         {
             printf("Fibonacci!\n");
         }
         else
        {
            printf("Not Fibonacci\n");
        }
         printf("Enter number to check: ");
         scanf("%d",&n);
    }
}
void createFibonacciSet(int threshold,typos_synolou synolo)
{    int i=0,j=1;
     synolo[i]=TRUE;
     while(j<threshold)
     {
        synolo[j]=TRUE;
        i=j-i;
        j=j+i;
     }
}
boolean isFibonacci(int n, typos_synolou synolo)
{
        return Melos(n,synolo);
}
void displayFibonacci(typos_synolou synolo)
{
    int i;
    for(i=0;i<megisto_plithos;i++)
    {
        if(Melos(i,synolo))
        {
            printf("%d ",i);
        }
    }
    printf("\n");
}
void Dimiourgia(typos_synolou synolo)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    synolo[stoixeio] = TRUE;
}
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    return synolo[stoixeio];
}
