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
inline int read(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return x*f;}
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 2E5+7;

PII p[N];
int n,k;
int a[N];

bool cmp(int a, int b)
{
    return a>b;
}
int main()
{
    int tot=0;
    scanf("%d%d",&n,&k);
    rep(i,1,n+1){
        int x;
        scanf("%d",&x);
        if(a[x]==0)tot++;
        a[x]++;
    }
    sort(a,a+N,cmp);

//    if(k>=tot) printf("1\n");
//    else{
        int sum=0;
//        printf("aa%d %d\n",k,tot);
        rep(i,k,tot+1){
//            printf("ss %d:%d \n",i,a[i]);
            sum+=a[i];
        }
        printf("%d",sum);
//    }
}
//#include <iostream>
//#include <stdio.h>
//#include <string.h>
//#include <algorithm>
//#include <set>
//using namespace std;
//typedef long long ll;
//int a[200005];
//bool compare(int a,int b){
//    return a>b;
//}
//int main(){
//    ios::sync_with_stdio(0);
//    int n,k,x;
//    cin>>n>>k;
//    memset(a,0,sizeof(a));
//    for(int i=0;i<n;i++){
//        cin>>x;
//        a[x]++;
//    }
//    int ans=0;
//    sort(a,a+n,compare);
//    for(int i=k;i<=n;i++){
//        ans+=a[i];
//    }
//    cout<<ans<<endl;
//    return 0;
//}


//int main()
//{
//    scanf("%d%d",&n,&k);
//    rep(i,1,n+1) a[i] = read();
//
//    sort(a+1,a+1+n);
//    int cnt=a[1];
//    int len=1;
//    p[len] = mp(1,a[1]);
//    rep(i,2,n+1){
//        if(a[i] == cnt) p[len].fi+=1;
//        else {
//            len++;
//            cnt = a[i];
////            printf("now:%d\n",a[i]);
//            p[len] = mp(1,a[i]);
//        }
//    }
//
//    sort(p+1,p+len+1);
//
//    ll ans=0;
//    if(len<=k) printf("1\n");
//    else{
////        printf("ss%d %d %d\n",len,k,len-k);
//        rep(i,1,len-k+1){
//            ans += p[i].fi;
//        }
//        printf("%lld\n",ans);
//    }
//    return 0;
//}
