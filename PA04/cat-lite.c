#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define TRUE 1
# define FALSE 0
void helpmsg(){
	//Prints help message as specified
	printf("\nUsage: cat-lite [--help] [FILE]...");
	printf("\nWith no FILE, or when FILE is -, read standard input.");
	printf("\n\nExamples:");
	printf("\n  cat-lite README   Print the file README to standard output.");
	printf("\n  cat-lite f - g    Print f's contents, then standard input,");
	printf("\n                    then g's contents.");
	printf("\n  cat-lite          Copy standard input to standard output.\n");
}

int cat(const char * filename, FILE * output)
{
	int ch;
	FILE * file;//Initialize file pointer
	//check for hypen
	int check=(strcmp(filename,"-")==0);
	if(check){
	    file=stdin;
	}
	else{
	    file=fopen(filename, "r");//set file pointer to read
	}
	if(file==NULL){
		return 0;
	}

	//Prints out characters in file until end is reached
	while((ch=fgetc(file)) != EOF){
		fputc(ch,output);
	}

	if(!check){
	    fclose(file);//close file pointer
	}
	return 1;
}


int main(int argc, char * * argv)
{

    int ind = 0;
    //Prints out file
    if(argc==1){
	cat("-", stdout);
	return EXIT_SUCCESS;
    }
    
    //Prints help message in helpmsg
    for(ind=1 ; ind < argc; ind++){
	if(strcmp(argv[ind], "--help")==0)
	{
	    helpmsg();
	    return EXIT_SUCCESS;
	}
    }

    //Prints error message
    for(ind=1 ; ind < argc; ind++) {
 	
	if(cat(argv[ind],stdout)==0){
	    fprintf(stderr,"File %s could not be retrieved\n", argv[ind]);
	    return EXIT_FAILURE;
	}  
    	
    }
    

    
    return EXIT_SUCCESS;
}

