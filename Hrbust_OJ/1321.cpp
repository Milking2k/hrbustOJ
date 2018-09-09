#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int times;
	scanf("%d", &times);
	while(times--)
	{
		int eages[4];
		for (int i = 0; i < 4; ++i)
		{
			cin >> eages[i];
		}
		sort(eages,eages+4);
		for (int i = 0; i < 4; ++i)
		{
			if(eages[2] - eages[1] < eages[0] || eages[3] - eages[2] < eages[1] ||
			   eages[3] - eages[2] < eages[0] || eages[3] - eages[1] < eages[0])
			{
				printf("T\n");
				break;
			}else if (eages[2] - eages[1] == eages[0] || eages[3] - eages[2] == eages[1] ||
			   eages[3] - eages[2] == eages[0] || eages[3] - eages[1] == eages[0])
			{
				printf("S\n");
				break;
			}else{
				printf("I\n");
				break;
			}

		}
	}
	return 0;
}