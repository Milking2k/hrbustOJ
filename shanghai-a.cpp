#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXX 100
int t;
int a[MAXX][MAXX];
int b[MAXX][MAXX];
ll c[MAXX][MAXX];
int main()
{
    scanf("%d",&t);
    int cas=1;
    while(t--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        printf("Case %d:\n",cas++);
        int m,n,l,k;
        cin >> m >> n >> l >> k;
        for(int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i=0; i<l; i++)
            for(int j=0; j<k; j++)
                cin >> b[i][j];
        if(n != l)
            cout << "ERROR" << endl;
        else{
            for(int i=0; i<m; i++)
                for(int j=0; j<k; j++)
                    for(int h=0; h<n; h++)
                        c[i][j] += a[i][h]*b[h][j];
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<k; j++)
                {
                    printf(j==k-1?"%d\n":"%d ",c[i][j]);
                }
            }
        }

    }
}
