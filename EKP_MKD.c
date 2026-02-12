/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
void isFirst(int arrayFirst[],int i);
void insertValues (int array[],int i);
void print(int array[],int len);
int findMax(int array[],int len);
int findRealSize(int array[],int k);
void initializeUnKnownRealSizeArr(int array[],int i);
void findEKP_MKD(int array[],int arrayFirst[],int i,int realSize);
bool checkEndEKP(int array[],int i);
int main()
{
    int i,k,realSize;
    printf("Give array positions\n");
    scanf("%d",&i);
    while(i<=1)
    {
        printf("Wrong number! Please fill 2 or more positions:");
        scanf("%d",&i);
    }
    int array[i];
    initializeUnKnownRealSizeArr(array,i);
    insertValues(array,i);
    k=findMax(array,i);
    int arrayFirst[k];
    initializeUnKnownRealSizeArr(arrayFirst,k);
    isFirst(arrayFirst,k);
    realSize=findRealSize(arrayFirst,k);
    findEKP_MKD(array,arrayFirst,i,realSize);
    
   
    
    
   
}

void isFirst(int arrayFirst[],int i)
{
    int k,count=-1;
    
    for(k=2;k<=i;k++)
    {
        bool a=true;
        int j=2;
        while (j<k && a)
        {  
            if((k%j)==0)
            {
                
                a=false;
            }
            j++;
        }
        if (a)
        {
            count++;
            arrayFirst[count]=k;
        }
    }
    
        
 }
 
 void insertValues (int array[],int i)
 {
    
            int j,a;
            for(j=0;j<i;j++)
            { 
               printf("Give number:");
               scanf("%d",&a);
                while(a<=0)
                {
               printf("Wrong number try again:");
               scanf("%d",&a);
                }
               array[j]=a;
               
               
            }
 }
 
 void print(int array[],int len)
 {
     int i;
     for(i=0;i<len;i++)
     {
         printf("%d,",array[i]);
     }
     printf("\n");
 }
 
 int findMax(int array[],int len)
 {
     int max=array[0],i;
     
     for(i=1;i<len;i++)
     {
        if(array[i]>=max)
        {
            max=array[i];
        }
     }
     return max;
 }
 
 int findRealSize (int array[],int k)
 {
     int i=0,count=0;
     while(array[i]!=-1 && i<k)
     {
         count++;
         i++;
     }
     return count;
     
 }
 void initializeUnKnownRealSizeArr(int array[],int i)
 {
            int j;
            for(j=0;j<i;j++)
            {
               array[j]=-1;
            }
 }
 
void findEKP_MKD(int array[],int arrayFirst[],int i,int realSize)
 {
      int start,startFirst,count,EKP,MKD;
      start=startFirst=count=0;
      EKP=MKD=1;
      bool sign=true;
   while(start<i && startFirst<realSize && sign)
   {   
       if(array[start]%arrayFirst[startFirst]==0)
       {
           array[start]=array[start]/arrayFirst[startFirst];
           count++;
       }
       
       if(start+1<i)
       {
       start++;
       }
       
       else
       {
           start=0;
           if(count>0)
           {
               EKP=EKP*arrayFirst[startFirst];
               if(count==i)
               {
                   MKD=MKD*arrayFirst[startFirst];
               }
              
           }
           else
           {
                startFirst++;
           }
           
           count=0;
           
           if(checkEndEKP(array,i))
           {
               sign=false;
           }
           
       }
       
       
   }
   printf("Ελαχιστο Κοινό Πολλαπλάσιο: %d\n",EKP);
   
   printf("Μέγιστος Κοινός Διαιρέτης : %d ",MKD);
     
    
     
 }
 
 bool checkEndEKP(int array[],int i)
 {
           bool ret=true;
           int m;
           for(m=0;m<=i-1;m++)
           {
               if(array[m]!=1)
               {
                   ret=false;
                   break;
               }
           }
          
           return ret;
 }
