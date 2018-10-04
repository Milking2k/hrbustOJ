#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
const int maxn=1e6+4;
 
int solve(int x) {
    int ret=0;
    while(x) {
        int d=x%10;
        ret+=d*d;
        x/=10;
    }
    return ret;
}
map<int,int>mp;
int main() {
    int n;
    while(read(n)!=EOF) {
        int f=0;
        int m=solve(n);
//        cout<<m<<endl;
        mp.clear();
        mp[m]=1;
        while(1) {
            if(m==1) {
                f=1;
                break;
            }
            m=solve(m);
            if(m==1) {
                f=1;
                break;
            }
            if(mp[m]&&m!=1){f=0;break;}
            else mp[m]=1;
//            cout<<m<<endl;
        }
        if(f==1)puts("HAPPY");
        else puts("UNHAPPY");
    }
}