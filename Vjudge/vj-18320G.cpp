#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n)
	{
		double cnt = sqrt(n*1.0);
		// printf("cnt:%.2f\n", cnt);
		int toend = 0;
		for (int i = 1; i < cnt; ++i)
		{
			int cnt1 = i*i;
			for (int j = i; j < cnt; ++j)
			{
				int cnt2 = j*j;
				for (int k = j; k < cnt; ++k)
				{
					if (cnt1+cnt2+k*k == n)
					{
						printf("%d %d %d\n", i,j,k);
						toend=1;
						break;
					}
				}
				if (toend)break;
			}
			if (toend)break;
		}
	}
	return 0;
}