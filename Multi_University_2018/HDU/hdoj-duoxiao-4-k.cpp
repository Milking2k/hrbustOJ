#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn=1e5+5;
int a[maxn];
char s[maxn];
char ss[maxn];
int main() {
    int T;
    read(T);
    while(T--) {
        scanf("%s",s);
        int l=strlen(s);
        int F=1;
        strcpy(ss,s);
        if(s[0]=='?') s[0]='1';
        for(int i=0;i<l;i++) {              /**     0?0?0    */
            if(s[i-1]=='0' && s[i]=='?' && i>=1) {
                int id=i-1;
                while(s[id]=='0'&&id>0) {
                    id--;
                }
                if(id==0&&i-id!=1&&s[id]=='0') {
                    F=0;
                    break;
                }
                else if(id==0&&i-id==1&&s[id]=='0')s[i]='+';

                if(id!=0&&i-id==2&&(s[id]=='+' || s[id]=='*'))s[i]='+';
                else if(id!=0&&i-id==2&&(s[id]>='1' || s[id]<=9))s[i]='1';
                else if(id!=0&&i-id!=2&&(s[id]=='+' || s[id]=='*')) {
                    F=0;
                    break;
                }

                if((s[id]>='1'&&s[id]<='9'))s[i]='1';
                else if(s[id]=='?')s[i]='1';
            }
            else if(s[i]=='?')s[i]='1';
        }
        //cout<<F<<endl;
        //puts("");
        int index=0;
        int f=1;
        for(int i=0;i<l;i++) {
            if(f==0) {
                if(s[i]=='+' || s[i]=='*') {
                    F=0;
                }
                else {
                    index=i;
                    f=1;
                }
            }
            if(s[i]=='+' || s[i]=='*') {
                if(s[index]!='0' && index!=i-1) {
                    f=0;
                    continue;
                }
                else if(index==i-1) {
                    f=0;
                    continue;
                }
                else {
                    F=0;
                }
            }
        }
        if(s[l-1]=='+' || s[l-1]=='*') F=0;
        if(s[0]=='+' || s[0]=='*') F=0;
        else {
            if(index!=l-1) {
                if(s[index]=='0')F=0;
            }
        }
        //printf("%s\n",s);
        if(F==0)puts("IMPOSSIBLE");
        else printf("%s\n",s);
    }
}
