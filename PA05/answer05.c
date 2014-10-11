//James Adam Harned

#include <stdio.h>
#include <stdlib.h>

void printPart(int *arr, int len)
{
    //Increments through parition printing each interger
    int ind;
    
    printf("= ");
    
    for(ind = 0; ind < len; ind++)
    {
        if(ind != 0)
        {
            printf(" + ");//Prints plus sign for all but counter integer
        }
        printf("%d", arr[ind]);//Prints integer value
    }
    
    printf("\n");
}	

void partitionAllInit(int val, int *arr, int pos)
{
    if(val == 0)//Base case
    {
        printPart(arr,pos);//Prints out integer array

        return;//Base case
    }

    int ind;
    //Branches through integers starting with 1
    for(ind = 1; ind <= val; ind++)
    {

        arr[ pos] = ind ;
        partitionAllInit(val - ind, arr, pos + 1);//Recursion case
    }
}

void partitionAll( int val)
{
    int *partArray = malloc( sizeof(int) * val);//Array to store partition
    partitionAllInit(val ,partArray ,0);//Recursion process in seperate func
    
   free(partArray);
}

void  partitionIncInit(int ind, int * array, int pos)
{
    if( ind   == 0)
    {
        printPart(array, pos);//Base case
        
        return;
    }

    int counter;

    int start;
    
    if(pos == 0)
    {
        start= 1;
    }
    //Recursive case
    else(start = array[pos-1]+1);
    for(counter = start; counter <= ind ; counter++)
    {
        array[pos] = counter;
        partitionIncInit(ind -  counter, array,pos + 1);
    }
}

void partitionIncreasing(int val)
{
    int *partArray = malloc (sizeof(int) * val);
    
     partitionIncInit(val,partArray,0);
    
    free(partArray);
}

void partitionDecInit(int ind, int *arr, int pos)
{
    if(ind  == 0)
    {
        printPart(arr,pos);
        return;
    }
    int counter;
    for(counter = 1; counter <= ind; counter++)
    {
        arr[pos] = counter;
        if(pos)
        {
            if(arr[pos-1]<=arr[pos])
            {
                return;
            }
        }
        partitionDecInit(ind - counter,arr,pos+1);
    }
}

void partitionDecreasing(int val)
{
    int *printArray = malloc ( sizeof(int) * val);
    partitionDecInit(val, printArray , 0);
    free(printArray);
}

void partitionOddInit(int ind, int *arr, int pos)
{
    if(ind  == 0)
    {
        printPart(arr,pos);
        return;
    }
    int counter;
    for(counter = 1; counter <= ind ; counter+=2)
    {
        arr[pos] = counter;
        partitionOddInit(ind  - counter,arr,pos+1);
    }
}

void partitionOdd(int val)
{
    int *partArray = malloc ( sizeof(int) *  val);
    partitionOddInit(val,partArray,0);
    free(partArray);
}

void partitionEvenInit(int ind, int *arr, int pos)
{
    if(ind == 0)
    {
        printPart(arr,pos);
        return;
    }
    int counter;
    for(counter = 2 ;  counter <= ind; counter+=2 )
    {
        arr[pos] = counter;
        partitionEvenInit(ind - counter, arr, pos+1);
    }
}


void partitionEven(int val)
{
    int *partArray = malloc ( sizeof(int)  * val) ;
    
    partitionEvenInit(val ,partArray, 0);
    
	free(partArray);
}

void partitionOddAndEvenInit(int ind, int *arr, int pos)
{
    if(ind  == 0)
    {
        printPart(arr,pos);
        
        return;
    }
    

    int counter;
    for(counter = 1; counter <= ind; counter++)
    {
        int pass = 1;
        if(pos == 0)
        {
            pass = 1;
        }
        else
        {
            pass = (arr[pos-1] % 2) != (counter % 2);
        }
        if(pass == 1)
        {
            arr[pos] = counter;
            partitionOddAndEvenInit(ind - counter,arr,pos+1);
        }
    }
}

void partitionOddAndEven(int val)
{
    int *partArray = malloc (sizeof(int) * val);
    partitionOddAndEvenInit(val,partArray,0);
    free(partArray);
}

//Checks if prime number, return 1 if so, otherwise 0
int checkPrime( int ind)
{

    //Cases for 1 and 0
    if(ind<=1)
    {
        return 0;
    }
    
    if(ind == 2)
    {
        return 1;
    }


    int primeinc;

    //Testing for divisibility
    for(primeinc=2; primeinc <= (ind/2); primeinc++)
    {

        if((ind%primeinc) == 0)
        {
            return 0;
        }
   }


    return 1;
}



void partitionPrimeInit(int ind, int *arr, int pos)
{
    if(ind == 0)
    {
        printPart(arr,pos);
        return;
    }
    int counter;

    for(counter = 1; counter <= ind; counter++)
    {
        arr[pos] = counter;
        if(checkPrime(arr[pos]))
        {
            partitionPrimeInit( ind - counter, arr, pos+1);
        }
    }
}

void partitionPrime(int val)
{
    int *partArr = malloc (sizeof(int) * val);
    
    partitionPrimeInit(val, partArr,  0);
    
    free(partArr);
}

