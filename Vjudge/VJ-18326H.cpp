#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int data[105];
int parse[105];
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		int i;
		cin >> n;
		for (i = 1; i <= n; ++i){ cin >> data[i];}
		for (i = 1; i <= n; ++i){ cin >> parse[i];}

		// int flag = 3;//1 stack  2queue 0neither 3both
		int isstack=1;
		int isqueue=1;
		for (i = 1; i <= n; ++i)
		{
			if (data[i] != parse[i])
			{
				// printf("data[i]:%d != parse[i]:%d\n",data[i] , parse[i]);
				isqueue = 0;
			}
			if(data[i]!= parse[n+1-i])
			{
				// printf("data[i]:%d != parse[n-i]:%d\n",data[i] , parse[n-i]);
				isstack = 0;
			}
		}
		if (isqueue && isstack)
		{
			printf("both\n");
		}else if (isqueue && !isstack)
		{
			printf("queue\n");
		}else if (!isqueue && isstack)
		{
			printf("stack\n");
		}else{
			printf("neither\n");
		}

	}
	return 0;
}