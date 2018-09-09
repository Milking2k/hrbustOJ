#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}


const int maxn=1e7+7;

deque< pair<int, int> > que;
int n,m,k,p,q,r,MOD;
int a[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d%d%d%d",&n,&m,&k,&p,&q,&r,&MOD);
        for(int i=1;i<=k;i++){
            scanf("%d",&a[i]);
        }
        for(int i=k+1;i<=n;i++){
            a[i]=(((ll)p*a[i-1])%MOD+((ll)q*i+r)%MOD)%MOD;
        }
        while(que.size())que.pop_back();
        ll A=0,B=0;
        que.push_back(make_pair(a[n-m+1],n-m+1));
//        printf("fuck %d %d\n",n-m+1,a[n-m+1]);
        for(int i=n-m+2;i<=n;i++){
            int now=que.back().first;
            if(a[i]>now){
                que.push_back(make_pair(a[i],i));
//                printf("in %d %d\n",a[i],i);
            }
        }
//        printf("asd %d %d\n",que.back().first,que.size());
        if(que.size()==1&&que.front().first==0){
            A+=n-m+1;
            B+=n-m+1;
        }
        else{
            A+=(ll)que.back().first^(n-m+1);
            B+=(ll)que.size()^(n-m+1);
        }
        for(int i=n-m;i>=1;i--){
            while(que.size()&&a[i]>=que.front().first){
                    que.pop_front();
            }
            que.push_front(make_pair(a[i],i));
//            printf("asd %d %d %d\n",que.front().first,que.back().first,i+m);
            if(que.back().second>i+m-1){
                que.pop_back();
            }
            if(que.size()==1&&que.front().first==0){
                A+=i;
                B+=i;
            }
            else{
                A+=(ll)que.back().first^(i);
                B+=(ll)que.size()^(i);
            }
//            printf("test %d == %d %d %d\n",i,a[i],A,B);
        }
        printf("%lld %lld\n",A,B);
    }
    return 0;
}
/*
2
10 6 10 5 5 5 5
3 2 2 1 5 7 6 8 2 9
10 6 10 5 5 5 5
3 2 2 1 5 7 6 8 2 9
*/
