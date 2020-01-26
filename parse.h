/*	
parse.h - header file for parse() function 
*/

#include <stdio.h>
#include <string.h>
#include <strings.h>
#define STORAGE 255

/* Function Prototype */
int parse(char *word);

/*

The parse() function gets one word at a time from the input stream. 
The function uses a pointer to a character array and traverses the array 
for space separated words.

INPUT: A pointer to a character array
OUTPUT: Length of a space separated word or -255 if end-of-file (EOF) is reached.

*/