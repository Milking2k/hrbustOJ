#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn=1e7+4;
vector<int>c[55];
//int mp[28][maxn];
//int top[28];
string s;
string ans;
int main() {
    int T;
    read(T);
    while(T--) {
        for(int i=0;i<40;i++)c[i].clear();
        ans.clear();
        int n;read(n);
        n--;
        cin>>ans;
        int len=ans.size();
        for(int i=0;i<len;i++){
            c[ans[i]-'a'].push_back(i);
        }
        for(int i=1;i<=n;i++) {
            cin>>s;
            len=s.size();
            int j=0;
            bool ok=true;
            int pre=0;
            for(j=0;j<len;j++){
                if(j==0){
                    if(c[s[j]-'a'].size()){
                        pre=c[s[j]-'a'][0];
                    }
                    else{
                        break;
                    }
                    continue;
                }
                int now=s[j]-'a';
//                cout<<"NOW "<<now<<endl;
                if(c[now].size()==0){
//                    printf("qwe j==%d\n",j);
                    break;
                }
                int pos=upper_bound(c[now].begin(),c[now].end(),pre)-c[now].begin();
//                printf("test i==%d j==%d pre==%d pos==%d c[now][pos]==%d now==%d\n",i,j,pre,pos,c[now][pos],now);
                if(pos>=c[now].size())break;
                if(c[now][pos]>pre)pre=c[now][pos];
                else {
//                    cout<<"$%#%"<<j<<endl;
                    break;
                }
            }
            int as=ans.size();
//            printf("fuck as==%d j==%d\n",as,j);
            for(;j<len;j++){
                ans+=s[j];
                c[s[j]-'a'].push_back(as);
                as++;
            }
        }
        cout<<ans<<endl;
    }
}