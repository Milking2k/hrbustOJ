// unfinished

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	while(~scanf("%d",&t)){
		string s;
		getline(cin,s);
		int a[102];
		memset(a,1e3,sizeof(a));
		int head=0;
		int tail=0;
		while(t--)
		{
			
			char ch = getchar();
			// cin >> a[tail];
			scanf("%c %d",&a[tail]);
			getline(cin,s);
			// cin >> a[tail];
			printf("ch=%c\n", ch);
			cout << s << endl;
			printf("a[%d]=%d\n",tail, a[tail-1]);
			// continue;


			switch(ch)
			{
				case 'e':
					// scanf("%d",&a[tail-1]);
					cin >> a[tail];
					printf("a[%d]=%d\n",tail, a[tail-1]);
					tail++;
					break;
				case 'q':
					if (head >= tail)
					{
						printf("this is empty!\n");
						break;
					}
					for (int i = head; i < tail; ++i)
					{
						printf("%d\n", a[i]);
						a[i] = 1e3;
					}
					tail = 0;
					break;
				case 'd':
					if (head < tail)
					{
						printf("%d\n", a[head]);
						head++;
					}else{
						printf("this is empty!\n");
					}
					break;
				default:printf("error\n");break;
			}

		}		
	}
	return 0;
}