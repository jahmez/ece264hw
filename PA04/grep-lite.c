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
	int found = FALSE;
	//Command Option Cases
	int help = FALSE;
	int quiet = FALSE;
	int invertcase = FALSE;
	int printlines = FALSE;

	for(ind = 1; ind < argc-1; ind++)
	{   
	    //Go through and check for cases(based on example.c)
	    if(!strcmp(argv[ind],"--help")) help=TRUE;//Help case

	    else if((!strcmp(argv[ind],"-v") || !strcmp(argv[ind],"--invert-match"))) invertcase=TRUE;//Inversion case
	    
	    else if((!strcmp(argv[ind],"-n") || !strcmp(argv[ind],"--line-number"))) printlines=TRUE;//Print lines case
	    
	    else if((!strcmp(argv[ind],"-q") || !strcmp(argv[ind],"--quiet"))) quiet=TRUE;//Quieted case
	    
	    else
	    {
		//Print error message
		fprintf(stderr,"ERROR MESSAGE HERE");
	    	return(2);
	    }
	}

	const char * entered = argv[argc-1];

	int linenum=0;

	if(argc==1)
	{
	    //Print error message
	    fprintf(stderr,"AN ERROR HAS OCCURED\n");
	    return(2);
	}
	
	//Test for help case
	if(help || strcmp(entered,"--help")==0)
	{
	    helpmsg();
	    return EXIT_SUCCESS;
	}

	
	int matching=0;

	char buffer[2000];
	

	while(fgets(buffer,2000,stdin)!=NULL){
	    linenum++;
	    
	    matching=(strstr(buffer,entered)!=NULL);//Test for a match
	    
	    if((matching && !invertcase) || (!matching && invertcase))//found if matching or not matching with inversion
	    {
		found=TRUE;
		
		if(!quiet)
		{
		   if(printlines){
			printf("%d: ",linenum);//Print out line number if case selected
		   }
		printf("%s ", buffer);//prints to console
		}
	    }
	}
	if(found) return 0;
	else return 1;
}
