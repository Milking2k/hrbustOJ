#include <bits/stdc++.h>
using namespace std;

struct people
{
	int dir;
	string name;
};

int main(int argc, char const *argv[])
{
	long long int n,m;
	struct people a[200000];

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].dir >> a[i].name;
	}
	int cnt1 = a[0].dir;
	// int cnt1 = a[0].;
	int pos = 0;
	for (int i = 0; i < m; ++i)
	{
		int c1,c2;
		int oprt;
		cin >> c1 >> c2;
		if (c1 == cnt1)
		{
			oprt = -1;
			// int poscnt = abs(pos-c2);
		}else{
			oprt = 1;
		}


		if (pos+oprt*c2 < 0)
		{
			pos = (pos+n+oprt*c2)%n;
		}else{
			pos = (pos+oprt*c2)%(n);
		}
		cnt1 = a[pos].dir;
		// printf("pos:%d  ", pos);
		// printf("cnt1:%d\n", cnt1);
	}
	// printf("%s\n", a[pos].name);
	// printf("_");
	cout << a[pos].name << endl;
	// printf("_");

	return 0;
}