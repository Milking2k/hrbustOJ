#include<bits/stdc++.h>
using namespace std;
int main()
{
	// freopen("in.txt","r",stdin);
    int n;
    int a[100005];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    sort(a,a+n);
	for(int i=0;i<n;i++) i==0?printf("%d", a[i]):printf(" %d", a[i]);
	printf("\n");
    return 0;
}