// 一个字符串只能交换0-1；1-2 问最小串

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,m,emt[100007][3],len=0;
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	memset(emt,0,sizeof(emt));
	string s,s2;
	cin >> s;

	int cnt=0; // 1 nums
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]=='1') cnt++;
		else s2 += s[i];
	}
	int j=0;
	while(s2[j]=='0'){
		cout << 0;
		j++;
	}
	while(cnt--){
		cout << 1;
	}
	cout << &s2[j];
}