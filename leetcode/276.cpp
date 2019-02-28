#include<bits/stdc++.h>
using namespace std;

int solve(int n, int k)
{ 
if(n==0) return 0;
	else if(n==1) return k;
	
int ans[4]; 
ans[1] = k, ans[2] = k*k;

for ( int i = 2; i <= n; ++i) {
	ans[3] = (ans[1] + ans[2])*(k-1);
	ans[1] = ans[2];
	ans[2] = ans[3];
}
return ans[3];
}

int main()
{
	int n,k;
	// scanf
	solve(n,k); 
return 0;
}
