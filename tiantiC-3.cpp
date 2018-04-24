#include <bits/stdc++.h>
using namespace std;
#define rd(x) scanf("%d",&x)
#define rc(x) scanf("%c",&x)
#define r1d(x) scanf("%1d",&x)
#define rdd(x) scanf("%d%d",&x,&y)
#define rddd(x) scanf("%d%d%d",&x,&y,&z)
#define ll long long int

int n;
char emt[50005];
int cnt;
int ans;
int wcont=0,lcont=0;
bool flag=1;
int main()
{
	// freopen("in.txt","r",stdin);
	int len=0;
	for (int i = 0; emt[len-1]!='E' ; ++i)
	{
		char ch;
		rc(ch);
		if(ch!='\n') emt[len++] = ch;
	}
	flag=1;
	int pos=0;
	while(flag)
	{
		wcont=0,lcont=0;
		for (int i = 0; i < 11; ++i,pos++)
		{
			if(emt[pos]=='E'){
				flag=0;break;
			}
			else if(emt[pos]=='W') wcont++;
			else if(emt[pos]=='L') lcont++;
		}
		printf("%d:%d\n", wcont,lcont);
	}
	printf("\n");
	flag=1;
	pos=0;
	while(flag)
	{
		wcont=0,lcont=0;
		for (int i = 0; i < 21; ++i,pos++)
		{
			if(emt[pos]=='E'){
				flag=0;break;
			}
			else if(emt[pos]=='W') wcont++;
			else if(emt[pos]=='L') lcont++;
		}
		printf("%d:%d\n", wcont,lcont);
	}
	return 0;
}