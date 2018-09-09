#include <bits/stdc++.h>
using namespace std;
// int foo(int x)
// {

// }
int main(int argc, char const *argv[])
{
	int l,r;
	int ans=0; 
	cin >> l >> r; 
	for(int i=l;i<=r;i++)
	{
		for(int j=i;j>0;j/=10)
		{
			if(j%10==2){
	  			ans++;
	  		}
		}
	}
	printf("%d\n",ans);
	return 0;
}