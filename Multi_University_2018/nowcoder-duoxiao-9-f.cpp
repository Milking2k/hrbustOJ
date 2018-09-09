#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = a; i<n; i++)
#define per(i,a,n) for (int i = n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 1000000007;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int MAX_N = 1e5+7;
const int MAX_TOT = 1e5+7;

struct ACho{
	struct state {
		int next[26];
		int fail, cnt;
	}stateTable[MAX_TOT];

	int size;

	std::queue<int> que;

	void init(){
		while(que.size()) que.pop();

		for(int i = 0; i < MAX_TOT; i++) {
			memset(stateTable[i].next, 0, sizeof(stateTable[i].next));
			stateTable[i].fail = stateTable[i].cnt = 0;
		}
		size = 1;
	}
	
	void insert(char *S) {
		int n = strlen(S);
		int now = 0;
		for (int i = 0; i < n; ++i) {
			char c = S[i];
			if(~stateTable[now].next[c - 'a']){
				stateTable[now].next[c - 'a'] = size++;
			}
			now = stateTable[now].next[c - 'a'];
		}
		stateTable[now].cnt++;
	}

	void build() {
		stateTable[0].fail = -1;
		que.push(0);
		while(que.size()){
			int u = que.front();
			que.pop();

			for (int i = 0; i < 26; ++i){
				if(stateTable[u].next[i]) {
					if(u == 0) stateTable[stateTable[u].next[i]].fail = 0;
					else {
						int v = stateTable[u].fail;
						while(v != -1) {
							if(stateTable[v].next[i]) {
								stateTable[stateTable[u].next[i]].fail = stateTable[v].next[i];
							}
							v = stateTable[v].fail;
						}
						if(v == -1) stateTable[stateTable[u].next[i]].fail = 0;
					}
					que.push(stateTable[u].next[i]);
				}
			}
		}
	}

	int Get(int u) {
		int res = 0;
		while(u) {
			res = res + stateTable[u].cnt;
			stateTable[u].cnt = 0;
			u = stateTable[u].fail;
		}
	}

	int match(char *S){
		int n = strlen(S);
		int res = 0, now = 0;
		for (int i = 0; i < n; ++i){
			char c = S[i];
			if(stateTable[now].next[c - 'a'])
				now = stateTable[now].next[c - 'a'];
			else {
				int p = stateTable[now].fail;
				while(p != -1 && stateTable[p].next[c - 'a'] == 0) p  = stateTable[p].fail;

				if(p == -1) now = 0;
				else now = stateTable[p].next[c - 'a'];
			}
			if (stateTable[now].cnt)
				res += Get(now);
		}
		return res;
	}

	int d[maxn];
    vector<int> G[maxn];
	void solve(const char* op)
    {
        for (int u = 0; u < sz; u++)
            for (int c = 0; c < 26; c++)
                if (~stateTable[u].next[c])
                    G[ch[u][c]].push_back(u);
        memset(d, -1, sizeof(d));
        queue<int> q;
        for (int i = 0; i < sz; i++)
            if (val[i]) q.push(i), d[i] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto& v : G[u])
            {
                if (~d[v]) continue;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        stack<int> s;
        int u = rt;
        s.push(u);
        printf("%d\n", d[u]);
        for (int i = 0; op[i]; i++)
        {
            if (op[i] == '-')
            {
                s.pop();
                if (!s.empty())
                    u = s.top();
                else
                    s.push(0);
                printf("%d\n", d[u]);
            }
            else
            {
                u = ch[u][op[i] - 'a'];
                s.push(u);
                printf("%d\n", d[u]);
            }
        }
    }


}acho;


int n;

char s[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    ac.init();
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        ac.insert(s, i);
    }
    ac.build();
    scanf("%s", s);
    ac.solve(s);
}
