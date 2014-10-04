#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void helpmsg(){
	printf("\nINSERT HELP MESSAGE");
}

int main(int argc, char * * argv)
{
	int ind;
	int help = FALSE;
	int invert = FALSE;
	int lines = FALSE;
	int quiet = FALSE;

	const char * pattern = argv[argc-1];

	for(ind = 1; ind < argc-1; ind++)
	{   
	    //Go through and check for commands
	    if(strcmp(argv[ind],"--help")) help=TRUE;
	    else if(strcmp(argv[ind],"-v") || strcmp(argv[ind],"--invert-match")) invert=TRUE;
	    else if(strcmp(argv[ind],"-n") || strcmp(argv[ind],"--line-number")) lines=TRUE;
	    else if(strcmp(argv[ind],"-q") || strcmp(argv[ind],"--quiet")) quiet=TRUE;
	    else
	    {
		fprintf(stderr,"ERROR MESSAGE HERE");
	    	return EXIT_FAILURE;
	    }
	}

	if(help || strcmp(pattern,"--help")==0)
	{
	    helpmsg();
	    return EXIT_SUCCESS;
	}
	if(argc==1)
	{
	    fprintf(stderr,"AN ERROR HAS OCCURED\n");
	    return EXIT_FAILURE;
	}

	char buffer[2048];
	int found=FALSE;
	int currLine=0;
	int matches=0;

	while(fgets(buffer,2048,stdin)!=NULL){
	    currLine++;
	    
		matches=(strstr(buffer,pattern)!=NULL);
	    if((matches && !invert) || (!matches && invert))
	    {
		found=TRUE;
		
		if(!quiet)
		{
		   if(lines) printf("%d: ",currLine);
		   printf("%s ", buffer);
		}
	    }
	}

	return found ? 0:1;
}
