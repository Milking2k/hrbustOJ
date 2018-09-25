#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+7;
char a[maxn],b[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",a+1);
        scanf("%s",b+1);
        int lena=strlen(a+1);
        int lenb=strlen(b+1);
        if(lena!=lenb){
            puts("-1");
            continue;
        }
        int cnta=0;
        int cntb=0;
        for(int i=1;i<=lena;i++){
            if(a[i]=='a')cnta++;
            if(b[i]=='a')cntb++;
        }
        if(cnta!=cntb){
            puts("-1");
            continue;
        }
        long long ans=0;
        int j=1;
        for(int i=1;i<=lena;i++){
            if(a[i]==b[i])continue;
            j=max(j,i+1);
            while(b[i]!=a[j])j++;
            ans+=j-i;
            swap(a[i],a[j]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
