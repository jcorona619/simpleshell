#include "parse.h"
//#include "parse.c"
#include "cshell.h"

int end_of_file;
int end_of_file;
int redirect_right;
int duplicate_right;
int redirect_left;
int pipe_flag;
int background_flag;
int empty_line;
int env_var;


int main(){


	int fd[20];				/* File desciptor array for up to 10 pipes */
	int pid1, pid2;			/* Variables for process IDs */
	char* home_dir;			/* variable for home directory */
	int directory;			/* for chdir(), for error checking */
	int new_process;		/* variable for new process ID */
	int in_fd;				/* variable for file desciptors */

	char s[10000];			/* char array for all words received from command line */
	char* argv[MAXITEM];	/* pointer array that contains all words returned from parse_words() */
	char* out_array[1];		/* pointer to file for output redirection */
	char* in_array[1];		/* pointer to file for input redirection */
	char cwd[255];			/* char array used for getcwd() */
	char *cur_dir = "";		/* empty string, holds current directory */

    setpgid(0,0);
    (void) signal(SIGTERM, my_sig_handler);

    /* Infinte loop to run shell until EOF signal */
     while(1){

        /* PROMPT */
        printf("%s>>",cur_dir);

        /* reset all flags to 0 */
        reset_global_flags();

        /* parse_words(): calls parse(), sets global flags */
        parse_words(s,argv,in_array,out_array);
        (void) printf("argv[0]: %s\n",argv[0]);
        (void) printf("argv[1]: %s\n",argv[1]);
        (void) printf("argv[2]: %s\n",argv[2]);
        (void) printf("argv[3]: %s\n",argv[3]);
        (void) printf("argv[4]: %s\n",argv[4]);
        (void) printf("argv[5]: %s\n",argv[5]);
        (void) printf("argv[6]: %s\n",argv[6]);

        if(end_of_file) break;

        if(empty_line) continue;

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

	while(1){

		word = parse(s);

		if(word == -255){
			end_of_file = 1;
			return;
		}

		if(word == 0){
			if(i == 0){
				empty_line = 1;
				return;
			}
		}

		if(*s == '>'){
			//todo
		}

		if(*s == '<'){
			//todo
		}

		if(*s == '|'){
			//todo
		}

		if(*s == '&'){

		}


	}


}

void sig_handler(int signum){}

void reset_global_flags(){
	end_of_file = 0;
	redirect_right = 0;
    duplicate_right = 0;
    redirect_left = 0;
    pipe_flag = 0;
    background_flag = 0;
    empty_line = 0;
    env_var = 0;
}
void my_sig_handler(int signum){}

void pipe_process(char* argv[], int fd[], char* in_array, char* out_array){

}
void redirect_input(char* argv[], char* in_array[]){

}
void redirect_output(char* argv[], char* in_array[], char* out_array[]){
	
}