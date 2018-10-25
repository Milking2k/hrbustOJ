#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,d;

int main()
{
    scanf("%d%d",&n,&d);
    if(d>n-1)d=n-1;
    if(n==0||d==0){
        printf("0\n");
    }
    else if(n-1-d==0){
        printf("%lld\n",(ll)pow(2,n-1)-1);
    }
    else{
        vector<ll>ans;
        for(int i=1;i<=d+1;i++){
            ans.push_back(i);
        }
        int pos=0;
        int times=130;
        while(times--){
            ll cnt = ans.back();
            ans.push_back(cnt+ans[pos]+1);
            pos++;
        }
        printf("%lld\n",(ll)pow(2,n-1)-ans[n-1-d-1]-1);
    }


    return 0;
}
