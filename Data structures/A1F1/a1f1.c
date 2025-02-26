#include <stdio.h>
#include <stdlib.h>
#define megisto_plithos 201
typedef enum
{
    FALSE, TRUE
}boolean;
typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;
void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void createPrimeSet(int first,int last,typos_synolou synolo);
boolean isPrime(int n);
void displaySet(int first,int last,typos_synolou synolo);
int main()
{
    int first,last;
    typos_synolou PRWTOI;
    do
   {
       printf("Dwse first:");
       scanf("%d",&first);

   }while(first<2||first>200);
   do
   {
       printf("Dwse last:");
       scanf("%d",&last);

   }while((last<2||last>200)||last<first);
   Dimiourgia(PRWTOI);
   createPrimeSet(first,last,PRWTOI);
   displaySet(first,last,PRWTOI);
}
void createPrimeSet(int first,int last,typos_synolou synolo)
{
    int i;
    for(i=first;i<=last;i++)
    {
        if(isPrime(i))
        {
            synolo[i]=TRUE;
        }
    }
}
boolean isPrime(int n)
{
    int i;
    boolean flag=TRUE;
    for(i=2;i<n;i++)
    {
        if(n%i==0&&n!=i)
        {
           flag=FALSE;
        }

    }
    return flag;
}
void displaySet(int first,int last,typos_synolou synolo)
{
    int i;
    for(i=first;i<=last;i++)
    {
        if(Melos(i,synolo))
        {
            printf("%d ",i);
        }
    }
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

