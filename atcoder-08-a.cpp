#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	while(cin >> a >> b)
	{
		int len = abs(abs(a) - abs(b));
		if (x > 0 && y > 0) {
        	if (x > y) ans += 2;
	    } else if (x > 0 && y < 0) {
	        ans++;
	    } else if (x < 0 && y > 0) {
	        ans++;
	    } else if (x < 0 && y < 0) {
	        if (x > y) ans += 2;
	    } else if (x == 0 && y < 0) {
	        ans++;
	    } else if (x > 0 && y == 0) {
	        ans++;
	    }
		printf("%d\n", len);
	}
	return 0;
}
