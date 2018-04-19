	#include <iostream>
	#include <cstdio>
	using namespace std;

	int n,k,t;

	int main(int argc, char const *argv[])
	{
		while(~scanf("%d%d%d",&n,&k,&t))
		{
			if(k<=t && t<=n)
				printf("%d\n", k);
			else if(t<k)
				printf("%d\n", t);
			else if(t>n)
				printf("%d\n", n+k-t);
		}

		return 0;
	}