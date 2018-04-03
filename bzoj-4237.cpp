#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 200011;
int n,stack[MAXN],top,stack2[MAXN],tail;
LL ans;
struct node{ int x,y; }a[MAXN];
inline bool cmpx(node q,node qq){ return q.x<qq.x; }
inline bool cmpy(node q,node qq){ return q.y<qq.y; }

inline int getint(){
    int w=0,q=0; 
    char c=getchar(); 
    while((c<'0'||c>'9') && c!='-') c=getchar();
    if(c=='-') q=1,c=getchar(); 
    while (c>='0'&&c<='9') w=w*10+c-'0',c=getchar(); 
    return q?-w:w;
} 
inline void solve(int l,int r){
    if(l==r) return ; sort(a+l,a+r+1,cmpy); int mid=(l+r)>>1;
    sort(a+l,a+mid+1,cmpx);//down
    sort(a+mid+1,a+r+1,cmpx);//up
    top=tail=0; int now=l,L,R,pos,mm,cp;
    for(int i=mid+1;i<=r;i++) {
        while(top>0 && a[stack[top]].y>=a[i].y) top--;
        stack[++top]=i;
 
        while(now<=mid && a[now].x<a[i].x) {
            while(tail>0 && a[stack2[tail]].y<=a[now].y) tail--;
            stack2[++tail]=now;
            now++;
        }
 
        L=1; R=tail; pos=-1; cp=a[stack[top-1]].x;
        while(L<=R) {
            mm=(L+R)>>1;
            if(a[stack2[mm]].x>cp) pos=mm,R=mm-1;
            else L=mm+1;
        }
        if(pos!=-1) ans+=tail-pos+1;
    }
    solve(l,mid); solve(mid+1,r);
}
 
inline void work(){
    n=getint(); for(int i=1;i<=n;i++) a[i].x=getint(),a[i].y=getint();
    a[0].x=a[0].y=-1;
    solve(1,n);
    printf("%lld",ans);
}
 
int main()
{
    work();
    return 0;
}