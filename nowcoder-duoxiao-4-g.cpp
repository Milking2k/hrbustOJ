#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn=1e5+5;
map<int,int>mp;
struct node{
    int x,num;
    int sum;
}d[maxn];
int c[maxn];
int lowbit(int x) {
    return x&(-x);
}
int getsum(int x) {
    int sum=0;
    while(x >0) {
        sum+=c[x];
    }
    return sum;
}
void add(int x,int i) {
    while(x<maxn) {
        c[x]+=i;
        x+=lowbit(x);
    }
}
bool cmp(node a,node b) {
    if(a.num != b.num) return a.num>b.num;
    else return a.x<b.x;
}
int a[maxn];
int main() {
    int T;
    read(T);
    while(T--) {
        int n,m;
        read(n);
        read(m);
        memset(d,0,sizeof(d));
        mp.clear();
        for(int i=1;i<=n;i++) {
            read(a[i]);
            mp[a[i]]++;
        }
        map<int,int>::iterator it;
        int cnt=0;
        for(it=mp.begin();it!=mp.end();it++) {
            d[++cnt].x=it->first;
            d[cnt].num=it->second;
        }
        sort(d+1,d+1+cnt,cmp);
        //cout<<cnt<<endl;
        int ss=0;
        for(int i=1;i<=cnt;i++) {
            d[i].sum+=ss;
            ss+=d[i].num;
            //cout<<d[i].num<<" "<<d[i].x<<" "<<d[i].sum<<endl;
        }
        int ans=-1;
        for(int i=1;i<=cnt;i++) {
            if(d[i].x < d[i+1].x && d[i].num == d[i+1].num) {
                continue;
            }
            int nn=d[i].sum;
            nn=nn-(i-1)*(d[i].num-1);
            //printf("%d nn:%d d[]:%d\n",i,nn,d[i].num-1);
            //cout<<nn<<" "<<m<<endl;
            if(nn<=m) {
                ans=max(ans,d[i].x);
            }
        }
        printf("%d\n",ans);
    }
}
