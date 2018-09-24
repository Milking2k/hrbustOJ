#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = (a); i<(n); i++)
#define per(i,a,n) for (int i = (n)-1; i>=(a); i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 1e9+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 2e5+7;
int T, n, m, k;
int blockNum = 0;
char chin[10][N];

char ch1[7][5] = {
    {'.', '.', '.', '.', 'x'},
    {'.', '.', '.', '.', 'x'},
    {'.', '.', '.', '.', 'x'},
    {'.', '.', '.', '.', 'x'},
    {'.', '.', '.', '.', 'x'},
    {'.', '.', '.', '.', 'x'},
    {'.', '.', '.', '.', 'x'},
};
char ch0[7][5] = {
    {'x', 'x', 'x', 'x', 'x'},
    {'x', '.', '.', '.', 'x'},
    {'x', '.', '.', '.', 'x'},
    {'x', '.', '.', '.', 'x'},
    {'x', '.', '.', '.', 'x'},
    {'x', '.', '.', '.', 'x'},
    {'x', 'x', 'x', 'x', 'x'},
};
char ch2[7][5] = {
'x','x','x','x','x' ,
'.','.','.','.','x' ,
'.','.','.','.','x' ,
'x','x','x','x','x' ,
'x','.','.','.','.' ,
'x','.','.','.','.' ,
'x','x','x','x','x', 
};
char ch3[7][5] = {
    {'x', 'x', 'x', 'x', 'x'},
    {'.', '.', '.', '.', 'x'},
    {'.', '.', '.', '.', 'x'},
    {'x', 'x', 'x', 'x', 'x'},
    {'.', '.', '.', '.', 'x'},
    {'.', '.', '.', '.', 'x'},
    {'x', 'x', 'x', 'x', 'x'},
};
char ch4[7][5] = {
'x','.','.','.','x' ,
'x','.','.','.','x' ,
'x','.','.','.','x' ,
'x','x','x','x','x' ,
'.','.','.','.','x' ,
'.','.','.','.','x' ,
'.','.','.','.','x' ,
};
char ch5[7][5] = {
'x','x','x','x','x' ,
'x','.','.','.','.' ,
'x','.','.','.','.' ,
'x','x','x','x','x' ,
'.','.','.','.','x' ,
'.','.','.','.','x' ,
'x','x','x','x','x' ,
};
char ch6[7][5] = {
'x','x','x','x','x', 
'x','.','.','.','.', 
'x','.','.','.','.', 
'x','x','x','x','x', 
'x','.','.','.','x', 
'x','.','.','.','x', 
'x','x','x','x','x', 
};
char ch7[7][5] = {
'x','x','x','x','x',
'.','.','.','.','x',
'.','.','.','.','x',
'.','.','.','.','x',
'.','.','.','.','x',
'.','.','.','.','x',
'.','.','.','.','x',
};
char ch8[7][5] = {
{'x','x','x','x','x' },
{'x','.','.','.','x' },
{'x','.','.','.','x' },
{'x','x','x','x','x' },
{'x','.','.','.','x' },
{'x','.','.','.','x' },
{'x','x','x','x','x'},
};
char ch9[7][5] = {
{'x','x','x','x','x' },
{'x','.','.','.','x' },
{'x','.','.','.','x' },
{'x','x','x','x','x' },
{'.','.','.','.','x' },
{'.','.','.','.','x' },
{'x','x','x','x','x' },
};
bool ispoint(int i, int j){
    return chin[i][j] == '.';
}
bool isx(int i, int j){
    return chin[i][j] == 'x';
}

int check(int col){
    if(ispoint(0,col) && ispoint(0,col+4)){
        return 10;
    }
    else if(ispoint(0,col) && isx(0,col+4)){
        return 1;
    }
    else if(ispoint(3,col) && ispoint(3,col+1)){
        return 7;
    }
    else if(ispoint(3,col+1)){
        return 0;
    }
    else if(ispoint(2,col) && ispoint(4,col+4)){
        return 2;
    }
    else if(ispoint(2,col)&&ispoint(4,col)){
        return 3;
    }
    else if(ispoint(0,col+1)){
        return 4;
    }
    else if(ispoint(2,col+4) && ispoint(4,col)){
        return 5;
    }
    else if(ispoint(2,col+4)){
        return 6;
    }
    else if(ispoint(4,col)){
        return 9;
    }
    else {
        return 8;
    }
}

int ans[10][N];

void mem(int y1,int y2){
    rep(i,0,7){
        rep(j,y1,y2+1){
            ans[i][j] = '.';
        }
    }
}

void drawIn(int x, int pos){
    // printf("test:%d %d\n", x, pos);
    if(x==0){
        rep(i,0,7)rep(j,pos,pos+5){
            ans[i][j] = ch0[i][j-pos];
        }
        // rep(i,0,7){
        //     rep(j,pos,pos+5){
        //         printf("%c", ans[i][j]);
        //     }
        //     puts("");
        // }
    }
    else if(x==1){
        rep(i,0,7)rep(j,pos,pos+5){
            ans[i][j] = ch1[i][j-pos];
        }
    }
    else if(x==2){
        rep(i,0,7)rep(j,pos,pos+5){
            ans[i][j] = ch2[i][j-pos];
        }
    }
    else if(x==3){
        rep(i,0,7)rep(j,pos,pos+5){
            ans[i][j] = ch3[i][j-pos];
        }
    }
    else if(x==4){
        rep(i,0,7)rep(j,pos,pos+5){
            ans[i][j] = ch4[i][j-pos];
        }
    }
    else if(x==5){
        rep(i,0,7)rep(j,pos,pos+5){
            ans[i][j] = ch5[i][j-pos];
        }
    }
    else if(x==6){
        rep(i,0,7)rep(j,pos,pos+5){
            ans[i][j] = ch6[i][j-pos];
        }
    }
    else if(x==7){
        rep(i,0,7)rep(j,pos,pos+5){
            ans[i][j] = ch7[i][j-pos];
        }
    }
    else if(x==8){
        rep(i,0,7)rep(j,pos,pos+5){
            ans[i][j] = ch8[i][j-pos];
        }
    }
    else if(x==9){
        rep(i,0,7)rep(j,pos,pos+5){
            ans[i][j] = ch9[i][j-pos];
        }
    }
}
void pt(ll x){
    int len = 0;
    int ptcnt[100];
    if(x==0){
        rep(i,0,7){
            rep(j,0,6-1){
                printf("%c", ch0[i][j]);
            }
            puts("");
        }
        return ;
    }
    while(x>0){
        ptcnt[len] = x % 10;
        len++;
        x /= 10;
    }
    // printf("%d\n", len);

    mem(0, len * 6 + 1);

    per(i,0,len){
        // printf("%d ", ptcnt[i]);
        drawIn(ptcnt[i],(len-1-i)*6);
    }
    rep(i,0,7){
        rep(j,0,len*6-1){
            printf("%c", ans[i][j]);
        }
        puts("");
    }
}
int main()
{
    // rep(i,0,7){
    //     rep(j,0,5){
    //         printf("%c", ch9[i][j]);
    //     }
    //     puts("");
    // }
    while(~scanf("%s",chin[0])){
        n = 7;
        rep(i,1,n){
            scanf("%s", chin[i]);
        }
        m = strlen(chin[0]);
        blockNum = (m + 1) / 6;

        ll num1=0, num2=0;
        bool ok = 0;
        rep(i,0,blockNum){
            int stk = 6 * i;
            int cnt = check(stk);
            // printf("cnt:%d", cnt);
            if(cnt==10){
                ok = 1;
            }
            else if(ok==0){
                num1 = num1 * 10 + cnt;
            }
            else {
                num2 = num2 * 10 + cnt;
            }
            // printf(" %lld %lld\n", num1, num2);
        }
        ll ans = num1 + num2;

        pt(ans);
    }
    return 0;
}
