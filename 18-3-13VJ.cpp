//wrong answer

#include <iostream>
#include <cstdio>
#include <cstring>
// 74 73 79
using namespace std;
// char s;
int a[200005][3];
char s[200005];
int main(int argc, char const *argv[])
{
	int n;
	while(~scanf("%d\n",&n))
	{
		int maxlen = 0;
		memset(a,0,sizeof(a));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				a[i][j] = a[i-1][j];
			}
			scanf("%c", &s[i]);
			// printf("s[i]:%c_\n", s[i]);
			switch(s[i])
			{
				case 'J': a[i][0]++;break;
				case 'O': a[i][1]++;break;
				case 'I': a[i][2]++;break;
			}
			// printf("j:%d	o:%d	i:%d\n", a[i][0], a[i][1], a[i][2]);
			if (i >= 6 && a[i][0] == a[i][1] && a[i][2] == a[i][1] && i>maxlen)
			{
				maxlen = i;
			}
		}
		for (int i = 7; i <= n; ++i)
		{
			for (int j = 0; j < i-6; ++j)
			{
				if (i >= 6 &&
					a[i][0] - a[j][0] == a[i][1] - a[j][1]&&
					a[i][2] - a[j][2] == a[i][1] - a[j][1]&&
					i-j > maxlen)
				{
					// printf("i:%d  j:%d  maxlen:%d\n", i,j,maxlen);					
					maxlen = i-j;
				}
			}
		}
		if (maxlen == 0)
		{
			printf("0\n");
		}else{
			printf("%d\n", maxlen);
		}


	}


	return 0;
}