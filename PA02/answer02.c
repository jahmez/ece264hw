#include "answer02.h"

size_t my_strlen(const char * str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
    }
 
    return i;
}

int my_countchar(const char * str, char ch)
{
    int i =0;
    int charcount = 0;
    
    for(i = 0; str[i] != '\0'; i++)
    {
	if(str[i] == ch)
	{
	    charcount++;
	}
    }

    return charcount;
}

char * my_strchr(const char * str, int ch)
{
   int i = 0;
    int found = 0;
    int done = 0;
    int charpos = 0;

    for(i=0; done == 0; i++)
    {
	if(str[i]=='\0')
	{
	    done=1;
	    if(ch=='\0')
	    {
		charpos=i;
		found=1; 
	    }
	}
	
	if(done==0 && str[i]==ch)
	{
	    found=1;
	    charpos=i;
	    done=1;
	}
    }

    if(found==1)
    {
	return(&str[charpos]);
    }
    else  
    {
	return NULL;
    }
}

char * my_strrchr(const char * str, int ch)
{
    int i = my_strlen(str);
    int found = 0;
    int charpos = 0;

    for(i = my_strlen(str); found==0 && i>= 0; i--)
    {
	if(str[i]=='\0' && ch=='\0')
	{
	    found=1;
	    charpos=i;
	}
	if(found==0 && str[i]==ch)
	{
	    found=1;
	    charpos=i;
	}
    }
    if(found==1)
    {
	return(&str[charpos]);
    }
    else
    {
	return NULL;
    }
}

char * my_strstr(const char * haystack, const char * needle)
{
    int needlecount=my_strlen(needle);
    int counter=my_strlen(haystack);
    int i=0;
    int b=0;
    int done=0;
    int charpos=0;

    for(i=0;i<counter && done==0;i++)
    {
	if(haystack[i]==needle[b])
	{
            b++;
	    if(b==needlecount)
	    {
		done=1;
		charpos=i-b+1;
	    }
	}
	else
	{
	    b=0;
	}
    }
    if(needlecount==0)
    {
	return(&haystack[0]);
    }
    if(done==1)
    {
        return(&haystack[charpos]);
    }
    else 
    {
	return NULL;
    }
}

char * my_strcpy(char * dest, const char * src)
{
    return 0;
}

char * my_strcat(char * dest, const char * src)
{
    return 0;
}

int my_isspace(int ch)
{
    int spacetest = 1;

    if(ch != ' ' && ch!= '\f' && ch != '\n' && ch != '\r' && ch != '\t' && ch != '\v')
    {
	spacetest = 0;
    }

    return spacetest;
}

int my_atoi(const char * str)
{
    return 0;
}

