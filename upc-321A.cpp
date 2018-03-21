#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,m;
	queue<int> q;
	int count=0;
	int a[1005];
	memset(a,0,sizeof(a));
	cin >> m >> n; 
	for(int i=0;i<n;i++)
	{
		int num;
		cin >> num;
		if(a[num]==0)
		{
			a[num]=1;
			count++;
			q.push(num); 
			if(q.size() > m)
			{
				a[q.front()]=0;
                q.pop();
            }
        }
    }  
	printf("%d\n", count);
	return 0;
}