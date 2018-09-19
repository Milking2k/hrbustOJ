#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

string aa="Jessie";
string a="jessie";

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        string aaa;
        cin>>aaa;
        int len=aaa.size();
        for(int i=0;i<len;i++){
            if('A'<=aaa[i]&&aaa[i]<='Z'){
                aaa[i]-='A';
                aaa[i]+='a';
            }
        }
        if(aaa==aa||aaa==a){
            puts("Good guy!");
        }
        else{
            puts("Dare you say that again?");
        }
    }
    return 0;
}