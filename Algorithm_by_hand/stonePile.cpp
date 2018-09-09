// wa


#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,a[107],b[107];
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}

	sort(a+1,a+1+n);
	int l=0,r=0;
	int ans;
	for(int i=1;i<=n;i++){
		if(l<r) l+=a[i];
		else r += a[i];
	}
	ans = abs(l-r);
	l=0,r=0;
	for(int i=n;i>=1;i--){
		if(l<r) l += a[i];
		else r += a[i];
	}
	ans = min(ans, abs(l-r));
	printf("%d\n", ans);

	return 0;
}