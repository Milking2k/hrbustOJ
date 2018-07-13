#include <stdio.h>
#include <signal.h>
int wait_mark = 1;
void stop()
{
	wait_mark = 0;
}
 
int main()
{
	int pid1,pid2;
	while((pid1=fork())==-1)
		;
	printf("pid1=%d\n",pid1);
	if(pid1==0)
	{
		signal(SIGQUIT,SIG_IGN);
		wait_mark = 1;
		printf("pid1 created!\n");
		signal(16,stop);
		while(wait_mark)
			;	
		printf("\npid1 killed by parent\n");
	}
	else
	{
		while((pid2=fork())==-1){}
		printf("pid2=%d\n",pid2);
		if(pid2==0)
		{
			signal(SIGQUIT,SIG_IGN);
			wait_mark = 1;
			printf("pid2 created!\n");
			signal(17,stop);
			while(wait_mark)
				;
			printf("\npid2 killed by parent\n");
		}
		else
		{
			signal(SIGQUIT,stop);
			while(wait_mark)
				;
			wait_mark = 1;
			kill(pid1,16);
			kill(pid2,17);
			wait(0);
			wait(0);
			wait_mark = 1;
			while(wait_mark)
			{
				signal(SIGQUIT,stop);
			}
			printf("\nparent killed!\n");
		}
	}
	return 0;
}
