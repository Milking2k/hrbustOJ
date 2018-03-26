#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	int book[100];
	int a[20];
	while(cin >> a[0] && a[0])
	{
		if(a[0] == -1) return 0;
		int i = 0;
		int count=0;
		memset(book,0,sizeof(book));
		book[a[0]]=1;
		for (i = 1; i < 20; ++i)
		{
			cin >> a[i];
			book[a[i]] = 1;
			if(a[i] == 0) break;
		}// len == i-1
		for (int j = 0; j < i; ++j)
		{
			if(a[j]%2 != 0)continue;
			int cnt = a[j]/2;
			// printf("a[j]:%d  cnt:%d   book[cnt]:%d\n", a[j], cnt, book[cnt]);
			if(book[cnt]) count++;
		}
		printf("%d\n", count);

	}
	return 0;
}