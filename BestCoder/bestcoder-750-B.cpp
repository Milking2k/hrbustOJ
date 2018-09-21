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
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
const int N = 1e5+7;
int T,n,m,k;
char s[N];

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    for (scanf("%d", &T); T; T--){
        scanf("%d%d", &n, &k);
        scanf("%s", s);

        vector<int> s0, s1, s2, s3;
        s1.pb(1111111), s2.pb(1111111), s3.pb(1111111);
        int cnt0=0, cnt1=0, cnt2=0, cnt3=0;
        rep(i,0,n){
            if(s[i]=='0')
                s0.pb(i), cnt0++;
            else if((s[i]-'0')%3 == 0)
                s3.pb(i), cnt3++;
            else if((s[i]-'0')%3 == 1)
                s1.pb(i), cnt1++;
            else if((s[i]-'0')%3 == 2)
                s2.pb(i), cnt2++;
        }

        if(k+1==n && s0.size()){
            printf("yes\n");
            continue;
        }
        bool flag = 0;
        for (int num0 = 0; num0 <= (cnt0 + cnt3) && num0 <= k;num0++){
            for (int num1 = 0; num1 <= cnt1 && num1 <= k - num0;num1++){
                int num2 = k - num0 - num2;
                if(num2 > cnt2) continue;

                int pos3 = num0 - cnt0;
                int pos2 = cnt2 - num2;
                int pos1 = cnt1 - num1;
                if(pos2>0 && s2.size() >1) pos2=1;
                else pos2 = 0;

                if(pos1>0&&s1.size()>1) pos1=1;
                else pos1 = 0;

                if (pos3 < 0) pos3 = 0;
                pos3 = cnt3 - pos3;
                
                if(pos3>0 && s3.size()>1) pos3 =1;
                else pos3 = 0;

                if(abs(cnt2-num2-cnt1+num1)%3==0
                   && ( num0 >= s0.size() 
                        || s0[num0] > s1[pos1]
                        || s0[num0] > s2[pos2]
                        || s0[num0] > s3[pos3])){
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        puts(flag ? "yes" : "no");
    }
        return 0;
}