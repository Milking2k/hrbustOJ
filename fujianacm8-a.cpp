#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        int as=(m-n*2)/2;
        int qw=n-as;
        printf("%d %d\n",as,qw);
    }
    return 0;
}