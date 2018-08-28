<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
struct point
{
    int x,y;
}a[maxn];
struct node
{
    int l,r,sum;
}T[maxn*40],TT[maxn*40];
int cnt,res;
int root[maxn],root1[maxn];
vector<int> v;
vector<int> q;
int getid(int x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin();
}
int getid1(int x)
{
    return lower_bound(q.begin(),q.end(),x)-q.begin();
}
void update(int l,int r,int &x,int y,int pos)
{
    T[++cnt]=T[y],T[cnt].sum++,x=cnt;
    if(l==r)return ;
    int mid=(l+r)>>1;
    if(pos<=mid)update(l,mid,T[x].l,T[y].l,pos);
    else update(mid+1,r,T[x].r,T[y].r,pos);
}
void update1(int l,int r,int &x,int y,int pos)
{
    TT[++res]=TT[y],TT[res].sum++,x=res;
    if(l==r)return ;
    int mid=(l+r)>>1;
    if(pos<=mid)update(l,mid,TT[x].l,TT[y].l,pos);
    else update(mid+1,r,TT[x].r,TT[y].r,pos);
}
 
int query(int l,int r,int x,int y,int k)
{
    if(l==r)return l;
    int mid=(l+r)>>1;
    int now=T[T[y].l].sum-T[T[x].l].sum;
    if(k<=now)query(l,mid,T[x].l,T[y].l,k);
    else query(mid+1,r,T[x].r,T[y].r,k-now);
}
int query1(int l,int r,int x,int y,int k)
{
    if(l==r)return l;
    int mid=(l+r)>>1;
    int now=TT[TT[y].l].sum-TT[TT[x].l].sum;
    if(k<=now)query(l,mid,TT[x].l,TT[y].l,k);
    else query(mid+1,r,TT[x].r,TT[y].r,k-now);
}
 
 
int main()
{

    int n,m;cnt=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        v.push_back(a[i].x);
        q.push_back(a[i].y);
    }
 
    sort(v.begin(),v.end());
    sort(q.begin(),q.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    q.erase(unique(q.begin(),q.end()),q.end());
    for(int i=1;i<=n;i++){
        update(0,v.size()-1,root[i],root[i-1],getid(a[i].x));
        update(0,q.size()-1,root1[i],root1[i-1],getid1(a[i].y));
    }
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
 
        if(abs(y-x) <= 1){
            printf("0\n");
            continue;
        }

        ll mxx1 = v[query(0,v.size()-1,root[x-1],root[y],abs(x-y)+1)];
        ll mxx2 = v[query(0,v.size()-1,root[x-1],root[y],abs(x-y))];
        ll mnx1 = v[query(0,v.size()-1,root[x-1],root[y],1)];
        ll mnx2 = v[query(0,v.size()-1,root[x-1],root[y],2)];
 
        printf("%lld %lld %lld %lld\n",mxx1,mxx2,mnx1,mnx2);
        ll mxy1 = q[query(0,q.size()-1,root1[x-1],root1[y],abs(x-y)+1)];
        ll mxy2 = q[query(0,q.size()-1,root1[x-1],root1[y],abs(x-y))];
        ll mny1 = q[query(0,q.size()-1,root1[x-1],root1[y],1)];
        ll mny2 = q[query(0,q.size()-1,root1[x-1],root1[y],2)];
        printf("%lld %lld %lld %lld\n",mxy1,mxy2,mny1,mny2);
 
        ll ansx = min(abs(mxx2-mnx1), abs(mxx1-mnx2));
        ll ansy = min(abs(mxy2-mny1), abs(mxy1-mny2));

 
        printf("%lld %lld\n",ansx, ansy);
        printf("%lld\n",max(ansx, ansy));
 
//        printf("%d\n",v[query(0,v.size()-1,root[x-1],root[y],k)]);
//        printf("%d\n",q[query(0,q.size()-1,root1[x-1],root1[y],k)]);
 
    }
    return 0;
}

/*
5 11
34 0
19 24
28 8
12 14
5 45
2 3
2 2

=======
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
struct point
{
    int x,y;
}a[maxn];
struct node
{
    int l,r,sum;
}T[maxn*40],TT[maxn*40];
int cnt,res;
int root[maxn],root1[maxn];
vector<int> v;
vector<int> q;
int getid(int x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin();
}
int getid1(int x)
{
    return lower_bound(q.begin(),q.end(),x)-q.begin();
}
void update(int l,int r,int &x,int y,int pos)
{
    T[++cnt]=T[y],T[cnt].sum++,x=cnt;
    if(l==r)return ;
    int mid=(l+r)>>1;
    if(pos<=mid)update(l,mid,T[x].l,T[y].l,pos);
    else update(mid+1,r,T[x].r,T[y].r,pos);
}
void update1(int l,int r,int &x,int y,int pos)
{
    TT[++res]=TT[y],TT[res].sum++,x=res;
    if(l==r)return ;
    int mid=(l+r)>>1;
    if(pos<=mid)update(l,mid,TT[x].l,TT[y].l,pos);
    else update(mid+1,r,TT[x].r,TT[y].r,pos);
}
 
int query(int l,int r,int x,int y,int k)
{
    if(l==r)return l;
    int mid=(l+r)>>1;
    int now=T[T[y].l].sum-T[T[x].l].sum;
    if(k<=now)query(l,mid,T[x].l,T[y].l,k);
    else query(mid+1,r,T[x].r,T[y].r,k-now);
}
int query1(int l,int r,int x,int y,int k)
{
    if(l==r)return l;
    int mid=(l+r)>>1;
    int now=TT[TT[y].l].sum-TT[TT[x].l].sum;
    if(k<=now)query(l,mid,TT[x].l,TT[y].l,k);
    else query(mid+1,r,TT[x].r,TT[y].r,k-now);
}
 
 
int main()
{

    int n,m;cnt=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        v.push_back(a[i].x);
        q.push_back(a[i].y);
    }
 
    sort(v.begin(),v.end());
    sort(q.begin(),q.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    q.erase(unique(q.begin(),q.end()),q.end());
    for(int i=1;i<=n;i++){
        update(0,v.size()-1,root[i],root[i-1],getid(a[i].x));
        update(0,q.size()-1,root1[i],root1[i-1],getid1(a[i].y));
    }
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
 
        if(abs(y-x) <= 1){
            printf("0\n");
            continue;
        }

        ll mxx1 = v[query(0,v.size()-1,root[x-1],root[y],abs(x-y)+1)];
        ll mxx2 = v[query(0,v.size()-1,root[x-1],root[y],abs(x-y))];
        ll mnx1 = v[query(0,v.size()-1,root[x-1],root[y],1)];
        ll mnx2 = v[query(0,v.size()-1,root[x-1],root[y],2)];
 
        printf("%lld %lld %lld %lld\n",mxx1,mxx2,mnx1,mnx2);
        ll mxy1 = q[query(0,q.size()-1,root1[x-1],root1[y],abs(x-y)+1)];
        ll mxy2 = q[query(0,q.size()-1,root1[x-1],root1[y],abs(x-y))];
        ll mny1 = q[query(0,q.size()-1,root1[x-1],root1[y],1)];
        ll mny2 = q[query(0,q.size()-1,root1[x-1],root1[y],2)];
        printf("%lld %lld %lld %lld\n",mxy1,mxy2,mny1,mny2);
 
        ll ansx = min(abs(mxx2-mnx1), abs(mxx1-mnx2));
        ll ansy = min(abs(mxy2-mny1), abs(mxy1-mny2));

 
        printf("%lld %lld\n",ansx, ansy);
        printf("%lld\n",max(ansx, ansy));
 
//        printf("%d\n",v[query(0,v.size()-1,root[x-1],root[y],k)]);
//        printf("%d\n",q[query(0,q.size()-1,root1[x-1],root1[y],k)]);
 
    }
    return 0;
}

/*
5 11
34 0
19 24
28 8
12 14
5 45
2 3
2 2

>>>>>>> d2d85486aa24dc4cfd0bd17c48ed9f6c990960c3
*/