#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
int b,n,e,tot;
int val[10];
int fc[N],ff[N];
struct node
{
    int val,a,b,c;
    bool operator <(const node& v) const {
        return val < v.val;
    }
}emt[10];

bool cmp(node aa,node bb)
{
    return aa.val<bb.val;
}
bool check(int val, int a, int b, int c)
{   
    for(int i=1;i<=tot;i++){
        ff[i] = val/fc[i];
        if(val % fc[i]) ff[i]++;
    }

    bool ok;
    for(int i=1;i<=tot;i++){
        ok = false;
        for(int j=1;j <= 6;j++){
            // printf("ff:%d emtj:%d\n",ff[i],emt[j].val);
            if(ff[i] <= emt[j].val && emt[j].a <= a && emt[j].b <= b && emt[j].c <= c){
                a -= emt[j].a;
                b -= emt[j].b;
                c -= emt[j].c;
                ok = true;
                break;
            }
        }
        if( !ok ) return false;
    }
    return true;
}

int main()
{
    while(cin >> b >> n >> e){
        cin >> val[1] >> val[2] >> val[3];
        emt[1] = (node){2*val[1],2,0,0};
        emt[2] = (node){2*val[2],0,2,0};
        emt[3] = (node){2*val[3],0,0,2};
        emt[4] = (node){val[1]+val[2],1,1,0};
        emt[5] = (node){val[1]+val[3],1,0,1};
        emt[6] = (node){val[2]+val[3],0,1,1};

        sort(emt+1,emt+6+1,cmp);
        // for(int i = 1;i<=6;i++){
        //     printf("%d %d %d %d\n",emt[i].val, emt[i].a, emt[i].b,emt[i].c);
        // }puts("");

        tot = (b+n+e)/2;
        for(int i=1;i<=tot;i++)cin >> fc[i];

        int l=0,r=1000000005,ans=0;
        // printf("%d\n",check(58,b,n,e));
        while(l<=r){
            int mid = (l+r)>>1;
            // printf("l:%d r:%d mid:%d\n",l,r,mid);
            if(check(mid,b,n,e)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
/*

24 0 1 1
15 1 0 1
11 1 1 0
28 0 0 2
20 0 2 0
2 2 0 0

l:0 r:1000000005 mid:500000002
l:0 r:500000001 mid:250000000
l:0 r:249999999 mid:124999999
l:0 r:124999998 mid:62499999
l:0 r:62499998 mid:31249999
l:0 r:31249998 mid:15624999
l:0 r:15624998 mid:7812499
l:0 r:7812498 mid:3906249
l:0 r:3906248 mid:1953124
l:0 r:1953123 mid:976561
l:0 r:976560 mid:488280
l:0 r:488279 mid:244139
l:0 r:244138 mid:122069
l:0 r:122068 mid:61034
l:0 r:61033 mid:30516
l:0 r:30515 mid:15257
l:0 r:15256 mid:7628
l:0 r:7627 mid:3813
l:0 r:3812 mid:1906
l:0 r:1905 mid:952
l:0 r:951 mid:475
l:0 r:474 mid:237
l:0 r:236 mid:118
l:0 r:117 mid:58
l:0 r:57 mid:28
l:29 r:57 mid:43
l:29 r:42 mid:35
l:29 r:34 mid:31
l:32 r:34 mid:33
l:34 r:34 mid:34


ff:2 emtj:2
ff:2 emtj:2
ff:2 emtj:11
ff:20 emtj:2
ff:20 emtj:11
ff:20 emtj:15
ff:20 emtj:20
ff:3 emtj:2
ff:3 emtj:11
ff:3 emtj:15
ff:3 emtj:20
ff:3 emtj:24
ff:3 emtj:28
*/