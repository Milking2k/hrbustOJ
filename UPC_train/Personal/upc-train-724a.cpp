#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7,MOD = 1e9+7, INF=0x3f3f3f3f;
int t,n,m,emt[N];
int main()
{
    string s;
    int vis[30];
    memset(vis,0,sizeof(vis));
    int vis2[30];
    cin >> s;
    int ans=0;
    for(int i=0;i<s.length();i++) {
        if(isupper(s[i])) continue;
        vis[s[i]-'a']=1;
    }

    for(int i=0;i<26;i++) {
        if(vis[i]==0){
            printf("%c",i+'a');
            return 0;
        }
    }
    printf("None\n");
    return 0;
}
