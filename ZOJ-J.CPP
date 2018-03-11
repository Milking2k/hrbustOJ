#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[300003];
int check(int array[],int low,int high,int target)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(array[mid]>target)
            high=mid-1;
        else if(array[mid]<target)
        low=mid+1;
        else
            return mid;
    }
    return-1;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		for (int i = 0; i < n; ++i)
		{
			int x;
			scanf("%d",&x);
			// printf("no error\n");
			if(check(a,0,n-1,x) != -1)
			{
				printf("%d\n", x);
				break;
			}
		}
	}
	return 0;
}