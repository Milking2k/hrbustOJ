#include<bits/stdc++.h>
using namespace std;

int n;
string cnt;
string emt[17]={"purple","green","blue","orange","red","yellow"};
string ans[17]={"Power","Time","Space","Soul","Reality","Mind"};
int ans2[17];
int main()
{
//    scanf("%d",&n);
    ios::sync_with_stdio(false);
    cin >> n;
    int ptans=6;
    for(int i=1;i<=n;i++)
    {
        cin >> cnt;
        for(int j=0;j<7;j++)
        {
            if(cnt==emt[j]) ans2[j]=1,ptans--;
        }
    }
    cout << ptans << endl;
    for(int i=0;i<7;i++)
    {
        if(ans2[i]==0)
            cout << ans[i] << endl;
    }
    return 0;
}
