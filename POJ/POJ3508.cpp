// #include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>
using namespace std;
#define rep(i,a,n) for (int i = a; i<n; i++)
#define per(i,a,n) for (int i = n-1; i>=a; i--)
// #define pb push_back
// #define mp make_pair
// #define all(now) (now).begin(),(now).end()
// #define fi first
// #define se second
// #define SZ(now) ((int)(now).size())
// typedef vector<int> VI;
// typedef long long ll;
// typedef pair<int,int> PII;
// const ll mod = 1000000007;
// inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
// ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
// ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
const int N = 1e5+7;
int T=0,n,m;
string a;
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while(cin >> a && a[0]!='0'){
        printf("%d. ", ++T);
        int len = a.length();
        if(len==1){
            printf("%c\n", a[0]);
        }
        else{
            int carry = 0;
            per(i,0,len-1){
                int tmp = a[i] - carry - a[i + 1];
                if (tmp < 0){
                    a[i] = tmp + 10 + '0';
                    carry = 1;
                }
                else{
                    a[i] = tmp + '0';
                    carry = 0;
                }
            }
            if(a[0]=='0'){
                printf("IMPOSSIBLE\n");
            }
            else{
                cout << a << endl;
            }
        }
    }
    return 0;
}