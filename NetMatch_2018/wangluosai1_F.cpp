#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e6+7;
const int MOD = 1e9+7;

int t,n,m;
int emt[1007];
set<int> s;

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=n;i>=1;i--){
            scanf("%d", &emt[i]);
        }
        if(n&1){
            printf("0\n");
            continue;
        }
        s.clear();
        int cnt=0, flag=1;
        for(int i=1;i<=n;i++){
            if(s.find(emt[i]) == s.end()){//ц╩спур╣╫
                s.insert(emt[i]);
                cnt++;
                if(cnt>5){
                    flag = 0;
                    break;
                }
            }
            else{
                s.erase(emt[i]);
                cnt--;
            }
        }
        if(cnt != 0) flag = 0;
        printf("%d\n",flag);
    }

    return 0;
}

