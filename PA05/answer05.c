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
            printf(" + ");//Prints plus sign for all but first integer
        }
        printf("%d", arr[ind]);//Prints integer value
    }
    
    printf("\n");
}	

void partitionAllHelper(int val, int *arr, int pos)
{
    if(val == 0)//Base case
    {
        printPart(arr,pos);
        return;
    }

    int ind;
    //Branches through integers starting with 1
    for(ind = 1; ind <= val; ind++)
    {

        arr[pos] = ind ;
        partitionAllHelper(val - ind, arr, pos + 1);//Recursion case
    }
}

void partitionAll(int val)
{
    int *partArray = malloc( sizeof(int) * val);//Array to store partition
    partitionAllHelper(val,partArray,0);
    free(partArray);
}

void partitionIncHelper(int n, int *arr, int pos)
{
    if(n == 0)
    {
        printPart(arr, pos);//Base case
        return;
    }

    int first;
    int start;
    
    if(pos == 0)
    {
        start= 1;
    }
    
    else(start = arr[pos-1]+1);
    for(first = start; first <= n; first++)
    {
        arr[pos] = first;
        partitionIncHelper(n - first,arr,pos+1);
    }
}

void partitionIncreasing(int val)
{
    int *partArray = malloc (sizeof(int) * val);
    partitionIncHelper(val,partArray,0);
    free(partArray);
}

void partitionDecHelper(int n, int *arr, int pos)
{
    if(n == 0)
    {
        printPart(arr,pos);
        return;
    }
    int first;
    for(first = 1; first <= n; first++)
    {
        arr[pos] = first;
        if(pos)
        {
            if(arr[pos-1]<=arr[pos])
            {
                return;
            }
        }
        partitionDecHelper(n - first,arr,pos+1);
    }
}

void partitionDecreasing(int val)
{
    int *printArray = malloc ( sizeof(int) * val);
    partitionDecHelper(val, printArray , 0);
    free(printArray);
}

void partitionOddHelper(int n, int *arr, int pos)
{
    if(n == 0)
    {
        printPart(arr,pos);
        return;
    }
    int first;
    for(first = 1; first <= n; first+=2)
    {
        arr[pos] = first;
        partitionOddHelper(n - first,arr,pos+1);
    }
}

void partitionOdd(int val)
{
    int *partArray = malloc ( sizeof(int) *  val);
    partitionOddHelper(val,partArray,0);
    free(partArray);
}

void partitionEvenHelper(int n, int *arr, int pos)
{
    if(n == 0)
    {
        printPart(arr,pos);
        return;
    }
    int first;
    for(first = 2; first <= n; first+=2)
    {
        arr[pos] = first;
        partitionEvenHelper(n - first,arr,pos+1);
    }
}


void partitionEven(int val)
{
    int *partArray = malloc ( sizeof(int)  * val) ;
    
    partitionEvenHelper(val ,partArray, 0);
    
	free(partArray);
}

void partitionOddAndEvenHelper(int n, int *arr, int pos)
{
    if(n == 0)
    {
        printPart(arr,pos);
        return;
    }
    int first;
    for(first = 1; first <= n; first++)
    {
        int pass = 1;
        if(pos == 0)
        {
            pass = 1;
        }
        else
        {
            pass = (arr[pos-1] % 2) != (first % 2);
        }
        if(pass == 1)
        {
            arr[pos] = first;
            partitionOddAndEvenHelper(n - first,arr,pos+1);
        }
    }
}

void partitionOddAndEven(int val)
{
    int *partArray = malloc (sizeof(int) * val);
    partitionOddAndEvenHelper(val,partArray,0);
    free(partArray);
}


int checkPrime(int n)
{
    if(n<=1)
    {
        return 0;
    }
    if(n == 2)
    {
        return 1;
    }
    int ind;
    for(ind=2;ind<=n/2;ind++)
    {
        if(n%ind == 0)
        {
            return 0;
        }
    }
    return 1;
}

void partitionPrimeHelper(int n, int *arr, int pos)
{
    if(n == 0)
    {
        printPart(arr,pos);
        return;
    }
    int first;

    for(first = 1; first <= n; first++)
    {
        arr[pos] = first;
        if(checkPrime(arr[pos]))
        {
            partitionPrimeHelper(n-first,arr,pos+1);
        }
    }
}

void partitionPrime(int val)
{
    int *partArr = malloc (sizeof(int) * val);
    
    partitionPrimeHelper(val, partArr,  0);
    
    free(partArr);
}

