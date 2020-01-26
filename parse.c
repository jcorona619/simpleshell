#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int parse(char *word){

    int chr;
    int count = 0;
    const char* env;

    /* REMOVE LEADING WHITESPACE FROM CHAR ARRAY */

    while(isspace((unsigned char)*word)) *word++;

    /* PROCESS WORDS UNTIL END OF FILE or ctl-d */

    while((chr = getchar()) != EOF){

    	/* WORD LENGTH LIMIT: 255 INCLUDING STRING TERMINATOR
    	 * CHARACTERS AFTER 255 WILL BE IGNORED */

    	if(count == 254){
    		ungetc(chr,stdin);
    		*word++ = '\0';
    		return count;
    	}
        
        /* BASE CASE FOR WORD: SPACE ' ' OR NEWLINE '\n' 
         * RETURN LENGTH OF WORD */
        
        if(chr == ' ' || chr == '\n'){
            *word = '\0';
            return count;
        }

        /* 				META CHARACTERS:
         *
         *  < - REDIRECT CONTENTS FROM FILE INTO COMMAND
         *  > - REDIRECT COMMAND OUTPUT TO FILE
         *  | - PIPE PROCESS FROM ONE COMMAND TO ANOTHER
         *  & - RUN PROCESS IN THE BACKGROUND
         *
         *  Each of these characters are treated as a separate word */
        
        if(chr == '<' || chr == '>' || chr == '&' || chr == '|'){
        	/* Separate metacharacter if no space exits betwen other characters */
            if(count != 0){
            	ungetc(chr,stdin);
            	*word = '\0';
            	return count;
            }
            else{
            	*word++ = chr;
                *word = '\0';
                count++;
                return count;
            }
        }

        /* USER HOME DIRECTORY */
        if(chr == '~'){
        	env = getenv("HOME");
        	while(strlen(env)){
        		*word = *env++;
        		count++;
        	}
        }
        *word++ = chr;
        count++;
  
    }
    *word = '\0';
    return -255;
}