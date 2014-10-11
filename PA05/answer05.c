//James Adam Harned

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
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
    //Branches through integers beginning with 1
    for(ind = 1; ind <= val; ind++){

        arr[ pos] =  ind ;
        partitionAllInit(val - ind, arr, pos + 1);//Recursion case
    }
}

//Each partition case split between memory allocation and recursion functions
void partitionAll( int val)
{
    int *partArray = malloc( sizeof(int) * val);//Array to store partition
    partitionAllInit(val ,partArray ,0);//Recursion process in seperate func
    
   free(partArray);//Free allocated memory
}

void  partitionIncInit(int ind, int * array, int pos)
{
    if(ind   == 0)
    {
        printPart( array, pos);//Base case
        
        return;
    }

    int counter;

    int bound;
    
    if(pos == 0)
    {
        bound= 1;
    }
    else(bound = array[pos-1] + 1);
    

    for(counter = bound; counter <= ind ; counter++)
    {
//Recursive case
        array[pos] = counter;
        partitionIncInit(ind -  counter, array,pos + 1);
    }
}

void partitionIncreasing(int val)
{
    int *partArray = malloc (sizeof(int) * val);
    
     partitionIncInit(val, partArray, 0);
    
    free(partArray);
}

void partitionDecInit(int ind, int * array, int pos)
{


    if(ind  == 0)
    {
	//Base case
        printPart(array,pos);
        return;
    }

    int counter;
    for(counter = 1; counter <= ind; counter++)
    {
        array[pos] = counter;
        
	if(pos != 0)
        {

            if(array[pos-1] <= array[pos])//Test for decreasing
            {
                return;//Exits current recursion if not decreasing
            }
        }

        partitionDecInit(ind - counter, array, pos + 1);//Recursion
    }
}

void partitionDecreasing( int val )
{
    int *printArray =  malloc ( sizeof(int) * val);
    partitionDecInit(val, printArray , 0);
    
    free(printArray);
}

void partitionOddInit(int ind, int * array, int pos)
{

//Base case
    if(ind  == 0)
    {
        printPart(array, pos);
        return;
    }

//Recursive case
    int counter;
    for(counter= 1; counter <= ind ; counter+=2)//Increments through odd ints
    {
        array[pos] = counter;

        partitionOddInit(ind  - counter, array, pos+1);//Branches
    }
}

void partitionOdd(int val)
{//same
    int *partArray = malloc ( sizeof(int) *  val);
    
    partitionOddInit(val, partArray, 0);
    
    free(partArray);
}

void  partitionEvenInit(int ind, int * array, int pos)
{//same as odd, just begins the counter at 02
    if(ind == 0)
    {
        printPart(array,pos);//base
        return;
    }

    int counter;
    
	//kwill branch through all even nums less than ind
    for(counter = 2 ;  counter <= ind; counter+=2 )
    {
        array[pos] = counter;

        partitionEvenInit(ind - counter, array, pos+1);//recursion here
    }
}


void partitionEven(int val)
{

    int *partArray = malloc ( sizeof(int)  * val) ;
    
    partitionEvenInit(val ,partArray, 0);
    
	free(partArray);
}

void partitionOddAndEvenInit(int ind, int *array, int pos)
{
    if(ind  == 0)
    {
        printPart(array,pos);
        //BAse case   
        return;
    }
    

    int counter;//Recursion case
    for(counter = 1; counter <= ind; counter++)
    {

        int test = TRUE;
        
        if(pos != 0)
        {
            test = (array[pos - 1] % 2) != (counter % 2);//determine if test is passed
        }

        if(test == TRUE)
        {
            array[pos] = counter;
            partitionOddAndEvenInit(ind - counter, array, pos+1);
        }
    }

}

void partitionOddAndEven(int val)
{
    int *partArray = malloc (sizeof(int) * val);
    
    partitionOddAndEvenInit(val, partArray, 0);
    
    free(partArray);
}

//Checks if prime number, return 1 if so, otherwise 0
int  checkPrime( int  ind)
{

    //Cases for 1 and 0
    if(ind <= 1)
    {
        return  FALSE;
    }
    
    //special case of 2
    if(ind == 2)
    {

        return TRUE;
    }


    int primeinc;//counter

    //Testing for divisibility
    for(primeinc=2; primeinc <= (ind/2); primeinc++)
    {

        if( (ind % primeinc) == 0)
        {
            return FALSE;
        }
   }


    return TRUE;
}



void partitionPrimeInit(int ind, int * array, int pos)
{
    if(ind == 0)
    {
        printPart(array,pos);
        //Base case
	return;
    }
    int  counter;

    for(counter = 1; counter <= ind; counter++)
    {

        array[pos]= counter;
        
	if(checkPrime(array[pos]))//Recursion if integer is prime
        {
	    //Recursive case
            partitionPrimeInit( ind - counter, array, pos + 1);//Branches through
        }
    }
}

void partitionPrime(int val)
{
    int *partArr = malloc (sizeof(int) * val);
    
    partitionPrimeInit(val, partArr,  0);
    
    free(partArr);
}

//int main()
//{   //Useless main func to avoid error
//    return 0;
//}
