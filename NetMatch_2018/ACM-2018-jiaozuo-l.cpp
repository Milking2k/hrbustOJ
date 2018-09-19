#include <bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
const int maxn=1e5+7;
const LL MOD=1e9+7;
struct mat{
    long long a[30][30];
    int r,c;
    mat operator *(const mat &b)const{
        mat ret;
        for (int i=0;i<r;i++){
            for (int j=0;j<b.c;j++){
                ret.a[i][j]=0;
                for (int k=0;k<c;k++)
                    ret.a[i][j]+=a[i][k]*b.a[k][j],ret.a[i][j]%=MOD;
            }
        }
        ret.r=r;
        ret.c=b.c;
        return ret;
    }
    mat init_unit(int x)
    {
        r=c=x;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==j)a[i][j]=1;
                else a[i][j]=0;
            }
        }
    }
}unit;

mat pow(mat p,LL n){
    unit.init_unit(9);
    mat ans=unit;
    while(n){
        if(n&1)ans=p*ans;
        p=p*p;
        n>>=1;
    }
    return ans;
}
int main()
{
    int T;
    read(T);
    while(T--) {
        LL n;
        scanf("%lld",&n);
        mat A;
        A.r=A.c=9;
        A.a[0][0]=0,A.a[0][1]=0,A.a[0][2]=0,A.a[0][3]=1,A.a[0][4]=0,A.a[0][5]=0,A.a[0][6]=1,A.a[0][7]=0,A.a[0][8]=0;
        A.a[1][0]=1,A.a[1][1]=0,A.a[1][2]=0,A.a[1][3]=1,A.a[1][4]=0,A.a[1][5]=0,A.a[1][6]=1,A.a[1][7]=0,A.a[1][8]=0;
        A.a[2][0]=1,A.a[2][1]=0,A.a[2][2]=0,A.a[2][3]=1,A.a[2][4]=0,A.a[2][5]=0,A.a[2][6]=0,A.a[2][7]=0,A.a[2][8]=0;
        A.a[3][0]=0,A.a[3][1]=1,A.a[3][2]=0,A.a[3][3]=0,A.a[3][4]=1,A.a[3][5]=0,A.a[3][6]=0,A.a[3][7]=1,A.a[3][8]=0;

        A.a[4][0]=0,A.a[4][1]=1,A.a[4][2]=0,A.a[4][3]=0,A.a[4][4]=0,A.a[4][5]=0,A.a[4][6]=0,A.a[4][7]=1,A.a[4][8]=0;
        A.a[5][0]=0,A.a[5][1]=1,A.a[5][2]=0,A.a[5][3]=0,A.a[5][4]=1,A.a[5][5]=0,A.a[5][6]=0,A.a[5][7]=0,A.a[5][8]=0;

        A.a[6][0]=0,A.a[6][1]=0,A.a[6][2]=1,A.a[6][3]=0,A.a[6][4]=0,A.a[6][5]=0,A.a[6][6]=0,A.a[6][7]=0,A.a[6][8]=1;
        A.a[7][0]=0,A.a[7][1]=0,A.a[7][2]=0,A.a[7][3]=0,A.a[7][4]=0,A.a[7][5]=1,A.a[7][6]=0,A.a[7][7]=0,A.a[7][8]=1;
        A.a[8][0]=0,A.a[8][1]=0,A.a[8][2]=1,A.a[8][3]=0,A.a[8][4]=0,A.a[8][5]=1,A.a[8][6]=0,A.a[8][7]=0,A.a[8][8]=0;
        if(n==1){
            printf("3\n");
            continue;
        }
        if(n==2){
            printf("9\n");
            continue;
        }
        mat ans;
        ans=pow(A,n-2);
        mat tmp;
        tmp.r=1;tmp.c=9;
        for(int i=0;i<9;i++){
            tmp.a[0][i]=1;
        }
        ans=tmp*ans;
        LL aaaa=0;
        for(int i=0;i<9;i++){
            aaaa+=ans.a[0][i];
            aaaa%=MOD;
        }
        printf("%lld\n",aaaa);
    }
    return 0;
}
/*
1
3
*/