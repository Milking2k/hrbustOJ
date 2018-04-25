#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rd(x) scanf("%d",&x)
// #define rdd(x) scanf("%d",&x)
#define rddd(x,y,z) scanf("%d%d%d",&x,&y,&z)

int p1,p2,p3;

std::vector<string> emt[100];

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	string s;
	while(cin>>p1>>p2>>p3)
	{
		int top=0;
		cin >> s;
		int slen = s.length();
		for (int i = 0; i < slen; ++i)
		{
			if(s[i]=='-' && 0<i && i<slen)
			{
				int len = s[i+1]-s[i-1];
				if(s[i-1] == s[i+1]) putchar('-');
				else if((isalpha(s[i-1]) && isalpha(s[i+1])) || (isdigit(s[i-1]) && isdigit(s[i+1])))
				{
					if(p3==1){
						for (int k = 1; k < len; ++k)
						{
							for (int j = 0; j < p2; ++j)
							{
								if (p1==1)putchar(s[i-1]+k);
								else if(p1==2) putchar(toupper(s[i-1]+k));
								else putchar('*');
							}
						}
					}else
					{
						for (int k = 1; k < len; ++k)
						{
							for (int j = 0; j < p2; ++j)
							{
								if (p1==1)putchar(s[i+1]-k);
								else if(p1==2) putchar(toupper(s[i+1]-k));
								else putchar('*');
							}
						}
					}
				}
				else
				{
					putchar(s[i]);
				}
			}
			else{
				putchar(s[i]);
			}
		}

	}

	return 0;
}