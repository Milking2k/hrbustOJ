#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		switch(n)
		{
			case 0:return 0;
			case 1:printf("Accepted\n");break;
			case 2:printf("Wrong Answer\n");break;
			case 3:printf("Time Limit Exceed\n");break;
			case 4:printf("Output Limit Exceed\n");break;
			case 5:printf("Memory Limit Exceed\n");break;
			case 6:printf("Runtime Error\n");break;
			case 7:printf("Presentation Error\n");break;
			case 8:printf("Compile Error\n");break;
		}
	}
	return 0;
}