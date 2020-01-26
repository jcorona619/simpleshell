#include <stdio.h>
#include "parse.h"
#include "parse.c"

int main(){
    int c;
    char str[100];
    
    for(;;){
    	(void) printf("n=%d, s=[%s]\n", c = parse(str), str);
    	if(c == -255) break;
    }
}