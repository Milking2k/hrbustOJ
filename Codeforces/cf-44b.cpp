#include<bits/stdc++.h>
using namespace std;
char in[2007][2007];
int sum[2007];
int main()
{
   int n,m;
   scanf("%d %d",&n,&m);
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
       {
           scanf("%1d",&emt[i][j]);
           emt2[i] += emt[i][j];
       }
   }
//    printf("test1\n");
   int cnt;
   for(int i=1;i<=n;i++)
   {
       cnt = 0;
       for(int j=1;j<=n;j++)
       {
           if(j!=i) cnt = cnt | emt2[j];
           //printf("cnt:%d\n",cnt);
       }
   }
//    printf("test2\n");
   if((~cnt)==(0<<n)) printf("YES");
   else printf("NO");

   return 0;
}
// int main() {
// 	int N, M, i, j;
// 	scanf("%d %d", &N, &M);
// 	for (i = 1; i <= N; i++) {
// 		scanf("%s", in[i] + 1);
// 		for (j = 1; j <= M; j++) if (in[i][j] == '1') sum[j]++;
// 	}

// 	for (i = 1; i <= N; i++) {
// 		for (j = 1; j <= M; j++) if (in[i][j] == '1' && sum[j] == 1) break;
// 		if (j > M) return !printf("YES\n");
// 	}
// 	return !printf("NO\n");
// }