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
int a[N];
struct node
{
    int v,p;
}d[N];
int v[N],p[N];

int main()
{
    for(scanf("%d",&T);T;T--){

        read(n),read(m);
        rep(i,1,n+1) {
            p[i]=v[i]=0;
        }
        int tot=1;


        rep(i,1,n+1){
            read(a[i]);
        }

        int cntt=a[1];
        v[1] = a[1];
        p[1] = 1;
        rep(i,2,n+1){
            if(a[i]>cntt){
                v[++tot] = a[i];
                p[tot] = i;
                cntt = a[i];
            }
        }

//        rep(i,1,tot+1) printf("%d ",v[i]);puts("");
//        rep(i,1,tot+1) printf("%d ",p[i]);puts("");
//
//        printf("tot::%d\n",tot);

        rep(i,1,m+1){
            int x,y;read(x),read(y);
            int len = lower_bound(p+1,p+1+tot,x) - (p);

//            printf("len:%d\n",len);

            if(len == tot+1){//û���ҵ�λ��
                if(v[len-1] < y)
                    printf("%d\n",tot+1);
                else
                    printf("%d\n",tot);
            }
            else if(p[len] == x){// ����޸ĵ�λ���������е�
                if(v[len] < y){ // �Ĵ���
                    int len2 = upper_bound(v+1,v+1+tot,y) - (v);// �ҵ��ϸ����y��λ�ã����λ�õ����Ǵ���y�ģ�����λ�������һ��
//                    printf("len2:%d\n",v[1]);
//                    printf("len2:%d\n",v[tot]);

                    printf("%d\n",len + tot+1 - len2);
                }
                else if(v[len] == y){
                    printf("%d\n",tot);
                }
                else{ // ���λ��֮��Ŀ����б��޸ĺ�Ĵ�
                    if(v[len-1] < y){//��С�˵��Ǳ�ǰ��Ĵ󣬱�����һ��
                        int temp = tot;
                        int cnt = y;
                        int to = p[len+1]==0 ? n+1:p[len+1];
                        for(int i=p[len]+1;i<to;i++){
                            if(a[i] > cnt){
                                temp++,cnt = a[i];
                            }
                        }
                        printf("%d\n",temp);
                    }
                    else{//��С�˵��Ǳ�ǰ���С,
//                        printf("%d\n",tot-1);
                        int temp = tot-1;
                        int cnt = v[len-1];
                        int to = p[len+1]==0 ? n+1:p[len+1];
                        for(int i=p[len]+1;i<to;i++){
                            if(a[i] > cnt){
                                temp++,cnt = a[i];
                            }
                        }
                        printf("%d\n",temp);
                    }
                }
            }
            else{// ����޸ĵ�λ�ò��������е�
                if(v[len] >= y){
                    printf("%d\n",tot);
                }
                else{//�޸ĵ���������ǰ�����
                    int len2 = upper_bound(v+1,v+1+tot,y) - (v);// �ҵ��ϸ����y��λ�ã����λ�õ����Ǵ���y�ģ�����λ�������һ��
//                    tot++;// ����Ͷ��˸���
                    printf("%d\n",len + tot+1 +1 - len2);
                }
            }
        }
    }

    return 0;
}
/*

9
7 1
1 2 2 2 2 2 3
3 3

6 1
1 6 5 7 8 9
3 7

5 1
1 3 5 2 4
2 2

5 1
1 1 1 1 1
5 2

5 1
2 3 4 5 6
2 1

6 1
1 2 3 55 3 4
6 55

10 1
10 9 8 7 6 6 7 8 9 10
1 1
*/
