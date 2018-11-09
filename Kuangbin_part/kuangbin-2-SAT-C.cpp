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
const double EPS = 1e-5;
int n,m;

/*2sat*/
const int MAXN = 20020;
const int MAXM = 100010;
struct Edge
{
    int to,next;
}edge1[MAXM],edge2[MAXM];
int head1[MAXN];
int head2[MAXN];
int tol1,tol2;
bool vis1[MAXN],vis2[MAXN];
int Belong[MAXN];//连通分量标记
int T[MAXN];//dfs结点结束时间
int Bcnt,Tcnt;
void add(int a,int b)//原图和逆图都要添加
{
    edge1[tol1].to=b;
    edge1[tol1].next=head1[a];
    head1[a]=tol1++;
    edge2[tol2].to=a;
    edge2[tol2].next=head2[b];
    head2[b]=tol2++;
}
void init()//建图前初始化
{
    memset(head1,-1,sizeof(head1));
    memset(head2,-1,sizeof(head2));
    memset(vis1,false,sizeof(vis1));
    memset(vis2,false,sizeof(vis2));
    tol1=tol2=0;
    Bcnt=Tcnt=0;
}
void dfs1(int x)//对原图进行dfs,算出每个结点的结束时间，哪个点开始无所谓
{
    vis1[x]=true;
    int j;
    for(int j=head1[x];j!=-1;j=edge1[j].next)
      if(!vis1[edge1[j].to])
        dfs1(edge1[j].to);
    T[Tcnt++]=x;
}
void dfs2(int x)
{
    vis2[x]=true;
    Belong[x]=Bcnt;
    int j;
    for(j=head2[x];j!=-1;j=edge2[j].next)
       if(!vis2[edge2[j].to])
         dfs2(edge2[j].to);
}

struct Point
{
    int x,y;
}s[MAXN];
double dist(Point a,Point b)
{
    return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool ok(int n)//判断可行性
{
    for(int i=0;i<2*n;i++)
      if(!vis1[i])
        dfs1(i);
    for(int i=Tcnt-1;i>=0;i--)
      if(!vis2[T[i]])//这个别写错，是vis2[T[i]]
      {
          dfs2(T[i]);
          Bcnt++;
      }
    for(int i=0;i<=2*n-2;i+=2)
      if(Belong[i]==Belong[i+1])
        return false;
    return true;
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    double left,right,mid;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
          scanf("%d%d%d%d",&s[2*i].x,&s[2*i].y,&s[2*i+1].x,&s[2*i+1].y);
        left=0;
        right=40000.0;
        while(right-left>=EPS)
        {
            mid=(left+right)/2;
            init();

            for(int i=0;i<2*n-2;i++)
            {
                int t;
                if(i%2==0)t=i+2;
                else t=i+1;
                for(int j=t;j<2*n;j++)
                   if(dist(s[i],s[j])<2*mid)//冲突了
                   {
                       add(i,j^1);
                       add(j,i^1);//注意顺序不能变的
                   }
            }
            if(ok(n))left=mid;
            else right=mid;
        }
        printf("%.2f\n",right);
    }
    return 0;
}