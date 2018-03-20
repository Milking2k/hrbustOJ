#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	priority_queue<int,vector<int>,greater<int>> q;
    int n;
    while(cin >> n)
    {
    	int cnt;
    	int ans =0;
    	int i;
    	for(i = 0; i < n; i++)
	    {
	        scanf("%d", &cnt);
	        q.push(cnt);
	    }
	    while(--i)
	    {
	    	int a,b;
	        a=q.top();
	        q.pop();
	        b = q.top();
	        q.pop();
	        ans += a+b;
	        q.push(a+b);
	    }
	    printf("%d\n", ans);
    }
	    
    return 0;
}
