#include "parse.h"
#include "cshell.h"


int main(){


	int fd[20];				/* File desciptor array for up to 10 pipes */
	int pid1, pid2;			/* Variables for process IDs */
	char* home_dir;
	int directory;			/* for chdir(), for error checking */
	int new_process;		/* variable for new process ID */
	int in_fd;				

	char s[10000];			/* char array for all words received from command line */
	char* argv[MAXITEM];	/* pointer array that contains all words returned from parse_words() */
	char* out_array[1];		/* pointer to file for output redirection */
	char* in_array[1];		/* pointer to file for input redirection */
	char cwd[255];			/* char array used for getcwd() */
	char *cur_dir = "";		/* empty string, holds current directory */

    setpgid(0,0);
    (void) signal(SIGTERM, my_sig_handler)

    /* Infinte loop to run shell until EOF signal */
     while(1){

        /* PROMPT */
        printf("%s:>",cur_dir);

        /* reset all flags to 0 */
        reset_global_flags();

     }

    killpg(getpgrp(), SIGTERM);
    printf("Shell Terminated...\n");
    exit(0);

}

void parse_words(char *s, char **argv, char **in_array, char** out_array){

	int word;
	int i = 0;
	int j = 0;
	in_array[0] = NULL;
	out_array[0] = NULL;
}

void my_sig_handler(int signum){}