/* Simulate a tree solution as a solution of array to approach Knuth's problem   */

/*Specifically we simualate a tree as an array,tree's size as array's size , tree's nodes as array's positions and
relation of parent-left-child in tree prototype as array[i]-array[2*i+1]-array[2*i+2] respectively in array prototype*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define N 131071 //The size of the array that simulate tree's size which is 2 ^ 17-1 .Search area is to 2^16 because the one more level is for termination conditon.
void print(double array[],int lim);//Print an array of numbers
double factorial(double number); //Return factorial of a number
void checkForNormalNum(double number,double array[],int i);//Check for normal numbers to add in an array .Not accepted NaN, inf or undefined types
int sumOfClearNodes(double array[]);//How many positions of an array have numbers and not -1 which similate NULL of a tree .
void Inorder(double array[],int start, double check[],int *a,double numForCheck,int *min,int lim);/*Recursive approach of Deapth First(Inorder) Search where traversal
                                                                                        is first to the Left subtree- after to the Root- finally to the Right subtree*/
int existPos(double check[],int lim);//Find the next free position to the back-up array
void minPos(int *a,int * previous);/*Find the min position where in an Inorder Traversal is the number we are searching for because
                                    the array may have in multiple positions the same number*/
void initializeInt(double array[],int lim);//Initialize an int array
bool checkIfNumInt(double *value);//Check if a number is int or not
bool isEvenNumber(int *i);//Check if a number is Even Number
void initializeString(char *arr[],int lim);//Initialize String array
void findFather(int *i);/*Find the father position of an other position of an array in the prototype of tree simulation which is
i->Root,2*i+1->Left Child,2*i+2->Right Child*/
double findPowerExponent(double base ,double power);// Find the exponent of a power whith number 2 as base .We find the "tree's" whole levels.
 double sumOfFilledPosRouteArr(char *saveRoute[],double lim );//Find the next free position to the route array
 void printRoute(char *saveRoute[],double lim);//Print Route
  void LevelOrder(double array[],int start, double check[],int *a,double numForCheck,int *min,int level,int lim);/*Recursive approach of Breadth First Search
                                                                                                                  where traversal is to level to level node */
int main()
{
  /*Declare ande initialize all the variables and the arrays which we will use*/
  double array[N],numForcheck,sumRoutePos,sumFillRoutePos,treeHeight;
  int i,lim;
  int a=0,min=N+2,j=0,level;
  char search;
  initializeInt(array,N);
  /*We fill the whole array to the 2*i+1 position with root of the value of i position /And/ to the 2*i+2 position with floor of the value of i position
  if this is floating number OR with factorial of the value of i position if this is integer. Before we do that we check if the nunber is type inf , NaN or undefined.
  */
  array[0]=4;
   for(i=0;i<N/4;i++)
  {


      checkForNormalNum( sqrt(array[i]),array,2*i+1);

      if(checkIfNumInt(&array[i]))
      {
          checkForNormalNum( factorial(array[i]),array,2*i+2);
      }
      else
      {
          checkForNormalNum( floor(array[i]),array,2*i+2);
      }
  }
  for(i=N/4;i<N/2;i++)
  {
      array[2*i+1]=-1;
      array[2*i+2]=-1;
  }

/*We create a back up array where we will store values of the main array which are numbers integer or floating and not -1 which represents values
 which is not normal numbers*/
     lim=sumOfClearNodes(array);
     double check[lim];
    initializeInt(check,lim);
/* Ask from user choose the type of search and the number */

     do
     {
          printf("Enter 'D' for Depth First Search or 'B' for Breadth First Search (upper or lower letter):\n");
          scanf("%c",&search);
     }while(toupper(search)!='D'&&toupper(search)!='B');

     printf("Enter number for check:");
     scanf("%lf",&numForcheck);
     treeHeight=findPowerExponent(2,N+1);
     //printf("%.2lf",treeHeight);

     //We run the function or for deapth first search or for breadth fisrt search
     if(toupper(search)=='D')
     {
         Inorder(array,0,check,&a,numForcheck,&min,lim);
     }
     else if(toupper(search)=='B')
     {
           for(level=0;level<(int)treeHeight;level++)
       {
         LevelOrder(array,0,check,&a,numForcheck,&min,level,lim);
       }
     }

/*If we dont find what we are searching for ,we print a message and if we find it we return to the
 opposite route until the start and we store in an array all the numeric operations of this route. When store finish
  we print these elements from the end to the start of the array to represent the numeric operations of normal route from the start to the end*/

     if(min!=N+2)
       {

         sumRoutePos=findPowerExponent(2,N/2+1);
         char *saveRoute[(int)sumRoutePos];
         initializeString(saveRoute,sumRoutePos);
         if(min==0)
         {
            printf("4(start)");
         }
         else
         {
         while(min!=0)
         {


         if(isEvenNumber(&min))
         {
             findFather(&min);
             if(checkIfNumInt(&array[(int)min]))
             {
                 saveRoute[j]="factorial()";
             }
             else
             {
                 saveRoute[j]="floor()";
             }

         }
         else
         {
              saveRoute[j]="root()";
              findFather(&min);


         }
         j++;
           //printf("%d\n",min);
         }
      sumFillRoutePos=sumOfFilledPosRouteArr(saveRoute, sumRoutePos);
       printRoute(saveRoute,sumFillRoutePos);
       }
     }
     else
     {
         printf("Didn't find\n");
     }






}

//-----------------------------------------------------------------FUNCTIONS    FUNCTIONS     FUNCTIONS-----------------------------------------------------------------
 void print(double array[],int lim)
 {
     int i;
     for(i=0;i<lim;i++)
     {
         printf("%.3lf\n",array[i]);
     }
 }


 double factorial(double number)
 {
     double fact=1,i;
     if(number<0)
     {
         fact=-1;
     }
     else if(number>0)
     {
         if(number<171)//One more check because of unpredictable returns ...max factorial with type double sw(171)
        {
         for(i=1;i<=number;i++)
         {
             fact*=i;
         }
        }
        else
        {
            fact=-1;
        }
     }
     return fact;
 }


  void checkForNormalNum(double number,double array[],int i)
 {

  switch (fpclassify(number)) {
    case FP_INFINITE:   array[i]=-1; break;
    case FP_NAN:       array[i]=-1;       break;
    case FP_ZERO:      array[i]=-1;    break;
    case FP_SUBNORMAL: array[i]=-1; break;
    case FP_NORMAL:    array[i]=number ;   break;

 }
 }


int sumOfClearNodes(double array[])
{
    int sum=0,i;
    for(i=0;i<N;i++)
    {
        if(array[i]!=-1)
        {
            sum+=1;
        }
    }
    return sum;
}


void Inorder(double array[],int start, double check[],int *a,double numForCheck,int *min,int lim)
{
    int pos;
    if(array[start]==-1) return;
    Inorder(array,2*start+1,check,a,numForCheck,min,lim);
    pos=existPos(check,lim);
    check[pos]=array[start];
    if(check[pos]==numForCheck)
    {
        *a=start;
        minPos(a,min);
    }
    Inorder(array,2*start+2,check,a,numForCheck,min,lim);
}


int existPos(double check[],int lim)
{   int i, sum=0;
    for(i=0;i<lim;i++)
    {
        if(check[i]!=0)
        {
            sum+=1;
        }
    }
    return sum;
}


void minPos(int *a,int * previous)
{
        if(*a<*previous)
        {
            *previous=*a;
        }
}


void initializeInt(double array[],int lim)
{
    int i;
    for(i=0;i<lim;i++)
    {
        array[i]=0;
    }
}


 bool checkIfNumInt(double *value)
 {
     double floatpart,intpart;
     bool check=false;
     floatpart=modf(*value,&intpart);
     if(floatpart==0)
     {
         check=true;
     }
     return check;
 }


 bool isEvenNumber(int *i)
 {   bool check=false;
     if(*i%2==0)
     {
         check=true;
     }
     return check;
 }


 void findFather(int *i)
 {
     if(isEvenNumber(i))
     {
         *i=*i/2-1;
     }
     else
     {
         *i=*i/2;
     }

 }


 void initializeString(char *arr[],int lim)
 {
     int i;
     for(i=0;i<lim;i++)
     {
         arr[i]="empty";
     }

 }


 double findPowerExponent(double base ,double power)
 {
     double result=log(power) / log(base);
     return result;
 }


 double sumOfFilledPosRouteArr(char *saveRoute[],double lim )
 {
     double i,sum=0;
     for(i=0;i<lim;i++)
     {
         if(saveRoute[(int)i]!="empty")
         {
             sum+=1;
         }
     }
     return sum;
 }


 void printRoute(char *saveRoute[],double lim)
 {
      double i;
      for(i=lim-1;i>=0;i--)
      {
          printf("%s\n",saveRoute[(int)i]);
      }
 }


 void LevelOrder(double array[],int start, double check[],int *a,double numForCheck,int *min,int level,int lim)
 {
     int pos;
     if(array[start]==-1) return;
     if(level==0)
     {
    pos=existPos(check,lim);
    check[pos]=array[start];
    if(check[pos]==numForCheck)
    {
        *a=start;
        minPos(a,min);
    }

     }
     else if(level>0)
     {
         LevelOrder(array,2*start+1,check,a,numForCheck,min,level-1,lim);
         LevelOrder(array,2*start+2,check,a,numForCheck,min,level-1,lim);
     }
 }
