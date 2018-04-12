#include<bits/stdc++.h>
#define debug puts("&&&&&&&&")
#define read(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
 
int main() {
    int n,x;
    while(read(n) != EOF) {
        read(x);
        //cout<<2*n-1<<endl;
        if(x>1 && x<2*n-1) {
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
    }
}