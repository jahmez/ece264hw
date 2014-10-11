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

    for(ind = 1; ind <= val; ind++)
    {
        arr[pos] = ind;
        partitionAllHelper(val - ind, arr, pos+1);//Recursion case
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
        printPart(arr,pos);
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

void partitionIncreasing(int value)
{
    int *arr = malloc (sizeof(int) * value);
    partitionIncHelper(value,arr,0);
    free(arr);
}

//PARTITION DECREASING INTEGERS//
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

void partitionDecreasing(int value)
{
    int *arr = malloc (sizeof(int) * value);
    partitionDecHelper(value,arr,0);
    free(arr);
}

// PARTITION ODD INTEGERS//
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

void partitionOdd(int value)
{
    int *arr = malloc (sizeof(int) * value);
    partitionOddHelper(value,arr,0);
    free(arr);
}

// PARTITION EVEN INTEGERS//
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

void partitionEven(int value)
{
    int *arr = malloc (sizeof(int) * value);
    partitionEvenHelper(value,arr,0);
    free(arr);
}

// PARTITION EVEN INTEGERS//
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

void partitionOddAndEven(int value)
{
    int *arr = malloc (sizeof(int) * value);
    partitionOddAndEvenHelper(value,arr,0);
    free(arr);
}

//PARTITION PRIME NUMBERS//

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

void partitionPrime(int value)
{
    int *arr = malloc (sizeof(int) * value);
    partitionPrimeHelper(value,arr,0);
    free(arr);
}

