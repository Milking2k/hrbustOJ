#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		string s;
		getline(cin,s);
		cout << s << endl;
	}
	return 0;
}