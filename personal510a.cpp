#include<iostream>
#include<cstring>
using namespace std;

int n;
int m;
int s;
double v;

int all;
double dis[101];

class exchange_points
{
public:
    int a;
    int b;
    double r;
    double c;
}exc[202];

bool bellman(void)
{
    memset(dis,0,sizeof(dis));
    dis[s]=v;
    bool flag;
    for(int i=1;i<=n-1;i++)
    {
        flag=false;
        for(int j=0;j<all;j++)
            if(dis[exc[j].b] < (dis[exc[j].a] - exc[j].c) * exc[j].r)
            {
                dis[exc[j].b] = (dis[exc[j].a] - exc[j].c) * exc[j].r;
                flag=true;
            }
        if(!flag)
            break;
    }


    for(int k=0;k<all;k++)
        if(dis[exc[k].b] < (dis[exc[k].a] - exc[k].c) * exc[k].r)
            return true;

    return false;
}

int main(void)
{
    int a,b;
    double rab,cab,rba,cba;

    while(cin>>n>>m>>s>>v)
    {
        all=0;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>rab>>cab>>rba>>cba;
            exc[all].a=a;
            exc[all].b=b;
            exc[all].r=rab;
            exc[all++].c=cab;
            exc[all].a=b;
            exc[all].b=a;
            exc[all].r=rba;
            exc[all++].c=cba;
        }
        if(bellman())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}