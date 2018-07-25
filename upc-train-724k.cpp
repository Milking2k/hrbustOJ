#include<bits/stdc++.h>
using namespace std;
struct node {
    int t,val;
    bool operator < (const node &a)const{
        if(a.t==t) return val>a.val;
        return t<a.t;
    }
}emt[100007];
priority_queue<int> Q;

int t,n,m;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&emt[i].t);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&emt[i].val);
    }

    sort(emt+1,emt+1+n);
    long long sum=0,cnt=0;
    for(int i=1;i<=n;i++){
//            printf("%d\n",emt[i].t);
//        if(emt[i].t >= i)
//            sum+=emt[i].val;
        Q.push(-emt[i].val);
//        printf("%d\n",-emt[i].val);
        sum+=emt[i].val;cnt++;
        while(emt[i].t < cnt) {
//            printf("qtop:%d\n",Q.top());
            sum+=Q.top();Q.pop();
            cnt--;
        }
    }
    printf("%lld\n",sum);
    return 0;
}


