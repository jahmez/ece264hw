#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ERROR_RET 2
#define MAX_BUFF 2048

int main(int argc, char * * argv)
{
	int ind;
	int showHelp = FALSE;
	int invertMatch = FALSE;
	int lineNumber = FALSE;
	int quiet = FALSE;
	const char * pattern = argv[argc-1];

	for(ind = 1; ind < argc-1; ind++)
	{
	    #define ARGCMP(C) (strcmp(argv[ind],C)==0)
	    if(ARGCMP("--help")) showHelp=TRUE;
	    else if(ARGCMP("-v") || ARGCMP("--invert-match")) invertMatch=TRUE;
	    else if(ARGCMP("-n") || ARGCMP("--line-number")) lineNumber=TRUE;
	    else if(ARGCMP("-q") || ARGCMP("--quiet")) quiet=TRUE;
	    else
	    {
		fprintf(stderr,"ERROR MESSAGE HERE");
	    	return ERROR_RET;
	    }
	    #undef ARGCMP
	}

	if(showHelp || strcmp(pattern,"--help")==0)
	{
	    printHelp();
	    return EXIT_SUCCESS;
	}
	if(argc==1)
	{
	    fprintf(stderr,"ERROR HAS OCCURED\n");
	    return ERROR_RET;
	}

	char buffer[MAX_BUFF];
	int found=FALSE;
	int currLine=0;
	int matches=0;

	while(fgets(buffer,MAX_BUFF,stdin)!=NULL){
	    currLine++;
	    matches=(strstr(buffer,pattern)!=NULL);
	    if((matches && !invertMatch) || (!matches && invertMatch))
	    {
		found=TRUE;
		if(!quiet)
		{
		   if(lineNumber) printf("%d: ",currLine);
		   printf("%s ", buffer);
		}
	    }
	}

	return found ? 0:1;
}

void printHelp(){
	printf("\n\nHELP MESSAGE");
}
