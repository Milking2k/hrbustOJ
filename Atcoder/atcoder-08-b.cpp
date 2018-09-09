#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, k; cin>>n>>k;
    vector<long> s(n+1), p(n+1);
    for(int i=0; i<n; ++i) {
        int a; cin>>a;
        p[i+1]=p[i]+(a>0)*a;
        s[i+1]=s[i]+a;
    }
    for (int i = 0; i <= n; ++i)
    {
    	cout << p[i] << "\t";
    }
    printf("\n");
    for (int i = 0; i <= n; ++i)
    {
    	cout << s[i] << "\t";
    }
    printf("\n");
    long res=0;
    for(int i=1; i+k-1<=n; ++i) {
        auto x=p[n]-(p[i+k-1]-p[i-1]);
        auto y=s[i+k-1]-s[i-1];
        cout << x << " " << y << " ";
        if (y>0) x+=y;
        res=max(res, x);
        cout << res << endl;
    }
    cout<<res;
}