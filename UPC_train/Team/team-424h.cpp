#include<bits/stdc++.h>
#define debug puts("%%%%%%%%%")
#define read(x) sacnf("%d",&x)
using namespace std;
 
 
int main() {
    char ch;
    string s;
    cin >> s;
    for(int i=1;i<s.length();i++)
    {
        if(s[i]=='s' && s[i-1]=='s')
        {
            printf("hiss\n");
            return 0;
        }
    }
    printf("no hiss\n");
    return 0;
}