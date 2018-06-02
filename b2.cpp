#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
typedef long long ll;


int n;
int dir[4][2]={{1,1},{2,2},{1,2},{2,1}};
char s[100007];
int iswt[100007];

int check()
{
	for(int i=1;i<=n;i++)
    {
		int l=i-1,r=i+1;
		if(l<=0)l=n;
		if(r>=n+1)r=1;

        if(iswt[i]==1&&s[i]=='o'&&iswt[l]!=iswt[r]) return 0;
        if(iswt[i]==1&&s[i]=='x'&&iswt[l]==iswt[r]) return 0;
        if(iswt[i]!=1&&s[i]=='o'&&iswt[l]==iswt[r]) return 0;
        if(iswt[i]!=1&&s[i]=='x'&&iswt[l]!=iswt[r]) return 0;

	}
	return 1;
}
void solve()
{
	for(int i=2;i<n;i++)
    {
		if(iswt[i]==1)
		{
			if(s[i]=='o')iswt[i+1]=iswt[i-1];
			else iswt[i+1]=(iswt[i-1]==1?2:1);
		}
		else
		{
			if(s[i]=='o')iswt[i+1]=(iswt[i-1]==1?2:1);
			else iswt[i+1]=iswt[i-1];
		}
	}
}
bool pt()
{
    for(int i=1;i<=n;i++)
    {
        if(iswt[i]==1) printf("S");
        else printf("W");
    }
    printf("\n");
    return false;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);

    for(int i=0;i<4;i++)
    {
        iswt[1]=dir[i][0];
        iswt[2]=dir[i][1];
        solve();
        if(check()) return pt();
    }
	printf("-1\n");
	return 0;
}
