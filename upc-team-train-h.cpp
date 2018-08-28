#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = a; i<n; i++)
#define per(i,a,n) for (int i = n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll MOD = 1000000007;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
 
char r[200],c[200];
int a[200],b[200];
bool vr[200],vc[200];
int ans[200][200];
int main()
{
    while(~scanf("%s",r)){
        rep(i,0,60+1)rep(j,0,60+1){
            ans[i][j] = 1;
        }
        rep(i,0,60) vr[i] = vc[i] = false,a[i] = b[i] = 0;
 
        // scanf("%s",r);
        scanf("%s",c);
        int n = strlen(r);
        int m = strlen(c);
//        printf("n::%d %d\n",n,m);
        int len1=0,len2=0;
        rep(i,0,n){
            if(m%2==0){
                if(r[i]=='0')a[i] = 0;
                else a[i] = 1,len1++;
            }
            else{
                if(r[i]=='1')a[i] = 0;
                else a[i] = 1,len1++;
            }
        }
        rep(i,0,m){
            if(n%2==0){
                if(c[i]=='0')b[i] = 0;
                else b[i] = 1,len2++;
            }
            else{
                if(c[i]=='1')b[i] = 0;
                else b[i] = 1,len2++;
            }
        }
 
//        rep(i,0,n) printf("%d_",a[i]);
//        puts("");
//        rep(i,0,n) printf("%d_",b[i]);
//        puts("");
 
        bool ok=true;
        if(len1<len2){
            per(i,0,n){
                if(a[i]==0)continue;
                per(j,0,m){
                    if(b[j]==1 && !vc[j] ){
                        ans[i][j] = 0;
                        vc[j] = true;
                        vr[i] = true;
                        break;
                    }
                }
            }
 
            int flag = -1;
            rep(i,0,m){
                if(b[i]==1 && !vc[i]){
                    if(flag != -1){
                        ans[0][flag] = 0;
                        ans[0][i] = 0;
                        vc[i] = vc[flag] = 1;
                        flag = -1;
                    }
                    else{
                        flag = i;
                    }
                }
            }
 
            rep(i,0,m) if(b[i]==1 && !vc[i]) ok =false;
        }
        else{
            per(i,0,m){
                if(b[i]==0)continue;
                per(j,0,n){
                    if(a[j]==1 && !vr[j] ){
                        ans[j][i] = 0;
                        vc[i] = true;
                        vr[j] = true;
                        break;
                    }
                }
            }
 
            int flag = -1;
            rep(i,0,n){
                if(a[i]==1 && !vr[i]){
                    if(flag != -1){
                        ans[flag][0] = 0;
                        ans[i][0] = 0;
                        vr[i] = vr[flag] = 1;
                        flag = -1;
                    }
                    else{
                        flag = i;
                    }
                }
            }
 
            rep(i,0,n) if(a[i]==1 && !vr[i]) ok =false;
        }
 
        if(!ok){
            printf("-1\n");
            continue;
            // return 0;
        }
 
        rep(i,0,n){
            rep(j,0,m){
                printf("%d",ans[i][j]);
            }
            puts("");
        }
    }
    return 0;
}
