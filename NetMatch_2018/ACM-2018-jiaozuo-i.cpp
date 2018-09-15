#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;

int main() {
    int a,b,c;
    while(cin>>a>>b>>c) {
        if(a%2==0 || b%2==0 || c%2==0) {
            puts("Yes");
        }
        else puts("No");

    }
}