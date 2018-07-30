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
// head

char ans[555][555];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
            int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        int lena = 2*a+1;
        int lenb = 2*b+1;
        int lenc = 2*c+1;
//        printf("lena:%d lenb:%d lenc:%d\n",lena,lenb,lenc);

        rep(i,0,lenc+lenb){
            rep(j,0,lena+lenb){
                ans[i][j]='.';
            }
        }
        rep(i,lenb,lenc+lenb){
            if((i-lenb)%2==0)
                rep(j,0,lena){
                    if(j%2==0) ans[i-1][j]='+';
                    else ans[i-1][j]='-';
                }
            else
                rep(j,0,lena){
                    if(j%2==0) ans[i-1][j]='|';
                    else ans[i-1][j]='.';
                }
        }




        rep(i,0,lenb){
            rep(j,0,lena){
                if(i+j<lenb-1)
                    ans[i][j]='.';
            }
        }



        rep(i,0,lenb){
            if(i%2==0){
                rep(j,0 ,lena){
                    if((j)%2==0){
                        ans[i][j+(lenb-i-1)]='+';
                    }
                    else{
                        ans[i][j+(lenb-i-1)]='-';
                    }
                }
            }
            else{
                rep(j,0,lena){
                    if((j)%2==0){
                        ans[i][j+(lenb-i-1)]='/';
                    }
                    else{
                        ans[i][j+(lenb-i-1)]='.';
                    }
                }
            }
        }

        rep(j,lena,lena+lenb-1){

            if((j-lena)%2==0){
                rep(i,0,lenc-1){
                    if(i%2==0){
                        ans[lena+lenb-(j)+i-1][j]='.';
//                        printf("j:%d i:%d\n",j,i);
                    }
                    else{
                        ans[lena+lenb-(j)+i-1][j]='/';
                    }
                }
            }
            else{
                rep(i,0,lenc-1){
                    if(i%2==0){
                        ans[lena+lenb-(j)+i-1][j]='|';
//                        printf("2:1j:%d i:%d\n",j,i);
                    }
                    else{
                        ans[lena+lenb-(j)+i-1][j]='+';
                    }
                }
            }
        }



        rep(i,0,lenc+lenb-1){
            rep(j,0,lena+lenb-1){
                printf("%c",ans[i][j]);
            }
            puts("");
        }
    }

    return 0;
}
