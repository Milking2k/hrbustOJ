#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int a[55];
int b[55];
bool ok;
void solve()
{
    for(int i=1;i<=24;i++){
        b[i]=a[i];
    }
}
bool check()
{
    bool as=true;
    for(int i=0;i<6;i++){
        if(b[i*4+1]==b[i*4+2]&&
           b[i*4+2]==b[i*4+3]&&
           b[i*4+3]==b[i*4+4])continue;
        else {
            as=false;break;
        }
    }
    return as;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        ok=false;
        for(int i=1;i<=24;i++){
            scanf("%d",&a[i]);
        }
        solve();
        ok=check();
        if(ok){
            printf("YES\n");continue;
        }
        ///68-24
        solve();
        b[2]=a[6];b[4]=a[8];
        b[6]=a[10];b[8]=a[12];
        b[10]=a[14];b[12]=a[16];
        b[14]=a[2];b[16]=a[4];
        ok=check();
        if(ok){
            printf("YES\n");continue;
        }

        ///24-68
        solve();
        b[12]=a[8];b[10]=a[6];
        b[16]=a[12];b[14]=a[10];
        b[2]=a[14];b[4]=a[16];
        b[6]=a[2];b[8]=a[4];
        ok=check();
        if(ok){
            printf("YES\n");continue;
        }

        ///57-13
        solve();
        b[1]=a[5];b[3]=a[7];
        b[5]=a[9];b[7]=a[11];
        b[9]=a[13];b[11]=a[15];
        b[13]=a[1];b[15]=a[3];
        ok=check();
        if(ok){
            printf("YES\n");continue;
        }

        ///13-57
        solve();
        b[5]=a[1];b[7]=a[3];
        b[9]=a[5];b[11]=a[7];
        b[13]=a[9];b[15]=a[11];
        b[1]=a[13];b[3]=a[15];
        ok=check();
        if(ok){
            printf("YES\n");continue;
        }

        ///56-18 20
        solve();
        b[18]=a[5];b[20]=a[6];
        b[5]=a[23];b[6]=a[21];
        b[23]=a[16];b[21]=a[15];
        b[16]=a[18];b[15]=a[20];
        ok=check();
        if(ok){
            printf("YES\n");continue;
        }

        ///18 20-56
        solve();
        b[16]=a[23];b[15]=a[21];
        b[18]=a[16];b[20]=a[15];
        b[5]=a[18];b[6]=a[20];
        b[23]=a[5];b[21]=a[6];
        ok=check();
        if(ok){
            printf("YES\n");continue;
        }

        ///78-17 19
        solve();
        b[17]=a[7];b[19]=a[8];
        b[7]=a[24];b[8]=a[22];
        b[24]=a[14];b[23]=a[13];
        b[14]=a[17];b[13]=a[19];
        ok=check();
        if(ok){
            printf("YES\n");continue;
        }

        ///17 19-78
        solve();
        b[7]=a[17];b[8]=a[19];
        b[24]=a[7];b[22]=a[8];
        b[14]=a[24];b[13]=a[22];
        b[17]=a[14];b[19]=a[13];
        ok=check();
        if(ok){
            printf("YES\n");continue;
        }

        ///43-24 23
        solve();
        b[24]=a[4];b[23]=a[3];
        b[4]=a[20];b[3]=a[19];
        b[20]=a[9];b[19]=a[10];
        b[9]=a[24];b[10]=a[23];
        ok=check();
        if(ok){
            printf("YES\n");continue;
        }

        ///24 24-43
        solve();
        b[4]=a[24];b[3]=a[23];
        b[20]=a[4];b[19]=a[3];
        b[9]=a[20];b[10]=a[19];
        b[24]=a[9];b[23]=a[10];
        ok=check();
        if(ok){
            printf("YES\n");continue;
        }

        ///21-22 21
        solve();
        b[21]=a[1];b[22]=a[2];
        b[12]=a[21];b[11]=a[22];
        b[17]=a[12];b[18]=a[11];
        b[1]=a[17];b[2]=a[18];
        ok=check();
        if(ok){
            printf("YES\n");continue;
        }

        ///22 21-21
        solve();
        b[1]=a[21];b[2]=a[22];
        b[18]=a[2];b[17]=a[1];
        b[11]=a[18];b[12]=a[17];
        b[21]=a[12];b[23]=a[12];
        ok=check();
        if(ok){
            printf("YES\n");continue;
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}