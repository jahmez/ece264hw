#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * * argv)
{
    int ind;
	
    //Based on code from example.c
    for(ind = 1; ind < argc; ind++) {
	printf("%s",argv[ind]);
	if(ind != (argc-1)){
	    printf(" ");
	}
    }
    printf("\n");

    return EXIT_SUCCESS;
}

