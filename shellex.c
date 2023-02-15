/* $begin shellmain */
#include "csapp.h"
#define MAXARGS   128

/* Function prototypes */
void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv); 
void signal_catch(int signal);
void help();

char *prompt;


int main(int argc, char **argv) 
{
    char cmdline[MAXLINE]; /* Command line */

    signal(SIGINT, signal_catch); //CTRL-C signal catch

    if(argc > 1){ //allowing custom prompt
        if(!strcmp(argv[1],"-p"))
        {
            prompt = argv[2];
        }
    }
    else{
        prompt = "sh257";
    }  
    
    while (1) {
	/* Read */
    printf("%s> ",prompt);  
	Fgets(cmdline, MAXLINE, stdin); 
	if (feof(stdin))
	    exit(0);

	/* Evaluate */
	eval(cmdline);
    } 
}
/* $end shellmain */
  
/* $begin eval */
/* eval - Evaluate a command line */
void eval(char *cmdline) 
{
    char *argv[MAXARGS]; /* Argument list execve() */
    char buf[MAXLINE];   /* Holds modified command line */
    int bg;              /* Should the job run in bg or fg? */
    pid_t pid;           /* Process id */
    
    strcpy(buf, cmdline);
    bg = parseline(buf, argv); 
    if (argv[0] == NULL)  
	return;   /* Ignore empty lines */

    if (!builtin_command(argv)) { 
        if ((pid = Fork()) == 0) {   /* Child runs user job */
            if (execvp(argv[0], argv) < 0) {
                printf("%s: Command not found.\n", argv[0]);
                exit(0);
            }
        }

	/* Parent waits for foreground job to terminate */
	if (!bg) {
	    int status;
	    if (waitpid(pid, &status, 0) < 0)
            unix_error("waitfg: waitpid error");

        if (WIFEXITED(status))
            printf("child exited with status of %d\n", WEXITSTATUS(status));

		
	}
	else
	    printf("%d %s", pid, cmdline);
    }
    return;
}

/* If first arg is a builtin command, run it and return true */
int builtin_command(char **argv) 
{
    if (!strcmp(argv[0], "exit")) /* exit command */
        raise(SIGTERM);
    else if (!strcmp(argv[0], "pid")) /* get process id */
    {
        printf("Shell process id: %d\n", getpid());
        return 1;
    }
    else if (!strcmp(argv[0], "ppid")) /* get parent process id */
    {
        printf("Parent process id: %d\n", getppid());
        return 1;
    }
    else if (!strcmp(argv[0], "help")) /* get the help */
    {
        help();
        return 1;
    }
    else if (!strcmp(argv[0], "cd")) /* print current directory (or change) */
    {
        if (argv[1] == NULL)
        {
            char cwd[100];
            if (getcwd(cwd, sizeof(cwd)) != NULL)
            {
                printf("Current directory: %s\n", cwd);
            }
            else
            {
                printf("error getting cwd");
                return 1;
            }
        }
        else if (argv[1] != NULL) /*change directory if requested*/
        {
            chdir(argv[1]);
        }
        return 1;
    }
    
    if (!strcmp(argv[0], "&"))    /* Ignore singleton & */
	    return 1;
    return 0;                     /* Not a builtin command */
}
/* $end eval */

/* $begin parseline */
/* parseline - Parse the command line and build the argv array */
int parseline(char *buf, char **argv) 
{
    char *delim;         /* Points to first space delimiter */
    int argc;            /* Number of args */
    int bg;              /* Background job? */

    buf[strlen(buf)-1] = ' ';  /* Replace trailing '\n' with space */
    while (*buf && (*buf == ' ')) /* Ignore leading spaces */
	buf++;

    /* Build the argv list */
    argc = 0;
    while ((delim = strchr(buf, ' '))) {
	argv[argc++] = buf;
	*delim = '\0';
	buf = delim + 1;
	while (*buf && (*buf == ' ')) /* Ignore spaces */
            buf++;
    }
    argv[argc] = NULL;
    
    if (argc == 0)  /* Ignore blank line */
	return 1;

    /* Should the job run in the background? */
    if ((bg = (*argv[argc-1] == '&')) != 0)
	argv[--argc] = NULL;

    return bg;
}
/* $end parseline */

//Signal catcher
//Used to catch the interrupt signal and just go back to normal buisness instead of terminating.
void signal_catch(int signal)
{
    printf("\n%s> ", prompt);
    fflush(stdout);
    return;
}


//Help function
//Prints useful information
void help()
{
    printf("*Developer: Austin Leonhirth\n");
    printf("*Run shell with -p <prompt> parameter to change prompt\n");
    printf("*Type man <command> for help with non-built-in commands\n");
}