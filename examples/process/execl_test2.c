# include <stdio.h>
#include <sys/types.h>   // for pid_t

int main()
{
	pid_t  pid; // creatdsa
	
	printf("\n\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");

	printf ("Original processPI D %d;PPID %d\n", getpid (), getppid ());
	printf(" ----------------fork()-------------------\n");


	/* fork another process */
	pid = fork();
	if (pid < 0)  /* error occurred */
	{	fprintf(stderr, "Fork Failed.\n");
		exit(-1);
	}

	if (pid == 0) /* child process */
	{ 
		printf ("CHILD process:PID %d ; PPID %d\n", getpid (), getppid ());

		execlp("/bin/ls", "ls", NULL);
		// subprocess exe here

		printf("after exec().\n");

	}
	else  /* parent process */
	{

		printf ("Parent process : PID %d and PPID %d.\n", getpid (), getppid ());

		printf ("My child's PID is %d\n", pid);

		/* parent will wait for the child to complete */
		wait (NULL);
		
		printf ("Child Complete.\n");

//		exit(0);
	}

	printf ("PID %d terminates.\n", getpid () ); /* Both processes execute this */
	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
}
