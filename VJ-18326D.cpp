#include <iostream>
#include <cstdio>
using namespace std;
int ans[35];
int ansLen;
int count=0;
void foo(int x)
{
	ansLen = 0;
	count = 0;
	int cnt = x;
	while(cnt)
	{
		if(cnt&1){ans[ansLen++] = 1;count++;}
		else	 {ans[ansLen++] = 0;}
		cnt >>= 1;
	}
	return ;
}

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n && n)
	{
		foo(n);
		printf("The parity of ");
		for (int i = ansLen-1; i >= 0; --i)
		{
			printf("%d", ans[i]);
		}
		printf(" is %d (mod 2).\n",count);
	}
	return 0;
}