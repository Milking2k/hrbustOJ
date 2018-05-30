#include<bits/stdc++.h>
using namespace std;

int n;
vector<string> emt;
bool cmp(string a,string b){return a+b>b+a;}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        string cnt;
        cin >> cnt;
        emt.push_back(cnt);
    }

    sort(emt.begin(),emt.end(),cmp);
    for(int i=0;i<emt.size();i++)
    {
        cout << emt[i];
    }

    cout << endl;
    return 0;
}
