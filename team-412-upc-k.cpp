#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n,a[105],maxs=0,num[105];
int limi;
bool fail;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        maxs = max(a[i],maxs);
        num[a[i]]++;
    }
    if (maxs&1)
    {
        limi = ((maxs+1)>>1);
        for (int i = 0; i < limi; ++i)
        {
            if(num[i]) fail = true;
        }
        if(num[limi]!=2) fail = true;
        for (int i = limi+1; i <= maxs; ++i)
        {
            if(num[i]<2) fail = true;
        }
    }
    else
    {
        limi = (maxs>>1);
        for (int i = 0; i < limi; ++i)
        {
            if(num[i]) fail = true;
        }
        if(num[limi]!=1) fail = true;
        for (int i = limi+1; i <= maxs; ++i)
        {
            if(num[i]<2) fail = true;
        }
    }
    puts(fail?"Impossible":"Possible");

    return 0;
}