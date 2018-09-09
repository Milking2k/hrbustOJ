#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int n,w,c[105],sum=0;
int main(){
    cin>>n>>w;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        sum+=c[i];
    }
    cout<<(sum+w-1)/w;
    return 0;
}

