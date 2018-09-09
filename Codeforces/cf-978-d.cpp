#include <bits/stdc++.h>
using namespace std;
long long n, d, x, s, mn=1e9, a[100005];
int main() {
	int i, j, k;
	cin>>n;
	for(i=0; i<n; i++) cin>>a[i];
	for(i=-1; i<=1; i++) for(j=-1; j<=1; j++) {
		d = a[1] + j - a[0] - i;
		s = abs(i);
		for(k=1; k<n; k++) {
			x = abs(a[k] - (a[0]+i + k*d));
			if(x>1) break;
			s += x;
		}
		if(k==n) mn = min(mn, s);
	}
	cout<<(mn<1e9 ? mn:-1);
	return 0;
}