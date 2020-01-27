#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <math.h>
#include <libgen.h>
#define MAXITEM 100

void reset_global_flags();
void my_sig_handler(int signum);
void parse_words(char* s, char *argv[], char* in_array[], char* out_array[]);
void pipe_process(char* argv[], int fd[], char* in_array, char* out_array);
void redirect_input(char* argv[], char* in_array[]);
void redirect_output(char* argv[], char* in_array[], char* out_array[]);
