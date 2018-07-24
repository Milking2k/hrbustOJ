#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=3000005;

int n, sum, f[N], g[N];
int fir[N], pcnt=1, ecnt;
struct node{ int e, next; } edge[N];
void Link( int s, int e ) {
	edge[++ecnt].e=e; edge[ecnt].next=fir[s]; fir[s]=ecnt;
}

int fa[N], sons[N], v[N];
bool ed[N];
char s[N];
void Build_tree( char s[] ) {
	int rot=1, len=strlen(s), w;
	while( --len>=0 ) {
		bool flg=1; w=s[len]-'a'+1;
		for( int i=fir[rot]; i && flg; i=edge[i].next )
			if( v[ edge[i].e ]==w ) rot=edge[i].e, flg=0;
		if( flg ) break;
	}
	while( len>=0 ) {
		v[ ++pcnt ]=s[len--]-'a'+1;
		Link( rot, pcnt );
		fa[pcnt]=rot; rot=pcnt;
	}
	ed[rot]=1; sons[ fa[rot] ]++;
}

void Dp() {
	for( int i=pcnt; i; i-- ) f[i]=g[i]=1;
	for( int i=pcnt; i; i-- ) if( ed[i] ) {
		if( f[ fa[i] ]<=f[i]+sons[i]+ed[i]-1 ) {
			g[ fa[i] ]=f[ fa[i] ];
			f[ fa[i] ]=f[i]+sons[i]+ed[i]-1;
		}
		else g[ fa[i] ]=max( g[ fa[i] ], f[i]+sons[i]+ed[i]-1 );
	}
	for( int i=pcnt; i; i-- )
		sum=max( sum, f[i]+g[i]+sons[i]+ed[i]-2 );
}

int main() {
	scanf( "%d", &n );
	for( int i=1; i<=n; i++ ) {
		scanf( "%s", s );
		Build_tree(s);
	}
	Dp();
	printf( "%d\n", sum );
	return 0;
}
