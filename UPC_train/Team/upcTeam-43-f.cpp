#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
int main(int argc, char const *argv[])
{
	ll a,b;
	cin >> a >> b;
	if(a>0){
		printf("Positive\n");
		return 0;
	}else if(a==0 || b==0 || (a<0 && b>0)){
		printf("Zero\n");
		return 0;
	}else{
		int cnt = abs(b-a);
		if(cnt%2==0){
			printf("Negative\n");
		}else{
			printf("Positive\n");
		}
	}
	return 0;
}