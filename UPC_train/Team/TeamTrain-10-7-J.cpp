#include <bits/stdc++.h>
using namespace std;

const int maxn=1e3+7;
const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}
struct point
{
    double x,y;
    point() {}
    point(double _x,double _y)
    {
        x = _x;y = _y;
    }
    point operator -(const point &b)const
    {
        return point(x - b.x,y - b.y);
    }
    double operator ^(const point &b)const
    {
        return x*b.y - y*b.x;
    }
    double operator *(const point &b)const
    {
        return x*b.x + y*b.y;
    }
    void sc()
    {
        scanf("%lf%lf",&x,&y);
    }
};
struct Line
{
    point s,e;
    Line() {}
    Line(point _s,point _e)
    {
        s = _s;
        e = _e;
    }
    pair<int,point> operator &(const Line &b)const
    {
        point res = s;
        if(sgn((s-e)^(b.s-b.e)) == 0){
            if(sgn((s-b.e)^(b.s-b.e)) == 0)
                return make_pair(0,res);
            else return make_pair(1,res);
        }
        double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
        res.x += (e.x-s.x)*t;
        res.y += (e.y-s.y)*t;
        return make_pair(2,res);
    }
};
double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
point PointToLine(point P,Line L)
{
    point result;
    double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
//    printf("fuck %lf %lf\n",L.e,L.s);
    result.x = L.s.x + (L.e.x-L.s.x)*t;
    result.y = L.s.y + (L.e.y-L.s.y)*t;
    return result;
}
point p[maxn];
double r[maxn];
Line l1,l2;
int n;

const int maxm=2e6+7;
int cnt;
struct node
{
    int from,to,next;
    double val;
}edge[maxm<<1];
int head[maxm];
double dis[maxn];
int vis[maxn];
struct Node
{
    int id;
    double val;
    bool operator <(const Node &b)const
    {
        if(val==b.val)return id<b.id;
        return val>b.val;
    }
};
void init()
{
    memset(head,-1,sizeof(head));
    cnt=1;
}
void addedge(int from,int to,double val)
{
    edge[cnt].from=from;
    edge[cnt].to=to;
    edge[cnt].val=val;
    edge[cnt].next=head[from];
    head[from]=cnt++;
}
void dijkstra(int s,int e)
{
    memset(vis,0,sizeof(vis));
//    memset(dis,0x7f,sizeof(dis));
    for(int i=0;i<=n+2;i++)dis[i]=9999999999999.0;
    Node now;
    priority_queue<Node>q;
    while(q.size())q.pop();
    now.val=0,now.id=s;
    dis[s]=0;
    q.push(now);
    while(!q.empty()){
        Node u=q.top();
        q.pop();
        if(vis[u.id])continue;
        vis[u.id]=1;
        for(int i=head[u.id];i!=-1;i=edge[i].next){
            int to=edge[i].to;
            if(dis[u.id]+edge[i].val<dis[to]){
                dis[to]=dis[u.id]+edge[i].val;
                Node pus;
                pus.id=to,pus.val=dis[to];
                q.push(pus);
            }
        }
    }
    return ;
}


void solve1(int z,double r1,int x,double r2)
{
    point a=p[z],b=p[x];
    double as=dist(a,b);
    as-=r1;as-=r2;
//    printf("test1 %d %.4f %d %.4f dis==%.4f\n",z,r1,x,r2,as);
    if(as<=0){
        addedge(z,x,0);
        addedge(x,z,0);
    }
    else{
        addedge(z,x,as);
        addedge(x,z,as);
    }
}
void solve2(int x,point a,double r)
{
    point qw=PointToLine(a,l1);
    double as=dist(a,qw);
    as-=r;
//    printf("test2 %d %.4f dis==%.4f %lf %lf %lf %lf\n",x,r,as,qw.x,qw.y,a.x,a.y);
    if(as<=0){
        addedge(0,x,0);
        addedge(x,0,0);
    }
    else{
        addedge(0,x,as);
        addedge(x,0,as);
    }
}
void solve3(int x,point a,double r)
{
    point qw=PointToLine(a,l2);
    double as=dist(a,qw);
    as-=r;
//    printf("test3 %d %.4f dis==%.4f %lf %lf %lf %lf\n",x,r,as,qw.x,qw.y,a.x,a.y);
    if(as<=0){
        addedge(n+1,x,0);
        addedge(x,n+1,0);
    }
    else{
        addedge(n+1,x,as);
        addedge(x,n+1,as);
    }
}
int main()
{
    double A,B,c1,c2;
    scanf("%d%lf%lf%lf%lf",&n,&A,&B,&c1,&c2);
    for(int i=1;i<=n;i++){
        p[i].sc();
        scanf("%lf",&r[i]);
    }
    point p1,q1,p2,q2;
    if(A==0){
        p1=point(0.0,-c1/B);
        q1=point(1.0,-c1/B);

        p2=point(0.0,-c2/B);
        q2=point(1.0,-c2/B);
    }
    else if(B==0){
        p1=point(-c1/A,0.0);
        q1=point(-c1/A,1.0);

        p2=point(-c2/A,0.0);
        q2=point(-c2/A,1.0);
    }
    else{
        p1=point(0.0,-1.0*c1/B);
        q1=point(-1.0*c1/A,0.0);

        p2=point(0.0,-1.0*c2/B);
        q2=point(-1.0*c2/A,0.0);
    }
    l1=Line(p1,q1);
    l2=Line(p2,q2);
    init();
    int S=0,T=n+1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            solve1(i,r[i],j,r[j]);
        }
    }
    for(int i=1;i<=n;i++){
        solve2(i,p[i],r[i]);
    }
    for(int i=1;i<=n;i++){
        solve3(i,p[i],r[i]);
    }
    dijkstra(0,n+1);
    printf("%.7f\n",dis[n+1]);
    return 0;
}
