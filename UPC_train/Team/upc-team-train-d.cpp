#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int n,m,k;
int a[N],b[N],v[N];
int main()
{
    while(~scanf("%d%d",&n,&m)){
        memset(v,0,sizeof(v));
        for(int i=1;i<=m;i++){
            scanf("%d",a+i);
            v[a[i]]=1;
        }
        int pos = 1;
        for(int i=1;i<=n;i++){
            if(!v[i]) b[pos++] = i;
        }
        sort(b+1,b+pos);
        int l=1,r=1;
        for(int i=1;i<=n;i++){
            if(l > m){
                printf("%d\n",b[r]);
                r++;
            }
            else if(r >= pos){
                printf("%d\n",a[l]);
                l++;
            }
            else if(b[r] < a[l]){
                printf("%d\n",b[r]);
                r++;
            }
            else{
                printf("%d\n",a[l]);
                l++;
            }
        }
    }
 
    return 0;
}