#include <bits/stdc++.h>
using namespace std;
int lena,lenb,n;
string a,b,c;
 
bool check(int sa,int sb)
{
    bool ok=true;
    for(int i=sa;i<n;i++){
        if(a[i]!=b[i-sa]){
            ok=false;
            break;
        }
    }
    if(ok){
        c="";
        for(int i=0;i<sa;i++){
            c+=a[i];
        }
        c+=b;
    }
    if(ok)return true;
    return false;
}
int main()
{
    while(~scanf("%d",&n)){
        c.clear();
        a.clear();
        b.clear();
        cin>>a>>b;
        bool flag=true;
        for(int i=0;i<n;i++){
            if(check(i,0)){
                flag=false;
                cout<<c.size()<<endl;
                break;
            }
        }
        if(flag)cout<<2*n<<endl;
    }
    return 0;
}