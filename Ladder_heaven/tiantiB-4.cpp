#include<bits/stdc++.h>
using namespace std;
#define rd(x) scanf("%d",&x)
#define r1d(x) scanf("%1d",&x)
#define rdd(x,y) scanf("%d%d",&x,&y)
#define rddd(x,y,z) scanf("%d%d",&x,&y,&z)
#define ll long long int

int n;
int pos;
int top;


int main()
{
	// freopen("in.txt","r",stdin);
    rd(n);
    string s1;
    string s2;
    pos=1;
    cin >> s1;
    for (int i = 2; i <= n; ++i)
    {
        cin >> s2;
        if(s1.length() < s2.length()) pos=i,s1=s2;
        else if(s1.length() == s2.length()){
            for (int j = 0; j < s1.length(); ++j)
            {
                if((int)s2[j] > (int)s1[j]) pos = i,s1=s2;
                else if((int)s2[j] < (int)s1[j]) break;
            }
        }
    }
    printf("%d\n", pos);
    printf("%s\n", &s1[0]);
    return 0;
}