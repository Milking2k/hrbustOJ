#include<iostream>
using namespace std;
long n,a[1<<17],b[1<<17],sum;
main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		if(i)
		{
			b[i-1]=a[i]-a[i-1];
		}
	}
	b[n-1]=a[0]-a[n-1];
	long all=-~n*n/2;
	if(sum%all)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	long k=sum/all;
	for(int i=0;i<n;i++)
	{
		b[i]-=k;
		if(b[i]>0||b[i]%n)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
}