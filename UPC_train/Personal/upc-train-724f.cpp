#include<bits/stdc++.h>
using namespace std;

int n;
int vis[200];
string s[55];
string sto;
int main()
{
    memset(vis,0,sizeof(vis));
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s[i];
    }
    cin >> sto;
    for(int i=1;i<=n;i++){
        if(s[i].find(sto,0)==0){

            if(sto.length()>=s[i].length()) continue;
//            printf("%c\n",s[i][sto.length()]);
            vis[s[i][sto.length()]-'A']=1;
        }
    }
    cout << "***";
    for(int i=0;i<26;i++){
        if((i+3)%8==0) cout << endl;
        if(vis[i]==0) cout << "*";
        else cout << (char)(i+'A');

    }
    cout << "***\n";
    return 0;
}

