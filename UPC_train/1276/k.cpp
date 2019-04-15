#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e5 +7;
char a[maxn];
int len;
int nxt[maxn];
void getnext()
{
    int j = 0, k = -1;
    nxt[0] = -1;
    while(j < len){
        if(k == -1 || a[j] == a[k]) nxt[++j] = ++k;
        else k = nxt[k];
    }
}
int main()
{
  scanf("%s",a);
  len = strlen(a);
  getnext();
  int ans = -1;
  // for (int i = 1; i <= len; i++) {
  //   printf("%d == %d\n",i, nxt[i]);
  // }
  printf("%d\n",len - nxt[len]);
  return 0;
}