#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int main()
{
    int n;
    char a[55],b[55];
    scanf("%d",&n);
    scanf("%s",a);
    scanf("%s",b);
    int p=0;
    ll sum=1;
    int i=0;
    if(a[0]==b[0]){
        sum=3;
        p=1;
        i=1;
    }
    else{
        sum=6;
        p=0;
        i=2;
    }
//    printf("%d\n",len);
    for(;i<n;i++){
        if(a[i]==b[i] && p==0){
            sum=sum*1%MOD;
            p=1;
        }
        else if(a[i]==b[i] && p==1){
            sum=sum*2%MOD;
            p=1;
        }
        else if(p==1){
            sum=sum*2%MOD;
            p=0;
            i++;
        }
        else{// p==0
            sum=sum*3%MOD;
            p=0;
            i++;
        }
//        printf("%d\n",sum);
    }
    return !printf("%lld\n",sum);
}
