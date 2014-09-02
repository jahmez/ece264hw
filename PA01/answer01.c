#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
    int summation = 0;
    int i = 0;
    for(i = 0; i < len; ++i){
	summation = summation + array[i];
	}
    return (summation);
}

int arrayCountNegative(int * array, int len)
{
    int negcount = 0;
    int i = 0; 
    for(i = 0; i < len; ++i){
	if(array[i] < 0){
	    ++negcount;
	}
    } 
    return (negcount);
}

int arrayIsIncreasing(int * array, int len)
{    
    int isincrease = 1;    
    int i = 0;

    for(i = 0; i < (len - 1); ++i){
	if(array[i+1] < array[i]){
	    isincrease = 0;
	}
    }    

    if(len == 0){
	isincrease = 1;
    }
 	        
    return (isincrease);
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
    int position = -1;
    int i = 0;

    for(i = 0; i < len; ++i){
	if(haystack[i] == needle){
	    position = i;
	}
    }

    return (position);
}

int arrayFindSmallest(int * array, int len)
{
    int smallest = array[0];
    int i = 0;
    int smallpos = 0;

    for(i = 0; i < len; ++i){
	if(array[i] < smallest){
	    smallest = array[i];
	}
    }

    for(i = (len-1); i >= 0; --i){
	if(array[i] == smallest){
	   smallpos = i;
	}
    }

    return (smallpos);
}
