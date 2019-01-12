#include<bits/stdc++.h>
using namespace std;

int n;
__int64 gcd(__int64 a, __int64 b)
{
    if(a%b==0) return b;
    return gcd(b,a%b);
}

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        __int64 q,p,d;
        scanf("%I64d%I64d%I64d",&q,&p,&d);
        __int64 gcdnum = gcd(q,p);
        q/=gcdnum;
        p/=gcdnum;
//        printf("q:%I64d p:%I64d\n",q,p);
        if(p==1){printf("Finite\n");continue;}
        gcdnum = d;
        while (1) {
			gcdnum=gcd(p,gcdnum);
			if (gcdnum==1) break;
			p/=gcdnum;
		}
		puts(p==1?"Finite":"Infinite");
    }
    return 0;
}