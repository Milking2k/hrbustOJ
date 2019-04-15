#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 3e5 + 7;
const double eps = 1e-4;
typedef pair<double, double> pii;
pii a[maxn];
int n;
int stku[maxn],topu;
int stkd[maxn],topd;
bool check (double x)
{
  topu = topd = 0;
  int i = 1;
  while(a[i].second <= x) i++;
  // printf("aaa %d\n", i);
  int v1id = i, v2id = 0;
  double u = a[i].second + x, d = a[i].second - x;
  double tmp = a[i].second;
 
  for (; i <= n; i++) {
    if(d <= a[i].second && a[i].second <= u) continue;
    if(fabs(a[i].second - tmp) > 2.0 * x){
      v2id = i;
      break;
    }
    if(a[i].second > u) {
      if(topd != 0) {
        v2id = i;
        // printf("bbb1\n");
        break;
      }
      stku[++topu] = i;
    }
    if(a[i].second < d) {
      if(topu != 0) {
        v2id = i;
        // printf("bbb2\n");
        break;
      }
      stkd[++topd] = i;
    }
    // printf("test %d\n",i);
  }
  // printf("aaa %d\n",i);
  double minn1 = 999999999.0, maxe1 = -1.0;
  if(v2id != -1) {
    for (int i = v1id; i < v2id; i++) {
      minn1 = min(a[i].second, minn1);
      maxe1 = max(a[i].second, maxe1);
    }
    if(maxe1 - maxe1 > 2.0 * x) return false;
  }
  // printf("fuck %d\n",v2id);
  double minn2, maxe2;
  minn2 = a[v2id].second, maxe2 = a[v2id].second;
  for (int i = v2id; i <= n; i++){
    minn2 = min(a[i].second, minn2);
    maxe2 = max(a[i].second, maxe2);
  } 
  // printf("aaa %f %f\n",maxe2, minn2);
  if(maxe2 - minn2 > 2.0 * x) return false;
  if(minn1 + x > maxe2 - x) return false;
  // if(minn1 <= minn2 && maxe1 <= maxe2) return true;
  return true;
}
int main()
{
  while(~scanf("%d", &n)) {
    double res = 0.0;
    for (int i = 1; i <= n; i++) {
      double x, y;
      scanf("%lf%lf", &x, &y);
      res = max(res, y);
      a[i] = make_pair(x,y);
    }
    sort (a + 1, a + 1 + n);
    // printf("test %d\n",check(1));
    double L = 0.0, R = res / 2.0;
    double ans = -1.0;
    while(L + eps <= R) {
      double mid = (L + R) * 0.5 ;
      // printf("test %lf %lf %lf %d\n",L, R, mid, check(mid));
      if(check(mid)) {
        R = mid;
        ans = mid;
      }
      else L = mid;
    }
    printf("%.1f\n",ans);
  }
  return 0;
}