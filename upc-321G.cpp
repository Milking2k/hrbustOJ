#include <bits/stdc++.h>
using namespace std;
struct point
{
	int x,y;
	int r1,r2;
};
bool cmp(point a,point b){return (a.r1 > b.r1);}
int distin(point a, point b)
{
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int main(int argc, char const *argv[])
{
	struct point a;
	struct point b;
	cin >> a.x >> a.y >> b.x >> b.y;
	int n;
	int ans = 0x3f3f3f3f;
	int t=0;
	cin >> n;
	struct point cnt[100005];
	for (int i = 0; i < n; ++i)
	{
	 	cin >> cnt[i].x >> cnt[i].y;
	 	cnt[i].r1 = distin(cnt[i],a);
	 	cnt[i].r2 = distin(cnt[i],b);
	}
	sort(cnt,cnt+n,cmp);
	for (int i = 0; i < n; ++i)
	{
		ans = min(ans, cnt[i].r1+t);
		t = max(t, cnt[i].r2);
	}
	printf("%d\n", min(ans,t));
	return 0;
}