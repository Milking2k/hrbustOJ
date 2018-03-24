#include <bits/stdc++.h>
using namespace std;
#define N 105
int dp[N+1][N+1];
char str1[N],str2[N];
int main(int argc, char const *argv[])
{
	int l,n,m;
	cin >> l >> n >> m;
	int a[50005];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	return 0;
}
int LCSL(int len1,int len2)
{
	int i,j;
	int len=maxx(len1,len2);
	for(i=0;i<=len;i++)
	{
		dp[i][0]=0;
		dp[0][i]=0;
	}
	for(i=1;i<=len1;i++)
		for(j=1;j<=len2;j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
			}
		}
	return dp[len1][len2];
}
int main()
{
	while(cin>>str1>>str2)
	{
		int len1=strlen(str1);
		int len2=strlen(str2);
		cout<<LCSL(len1,len2)<<endl;
	}
	return 0;
}