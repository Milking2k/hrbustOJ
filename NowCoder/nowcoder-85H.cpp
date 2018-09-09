#include <bits/stdc++.h>
using namespace std;
 
char strs[10][5010];
char vs[] = "FEDCBAGFE";
 
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < 9; i++) {
    scanf("%s", strs[i]);
  }
  for(int i = 0; i < n; i++) {
    if(strs[0][i] == '|') {
      putchar('|');
    }
    for(int j = 0; j < 9; j++) {
      if(strs[j][i] == 'o') putchar(vs[j]);
    }
  }
  puts("");
}