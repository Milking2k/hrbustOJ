/*
主席树+倍增LCS
*/

#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define ll long long
using namespace std;
inline int read(){
    int x=0;char ch=' ';int f=1;
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')f=-1,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
struct edge{
    int to,next;
}e[320001];
int T,n,m,q,tot;
int a[80001];
int fa[80001];
int son[80001];
int head[80001];
inline void addedge(int x,int y){
    e[++tot].to=y;e[tot].next=head[x];head[x]=tot;
}
struct Node{
    int size,ls,rs;
}t[80001*600];
int cnt;
int root[80001];
void build(int &now,int l,int r){
    now=++cnt;
    t[now].size=0;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(t[now].ls,l,mid);
    build(t[now].rs,mid+1,r);
}
void insert(int &now,int pre,int l,int r,int x){
    now=++cnt;
    t[now]=t[pre];
    t[now].size++;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(x<=mid)insert(t[now].ls,t[pre].ls,l,mid,x);
    else insert(t[now].rs,t[pre].rs,mid+1,r,x);
}
int b[80001];
int size;
int query(int x,int y,int pre1,int pre2,int l,int r,int k){
    if(l==r)return b[l];
    int lsize=t[t[x].ls].size+t[t[y].ls].size-t[t[pre1].ls].size-t[t[pre2].ls].size;
    int mid=(l+r)>>1;
    if(k<=lsize)return query(t[x].ls,t[y].ls,t[pre1].ls,t[pre2].ls,l,mid,k);
    else return query(t[x].rs,t[y].rs,t[pre1].rs,t[pre2].rs,mid+1,r,k-lsize);
}
inline int Hash(int x){
    return lower_bound(b+1,b+size+1,x)-b;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int st[80001][17];
int dep[80001];
int vis[80001];
void dfs(int x,int father,int rt){
    st[x][0]=father;
    for(int k=1;k<=16;k++){
        st[x][k]=st[st[x][k-1]][k-1];
    }
    son[rt]++;
    dep[x]=dep[father]+1;
    fa[x]=father;
    vis[x]=1;
    insert(root[x],root[father],1,size,Hash(a[x]));
    for(int i=head[x];i;i=e[i].next){
        int u=e[i].to;
        if(u==father)continue;
        dfs(u,x,rt);
    }
}
inline int getlca(int x,int y){
    if(x==y)return x;
    if(dep[x]>dep[y])swap(x,y);
    for(int k=16;k>=0;k--){
        if(dep[st[y][k]]>=dep[x]){
            y=st[y][k];
        }
    }
    if(x==y)return x;
    for(int k=16;k>=0;k--){
        if(st[x][k]!=st[y][k]){
            x=st[x][k];
            y=st[y][k];
        }
    }
    return st[x][0];
}
int main(){
    T=read();
    T=1;
    while(T--){
        memset(head,0,sizeof(head));
        memset(dep,0,sizeof(dep));
        memset(vis,0,sizeof(vis));
        memset(st,0,sizeof(st));
        memset(son,0,sizeof(son));
        tot=0;
        cnt=0;
        n=read();m=read();q=read();
        for(int i=1;i<=n;i++){
            a[i]=read();
            b[i]=a[i];
            fa[i]=i;
        }
        sort(b+1,b+n+1);
        size=unique(b+1,b+n+1)-b-1;
        for(int i=1;i<=m;i++){
            int x=read(),y=read();
            addedge(x,y);addedge(y,x);
        }
        build(root[0],1,size);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,0,i);
                fa[i]=i;
            }
        }
        int lastans=0;
        for(int i=1;i<=q;i++){
            char ch[3];
            int x,y,k;
            scanf("%s",ch);
            x=read()^lastans;
            y=read()^lastans;
            if(ch[0]=='Q'){
                k=read()^lastans;
                int lca=getlca(x,y);
                lastans=query(root[x],root[y],root[lca],root[st[lca][0]],1,size,k);
                printf("%d\n",lastans);
            }
            else{
                addedge(x,y);
                addedge(y,x);
                int u=find(x);
                int v=find(y);
                if(son[u]<son[v]){
                    swap(u,v);
                    swap(x,y);
                }
                dfs(y,x,u);
            }
        }
    }
    return 0;
}