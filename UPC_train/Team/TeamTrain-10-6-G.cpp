#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn=1e5+4;
char s[maxn];
int star[30]={0,5,5,5,5,5,5,5,5,5,5,4,4,4,4,4,3,3,3,3,3,2,2,2,2,2};


int main() {
    cin>>s;
    int l=strlen(s);
    int L=25;
    int win=0;
    int stars=0;
    int idx=25;
    for(int i=0;i<l;i++) {
        if(s[i]=='W') {
            win++;
            stars++;
            if(win>=3  &&  idx>=6)stars++;
            if(stars>star[idx]) {
                stars-=star[idx];
                idx--;
            }
        }
        else {
            win=0;
            if(idx<=20)stars--;
            if(stars<0) {
//                idx=min(idx+1,20);
                idx++;
                if(idx==21)stars=0,idx=20;
                else {
                    stars=star[idx]-1;
                }
            }
        }
        if(idx<1)break;
    }
    if(idx>0)cout<<idx<<endl;
    else puts("Legend");
}
