#include <bits/stdc++.h>
using namespace std;
char a[105],b[105];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        string as="";
        scanf("%s %s",a,b);
        int lenb=strlen(b);
        int lena=strlen(a);
        for(int i=0;i<lenb;i++){
            if(i==0){
                as+=toupper(b[i]);
            }
            else{
                as+=b[i];
            }
        }
        for(int i=0;i<lena;i++){
            as+=a[i];
        }
        cout<<as<<endl;
    }
    return 0;
}