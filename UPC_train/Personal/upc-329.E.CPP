#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[105];
	int cnt=0;
	for (int i = n; i >= 0; --i)
	{
		cin >> cnt;

			if(cnt == 0 && n==0)printf("0");
			if(cnt == 0)continue;
			else if(cnt > 0 && cnt!=1 && i==n)printf("%d",cnt);
			else if(cnt > 0 && cnt!=1 && i!=n)printf("+%d",cnt);

			else if(cnt > 0 && cnt==1 && i==0)printf("+1");
			else if(cnt > 0 && cnt==1 && i==n)printf("");
			else if(cnt > 0 && cnt==1 && i!=n)printf("+");

			else if(cnt < 0 && cnt==-1 && i!=0)printf("-");
			else if(cnt < 0 && cnt==-1 && i==0)printf("-1");

			else if(cnt < 0 && cnt!=-1)printf("%d",cnt);

			if(i>1)printf("x^%d", i); 
			else if(i==1)printf("x");
			else if(i==0)printf("");

	}
	printf("\n");
	return 0;
}