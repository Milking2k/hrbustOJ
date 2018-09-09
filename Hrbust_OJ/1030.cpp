#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	long long int a[100005];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	for (int i = 0; i < n; ++i)
	{
		// printf("%d\n", a[i]);
		cout << a[i] << endl;
	}
	// printf("\n");
	return 0;
}