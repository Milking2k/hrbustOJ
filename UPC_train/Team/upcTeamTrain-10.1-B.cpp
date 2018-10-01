#include <bits/stdc++.h>
using namespace std;

const int maxn=2006;
char s[505][maxn];

bool solve(char S[maxn],char T[maxn])
{
    int slen=strlen(S);
    int tlen=strlen(T);
    bool ok=true;
    int j=0;
    for(int i=0;i<slen;i++){
        if(S[i]==T[j])j++;
    }
    if(j>=tlen)return true;
    return false;
}
int stk[505],top;
int main()
{
    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--){
        int n;
        scanf("%d",&n);
        top=0;
        for(int i=1;i<=n;i++){
            scanf("%s",&s[i]);
        }
        int ans=-1;
        stk[top++]=1;
        for(int i=2;i<=n;i++){
            bool as=true;
            for(int j=0;j<top;++j){
                bool pp=solve(s[i],s[stk[j]]);
                if(!pp){
                    as=false;
                    break;
                }
            }

            if(!as){
                stk[top++]=i;
                ans=max(ans,i);
            }
            else{
                top=0;
                stk[top++]=i;
            }
        }
//        for(int i=0;i<a.size();++i){
//            printf("%s\n",s[a[i]]);
//        }
//        puts("");
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
/*
1
3
a
ab
ca
*/
