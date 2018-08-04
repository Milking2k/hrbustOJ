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
const ll mod = 1000000007;
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int n,m,q;
char s[1007];
char t[1007];

int lft[100007];
int rit[100007];

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    scanf("%s",s);
    scanf("%s",t);


    int pos=0;
    int cnt=0;
    rep(i,0,n+1){
        if(s[i]==t[0]){
            int j = i;
            pos=0;
            while(s[i]==t[pos] && t[pos]!='\0' &&pos<=m) i++,pos++;
//            printf("pos:%d\n",pos);
            if(pos<m) i=j;
            else if(i-j == m){
                lft[cnt] = j;
                rit[cnt] = i-1;
                cnt++;
                i--;
            }
            i=j;
        }
    }



    rep(i,1,q+1){
        int x,y;
        scanf("%d %d",&x,&y);
        x--,y--;
        if(y-x+1 < m) printf("0\n");
        else {
            ll ans = 0;
            int len = lower_bound(lft,lft+cnt, x) - (lft);
//                printf("len:%d\n",len);
            for(int i = len;i<cnt && i<=y;i++){
//                printf("rit:%d\n",rit[i]);
                if(rit[i] <= y) ans++;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}

