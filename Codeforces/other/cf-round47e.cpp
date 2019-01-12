#include <cstdio>
const int p=998244353;
int n,l,s,a=0,b=0;
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		l=(l*2%p+b)%p;
		s=(s*2%p+l+a)%p;
		b=a;
	}
	printf("%d\n",s);
}