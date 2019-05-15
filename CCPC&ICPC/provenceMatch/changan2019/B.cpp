#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        int ans = 0;
        while(n > 2) ans++, n/=2;
        if(n == 2) ans += 2;
        else ans += 1;
        printf("%d\n",ans);
    }
    
    return 0;
}

/*

1 2
1 1
0 0

1 2 3
1 1 2
0 0 1
0 0 0

1 2 3 4
1 2 1 2
0 1 0 1
0 0 0 0
= 3

1 2 3 4 5 6 7 8
1 2 3 4 1 2 3 4
1 2 1 2 1 2 1 2
0 2
0 0
= 4

1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 1 2 3 4 5
1 2 0 1 2 1 2 0 1 2
0 2 0
0 0 0
= 4

1 2 3 4 5 6 7 8 9 10 11 12 13
1 2 3 4 5 6 0 1 2 3  4  5  6
1 2 3 1 2 3 0 1 2 3  1  2  3


*/