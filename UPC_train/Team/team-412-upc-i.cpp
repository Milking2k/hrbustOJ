#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
 
char stk[maxn];
int top;
 
int main()
{
    string a;
    while(cin>>a){
        top=0;
        int len=a.size();
        for(int i=0;i<len;i++){
            if(a[i]=='T'&&stk[top-1]=='S'){
                top--;
            }
            else stk[top++]=a[i];
        }
        printf("%d\n",top);
    }
    return 0;
}