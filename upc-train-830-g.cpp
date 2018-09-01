#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define fi first
#define se second
const int N = 1e5 + 7;

int n, m;
int bit[N];
pair<int, int> op[N];
int onecg[N],tot=0;
int qusNum[N],qusPay[N],totPay[N];
void add(int x, int v)
{
    x++;
    while(x<N){
        bit[x] += v;
        x += x&-x;
    }
}

int getsum(int x)
{
    x++;
    int res=0;
    while(x){
        res += bit[x];
        x -= x&-x;
    }
    return res;
}

int main()
{

    while(cin >> n >> m){
        int tot =0;
        onecg[0] = 0;
        rep(i,1,m+1){
            cin >> op[i].fi >> op[i].se;
            if(op[i].fi == 1){
                onecg[++tot] = onecg[tot-1] + op[i].se;
            }
        }
        memset(qusNum,0,sizeof(qusNum));
        memset(bit,0,sizeof(bit));
        memset(totPay,0,sizeof(totPay));
        memset(qusPay,0,sizeof(qusPay));

        add(0,n);
        rep(i,1,m+1) {
            if(op[i].fi==1)
                qusNum[1]++;
            else
            {
                add(qusNum[op[i].fi],-1);
                if(onecg[qusNum[op[i].fi]]>totPay[op[i].fi])
                    qusPay[qusNum[op[i].fi]]--;
                qusNum[op[i].fi]++;
                totPay[op[i].fi]+=op[i].se;
                add(qusNum[op[i].fi],1);
                if(onecg[qusNum[op[i].fi]]>totPay[op[i].fi])
                    qusPay[qusNum[op[i].fi]]++;
            }
            printf("%d\n",n-getsum(qusNum[1])+qusPay[qusNum[1]]+1);
        }
    }
    return 0;
}