#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define ll long long int

const int MAX = 100007;
int n,q;
int emt[MAX];
int L[MAX];
int R[MAX];
int X[MAX];

ll bit0[MAX],bit1[MAX];

ll sum(ll *b, int i)
{
    ll s=0;
    while(i>0)
    {
        s+=b[i];
        i-=i&-i;
    }
    return s;
}
void add(ll *b, int i, int v)
{
    while(i<=n)
    {
        b[i] += v;
        i += i&-i;
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&emt[i]);
        add(bit0, i, emt[i]);
    }
    for(int i=0;i<q;i++)
    {
        char c[5];
        int op1,op2;
        scanf("%s %d %d",&c,&op1,&op2);
        if(c[0]=='C')
        {
            int val;
            scanf("%d",&val);
            add(bit0, op1, -val*(op1-1));
            add(bit1, op1, val);
            add(bit0, op2+1, val*op2);
            add(bit1, op2+1, -val);
        }
        else
        {
            ll res=0;
            res += sum(bit0,op2) + sum(bit1, op2) * op2;
            res -= sum(bit0, op1-1) + sum(bit1, op1-1) * (op1-1);
            printf("%lld\n",res);
        }
    }
    return 0;
}
