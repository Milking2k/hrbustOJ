#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn=1e6+5;
vector<int >v[maxn];
map<pair<int,int> ,int>mp;
int main() {
    int T;
    int n;
    read(T);
    while(T--) {
        read(n);
        mp.clear();
        for(int i=0;i<=n;i++) {
            v[i].clear();
        }
        int cnt=0;
        for(int i=1;i<=n;i++) {
            int x;
            read(x);
            for(int j=1;j<=x;j++) {
                int f,t;
                read(f),read(t);
                if(mp[make_pair(f,t)] < 1) {
                    cnt++;
                    mp[make_pair(f,t)]=cnt;
                }
                int pos=mp[make_pair(f,t)];
                v[pos].push_back(i);
            }
        }
        int ans=0;
        for(int i=1;i<=cnt+1;i++) {
            int tmp=1;
            ans=max(ans,tmp);
            for(int j=1;j<v[i].size();j++) {
                if(j==1) {
                    if(v[i][j]==v[i][j-1]+1)tmp=2;
                    else if(v[i][j]!=v[i][j-1]+1) tmp=1;
                    ans=max(ans,tmp);
                    continue;
                }
                if(v[i][j]==v[i][j-1])continue;
                if(v[i][j]==v[i][j-1]+1)tmp++;
                else tmp=1;
                ans=max(ans,tmp);
            }
        }
        cout<<ans<<endl;
    }
}
