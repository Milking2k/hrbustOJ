#include<bits/stdc++.h>
using namespace std;

int n;
int x,y;
int main()
{
//    scanf("%d",&n);
    ios::sync_with_stdio(false);
    cin >> x >> y;
    if(x>=3 && y>=3)
    {
        if(x<y) cout << ">";
        else if(x>y) cout << "<";
        else cout << "=";
    }
    else if(x==1||y==1)
    {
        if(x!=1) cout << ">";
        else if(y!=1) cout << "<";
        else cout << "=";
    }
    else if(x==y)
    {
        cout << "=";
    }
    else
    {
        if(x==2)
        {
            if(y==3) cout << "<";
            else if(y==4) cout << "=";
            else cout << ">";
        }
        else
        {
            if(x==3) cout << ">";
            else if(x==4) cout << "=";
            else cout << "<";
        }
    }
    return 0;
}

