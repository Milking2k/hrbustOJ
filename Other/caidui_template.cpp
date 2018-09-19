#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
#define pb(x) push_back(x)
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, int> PII;
typedef pair<ll, ll> pll;
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define my_sort_unique(c) (sort(c.begin(), c.end())), my_unique(c)
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;
const int mod = 1e9 + 7;
const int NINF = 0xc0c0c0c0;
const int maxn = 1e5 + 5;

struct Edge {
    int from, to, cap, flow, cost;
    Edge(int u, int v, int c, int f, int w)
        : from(u), to(v), cap(c), flow(f), cost(w) {}
};
struct MCMF {
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn]; //是否在队列中
    int d[maxn];    // bellmanford 到源点距离
    int p[maxn];    //上一条弧
    int a[maxn];    //可改进量

    void init(int n) {//init the graph's edge size
        this->n = n;
        for (int i = 0; i <= n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap, int cost) {
        edges.push_back(Edge(from, to, cap, 0, cost));
        edges.push_back(Edge(to, from, 0, 0, -cost));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BellmanFord(int s, int t, int& flow, ll& cost) {
        for (int i = 0; i <= n; i++) d[i] = INF;
        memset(inq, 0, sizeof(inq));
        d[s] = 0;
        inq[s] = 1;
        p[s] = 0;
        a[s] = INF;
        queue<int> Q;
        Q.push(s);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); i++) {
                Edge& e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to]) {
                        Q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if (d[t] == INF) return false; // 当没有可增广的路时退出
        flow += a[t];
        cost += (ll)d[t] * (ll)a[t];
        for (int u = t; u != s; u = edges[p[u]].from) {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
        }
        return true;
    }

    int MincostMaxflow(int s, int t, ll& cost) {// return the cost or using the cost
        int flow = 0;
        cost = 0;
        while (BellmanFord(s, t, flow, cost))
            ;
        return flow;
    }
}ans;

/*==================================
树链剖分
==================================*/
struct HLD
{
    int n, dfs_clock;
    int sz[maxn], top[maxn], son[maxn], dep[maxn], fa[maxn], id[maxn];
    ull ref[maxn];
    vector<int> G[maxn];
    void init(int n)
    {
        this->n = n, memset(son, -1, sizeof(son)), dfs_clock = 0;
        for (int i = 0; i <= n; i++) G[i].clear();
    }
    void add_edge(int u, int v) { G[u].push_back(v), G[v].push_back(u); }
    void dfs(int u, int p, int d)
    {
        dep[u] = d, fa[u] = p, sz[u] = 1;
        for (auto& v : G[u])
        {
            if (v == p) continue;
            dfs(v, u, d + 1);
            sz[u] += sz[v];
            if (son[u] == -1 || sz[v] > sz[son[u]]) son[u] = v;
        }
    }
    void link(int u, int t)
    {
        top[u] = t, id[u] = ++dfs_clock;
        if (son[u] == -1) return;
        link(son[u], t);
        for (auto& v : G[u])
            if (v != son[u] && v != fa[u]) link(v, v);
    }

    void update_path(int u, int v, int op, ull val)
    {
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            update(id[top[u]], id[u], op, val, 1, n, 1);
            u = fa[top[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        update(id[u], id[v], op, val, 1, n, 1);
    }

    ull query_path(int u, int v)
    {
        ull ret = 0;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            ret += query(id[top[u]], id[u], 1, n, 1);
            u = fa[top[u]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        ret += query(id[u], id[v], 1, n, 1);
        return ret;
    }
#define lson o << 1
#define rson o << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson
#define lm (m - (m >> 1))
#define rm (m >> 1)
    ull sum[maxn << 2], addv[maxn << 2], mulv[maxn << 2];
    inline void pushup(int o) { sum[o] = sum[lson] + sum[rson]; }
    inline void pushdown(int o, int m)
    {
        if (addv[o] != 0 || mulv[o] != 1)
        {
            addv[lson] = (mulv[o] * addv[lson] + addv[o]);
            addv[rson] = (mulv[o] * addv[rson] + addv[o]);
            mulv[lson] = mulv[lson] * mulv[o];
            mulv[rson] = mulv[rson] * mulv[o];
            sum[lson] = mulv[o] * sum[lson] + addv[o] * lm;
            sum[rson] = mulv[o] * sum[rson] + addv[o] * rm;
            addv[o] = 0;
            mulv[o] = 1;
        }
    }
    void build(int l, int r, int o)
    {
        addv[o] = 0, mulv[o] = 1;
        sum[o] = 0;
        if (l == r) return;
        const int m = l + r >> 1;
        build(Lson);
        build(Rson);
        pushup(o);
    }
    void update(int L, int R, int op, ull v, int l, int r, int o)
    {
        if (L <= l && r <= R)
        {
            if (op == 1)
            {
                addv[o] *= v;
                mulv[o] *= v;
                sum[o] *= v;
            }
            if (op == 2)
            {
                addv[o] += v;
                sum[o] += v * (r - l + 1);
            }
            return;
        }
        const int m = l + r >> 1;
        pushdown(o, r - l + 1);
        if (L <= m) update(L, R, op, v, Lson);
        if (m < R) update(L, R, op, v, Rson);
        pushup(o);
    }
    ull query(int L, int R, int l, int r, int o)
    {
        if (L <= l && r <= R) return sum[o];
        pushdown(o, r - l + 1);
        const int m = l + r >> 1;
        ull ret = 0;
        if (L <= m) ret += query(L, R, Lson);
        if (m < R) ret += query(L, R, Rson);
        return ret;
    }
} gao;


/*===================
SAM
===================*/

char buf[maxn];
struct SAM
{
    int len[maxn << 1], link[maxn << 1], ch[maxn << 1][26];
    int sz, rt, last;
    int newnode(int x = 0)
    {
        len[sz] = x;
        link[sz] = -1;
        memset(ch[sz], -1, sizeof(ch[sz]));
        return sz++;
    }
    void init() { sz = last = 0, rt = newnode(); }// init before using 
    void extend(int c)
    {
        int np = newnode(len[last] + 1);
        int p;
        for (p = last; ~p && ch[p][c] == -1; p = link[p]) ch[p][c] = np;
        if (p == -1)
            link[np] = rt;
        else
        {
            int q = ch[p][c];
            if (len[p] + 1 == len[q])
                link[np] = q;
            else
            {
                int nq = newnode(len[p] + 1);
                memcpy(ch[nq], ch[q], sizeof(ch[q]));
                link[nq] = link[q], link[q] = link[np] = nq;
                for (; ~p && ch[p][c] == q; p = link[p]) ch[p][c] = nq;
            }
        }
        last = np;
    }
    int topcnt[maxn], topsam[maxn << 1];
    void sort()
    { // 加入串后拓扑排序
        memset(topcnt, 0, sizeof(topcnt));
        for (int i = 0; i < sz; i++) topcnt[len[i]]++;
        for (int i = 0; i < maxn - 1; i++) topcnt[i + 1] += topcnt[i];
        for (int i = 0; i < sz; i++) topsam[--topcnt[len[i]]] = i;
    }
    int dp[maxn];
    void solve(int a, int b)
    {
        for (int i = 0; i < sz; i++) dp[i] = 0;
        int u = 0;
        for (int i = 0; buf[i]; i++) dp[u = ch[u][buf[i] - 'A']] = 1;
        for (int i = sz - 1; ~i; i--)
        {
            int u = topsam[i];
            if (~link[u]) dp[link[u]] += dp[u];
        }
        ll ans = 0;
        for (int i = 1; i < sz; i++)
            if (dp[i] >= a && dp[i] <= b) ans += len[i] - len[link[i]];
        printf("%lld\n", ans);
    }
} sam;

/*===================
bigint
===================*/
// base and base_digits must be consistent
constexpr int base = 1000000000;
constexpr int base_digits = 9;
struct bigint
{
    // value == 0 is represented by empty z
    vector<int> z; // digits

    // sign == 1 <==> value >= 0
    // sign == -1 <==> value < 0
    int sign;

    bigint() : sign(1) {}

    bigint(long long v) { *this = v; }

    bigint& operator=(long long v)
    {
        sign = v < 0 ? -1 : 1;
        v *= sign;
        z.clear();
        for (; v > 0; v = v / base)
            z.push_back((int)(v % base));
        return *this;
    }

    bigint(const string& s) { read(s); }

    bigint& operator+=(const bigint& other)
    {
        if (sign == other.sign)
        {
            for (int i = 0, carry = 0; i < other.z.size() || carry; ++i)
            {
                if (i == z.size())
                    z.push_back(0);
                z[i] += carry + (i < other.z.size() ? other.z[i] : 0);
                carry = z[i] >= base;
                if (carry)
                    z[i] -= base;
            }
        }
        else if (other != 0 /* prevent infinite loop */)
        {
            *this -= -other;
        }
        return *this;
    }

    friend bigint operator+(bigint a, const bigint& b)
    {
        return a += b;
    }

    bigint& operator-=(const bigint& other)
    {
        if (sign == other.sign)
        {
            if (sign == 1 && *this >= other || sign == -1 && *this <= other)
            {
                for (int i = 0, carry = 0; i < other.z.size() || carry; ++i)
                {
                    z[i] -= carry + (i < other.z.size() ? other.z[i] : 0);
                    carry = z[i] < 0;
                    if (carry)
                        z[i] += base;
                }
                trim();
            }
            else
            {
                *this = other - *this;
                this->sign = -this->sign;
            }
        }
        else
        {
            *this += -other;
        }
        return *this;
    }

    friend bigint operator-(bigint a, const bigint& b)
    {
        return a -= b;
    }

    bigint& operator*=(int v)
    {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < z.size() || carry; ++i)
        {
            if (i == z.size())
                z.push_back(0);
            long long cur = (long long)z[i] * v + carry;
            carry = (int)(cur / base);
            z[i] = (int)(cur % base);
        }
        trim();
        return *this;
    }

    bigint operator*(int v) const
    {
        return bigint(*this) *= v;
    }

    friend pair<bigint, bigint> divmod(const bigint& a1, const bigint& b1)
    {
        int norm = base / (b1.z.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.z.resize(a.z.size());

        for (int i = (int)a.z.size() - 1; i >= 0; i--)
        {
            r *= base;
            r += a.z[i];
            int s1 = b.z.size() < r.z.size() ? r.z[b.z.size()] : 0;
            int s2 = b.z.size() - 1 < r.z.size() ? r.z[b.z.size() - 1] : 0;
            int d = (int)(((long long)s1 * base + s2) / b.z.back());
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.z[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return {q, r / norm};
    }

    friend bigint sqrt(const bigint& a1)
    {
        bigint a = a1;
        while (a.z.empty() || a.z.size() % 2 == 1)
            a.z.push_back(0);

        int n = a.z.size();

        int firstDigit = (int)::sqrt((double)a.z[n - 1] * base + a.z[n - 2]);
        int norm = base / (firstDigit + 1);
        a *= norm;
        a *= norm;
        while (a.z.empty() || a.z.size() % 2 == 1)
            a.z.push_back(0);

        bigint r = (long long)a.z[n - 1] * base + a.z[n - 2];
        firstDigit = (int)::sqrt((double)a.z[n - 1] * base + a.z[n - 2]);
        int q = firstDigit;
        bigint res;

        for (int j = n / 2 - 1; j >= 0; j--)
        {
            for (;; --q)
            {
                bigint r1 = (r - (res * 2 * base + q) * q) * base * base 
                + (j > 0 ? (long long)a.z[2 * j - 1] * base + a.z[2 * j - 2] : 0);
                if (r1 >= 0)
                {
                    r = r1;
                    break;
                }
            }
            res *= base;
            res += q;

            if (j > 0)
            {
                int d1 = res.z.size() + 2 < r.z.size() ? r.z[res.z.size() + 2] : 0;
                int d2 = res.z.size() + 1 < r.z.size() ? r.z[res.z.size() + 1] : 0;
                int d3 = res.z.size() < r.z.size() ? r.z[res.z.size()] : 0;
                q = (int)(((long long)d1 * base * base + (long long)d2 * base + d3) / (firstDigit * 2));
            }
        }

        res.trim();
        return res / norm;
    }

    bigint operator/(const bigint& v) const
    {
        return divmod(*this, v).first;
    }

    bigint operator%(const bigint& v) const
    {
        return divmod(*this, v).second;
    }

    bigint& operator/=(int v)
    {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int)z.size() - 1, rem = 0; i >= 0; --i)
        {
            long long cur = z[i] + rem * (long long)base;
            z[i] = (int)(cur / v);
            rem = (int)(cur % v);
        }
        trim();
        return *this;
    }

    bigint operator/(int v) const
    {
        return bigint(*this) /= v;
    }

    int operator%(int v) const
    {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = (int)z.size() - 1; i >= 0; --i)
            m = (int)((z[i] + m * (long long)base) % v);
        return m * sign;
    }

    bigint& operator*=(const bigint& v)
    {
        *this = *this * v;
        return *this;
    }

    bigint& operator/=(const bigint& v)
    {
        *this = *this / v;
        return *this;
    }

    bool operator<(const bigint& v) const
    {
        if (sign != v.sign)
            return sign < v.sign;
        if (z.size() != v.z.size())
            return z.size() * sign < v.z.size() * v.sign;
        for (int i = (int)z.size() - 1; i >= 0; i--)
            if (z[i] != v.z[i])
                return z[i] * sign < v.z[i] * sign;
        return false;
    }

    bool operator>(const bigint& v) const
    {
        return v < *this;
    }

    bool operator<=(const bigint& v) const
    {
        return !(v < *this);
    }

    bool operator>=(const bigint& v) const
    {
        return !(*this < v);
    }

    bool operator==(const bigint& v) const
    {
        return !(*this < v) && !(v < *this);
    }

    bool operator!=(const bigint& v) const
    {
        return *this < v || v < *this;
    }

    void trim()
    {
        while (!z.empty() && z.back() == 0)
            z.pop_back();
        if (z.empty())
            sign = 1;
    }

    bool isZero() const
    {
        return z.empty();
    }

    friend bigint operator-(bigint v)
    {
        if (!v.z.empty())
            v.sign = -v.sign;
        return v;
    }

    bigint abs() const
    {
        return sign == 1 ? *this : -*this;
    }

    long long longValue() const
    {
        long long res = 0;
        for (int i = (int)z.size() - 1; i >= 0; i--)
            res = res * base + z[i];
        return res * sign;
    }

    friend bigint gcd(const bigint& a, const bigint& b)
    {
        return b.isZero() ? a : gcd(b, a % b);
    }

    friend bigint lcm(const bigint& a, const bigint& b)
    {
        return a / gcd(a, b) * b;
    }

    void read(const string& s)
    {
        sign = 1;
        z.clear();
        int pos = 0;
        while (pos < s.size() && (s[pos] == '-' || s[pos] == '+'))
        {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = (int)s.size() - 1; i >= pos; i -= base_digits)
        {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            z.push_back(x);
        }
        trim();
    }

    friend istream& operator>>(istream& stream, bigint& v)
    {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream& operator<<(ostream& stream, const bigint& v)
    {
        if (v.sign == -1)
            stream << '-';
        stream << (v.z.empty() ? 0 : v.z.back());
        for (int i = (int)v.z.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.z[i];
        return stream;
    }

    static vector<int> convert_base(const vector<int>& a, int old_digits, int new_digits)
    {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int v : a)
        {
            cur += v * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits)
            {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int)cur);
        while (!res.empty() && res.back() == 0)
            res.pop_back();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll& a, const vll& b)
    {
        int n = a.size();
        vll res(n + n);
        if (n <= 32)
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    bigint operator*(const bigint& v) const
    {
        vector<int> a6 = convert_base(this->z, base_digits, 6);
        vector<int> b6 = convert_base(v.z, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < c.size(); i++)
        {
            long long cur = c[i] + carry;
            res.z.push_back((int)(cur % 1000000));
            carry = (int)(cur / 1000000);
        }
        res.z = convert_base(res.z, 6, base_digits);
        res.trim();
        return res;
    }
};

/*
trie AC 自动机
*/

typedef vector<ll> vec;
typedef vector<vec> mat;
mat mul(mat& A, mat& B)
{
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int k = 0; k < B.size(); k++)
            if (A[i][k]) // 对稀疏矩阵的优化
                for (int j = 0; j < B[0].size(); j++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}
mat Pow(mat A, ll n)
{
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++) B[i][i] = 1;
    for (; n; n >>= 1, A = mul(A, A))
        if (n & 1) B = mul(B, A);
    return B;
}
struct Trie
{
    int ch[maxn][3], f[maxn], val[maxn];
    int sz, rt;
    int newnode()
    {
        memset(ch[sz], -1, sizeof(ch[sz])), val[sz] = 0;
        return sz++;
    }
    void init() { sz = 0, rt = newnode(); }
    inline int idx(char c) { return c - 'A'; };
    void insert(const char* s)
    {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if (ch[u][c] == -1) ch[u][c] = newnode();
            u = ch[u][c];
        }
        val[u] = 1;
    }
    mat tr;
    void build()
    {
        queue<int> q;
        f[rt] = rt;
        for (int c = 0; c < 3; c++)
        {
            if (~ch[rt][c])
                f[ch[rt][c]] = rt, q.push(ch[rt][c]);
            else
                ch[rt][c] = rt;
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            val[u] |= val[f[u]];
            for (int c = 0; c < 3; c++)
            {
                if (~ch[u][c])
                    f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
                else
                    ch[u][c] = ch[f[u]][c];
            }
        }
        mat A(sz, vec(sz));
        for (int u = 0; u < sz; u++)
        {
            for (int c = 0; c < 3; c++)
                if (!val[ch[u][c]])
                    A[u][ch[u][c]]++;
        }
        tr = A;
    }
    ll solve(ll n)
    {
        mat A = Pow(tr, n);
        ll ans = 0;
        for (int i = 0; i < sz; i++) (ans += A[0][i]) %= mod;
        return ans;
    }
} ac;

/*
Trie树
*/
struct Node
{
    int sz, tag;
    Node* ch[2];
    Node() : sz(0), tag(0) { memset(ch, 0, sizeof(ch)); }
    void maintain(){
        sz = 0;
        if (ch[0] != nullptr) sz += ch[0]->sz;
        if (ch[1] != nullptr) sz += ch[1]->sz;
    }
    void pushdown(){
        if (tag == 0) return;
        if (tag & 1){
            swap(ch[0], ch[1]);
            if (ch[0] != nullptr) ch[0]->tag++;
        }
        if (tag > 1){
            if (ch[0] != nullptr) ch[0]->tag += (tag >> 1);
            if (ch[1] != nullptr) ch[1]->tag += (tag >> 1);
        }
        tag = 0;
    }
} mem[maxn];

Node* newNode()
{
    static int tot = 0;
    assert(tot + 1 < maxn);
    return &mem[tot++];
};
struct Trie
{
    void insert(Node*& o, int x, int dep = 30){
        if (o == nullptr) o = newNode();
        if (dep == 0)
        {
            o->sz++;
            return;
        }
        o->pushdown();
        insert(o->ch[x & 1], x >> 1, dep - 1);
        o->maintain();
    }
    Node* merge(Node* o, Node* k, int dep = 30)
    {
        if (o == nullptr) return k;
        if (k == nullptr) return o;
        if (o == nullptr && k == nullptr) return nullptr;
        if (dep == 0)
        {
            o->sz += k->sz;
            return o;
        }
        o->pushdown(), k->pushdown();
        o->ch[0] = merge(o->ch[0], k->ch[0], dep - 1);
        o->ch[1] = merge(o->ch[1], k->ch[1], dep - 1);
        o->maintain();
        return o;
    }
    int query(Node* o, int x, int dep)
    {
        if (o == nullptr) return 0;
        if (dep == 0) return o->sz;
        o->pushdown();
        return query(o->ch[x & 1], x >> 1, dep - 1);
    }
};

/*
    并查集
*/
struct DSU
{
    vector<int> fa;
    DSU() {}
    DSU(int n) { fa.resize(n), iota(fa.begin(), fa.end(), 0); }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    bool same(int x, int y) { return find(x) == find(y); }
    void merge(int x, int y) { fa[find(y)] = find(x); }
};

/*
回文树
*/
ll P[N];
struct Palindromic_Tree
{
    int ch[N][10], f[N], cnt[N], len[N], s[N], val[N];
    int last, sz, n;
    int newnode(int x)
    {
        memset(ch[sz], 0, sizeof(ch[sz]));
        cnt[sz] = 0, len[sz] = x;
        val[sz] = 0;
        return sz++;
    }
    void init()
    {
        sz = 0;
        newnode(0), newnode(-1);
        last = 0, n = 0, s[0] = -1, f[0] = 1;
    }
    int get_fail(int u)
    {
        while (s[n - len[u] - 1] != s[n]) u = f[u];
        return u;
    }
    void add(int c)
    {
        s[++n] = c;
        int u = get_fail(last);
        if (!ch[u][c])
        {
            int np = newnode(len[u] + 2);
            f[np] = ch[get_fail(f[u])][c];
            ch[u][c] = np;
            val[np] = ((P[len[u]] * c % mod + val[u]) * 10 + c) % mod;
        }
        last = ch[u][c];
        cnt[last]++;
    }
    ll count()
    {
        ll ans = 0;
        // for (int i = sz - 1; ~i; i--) cnt[f[i]] += cnt[i];
        for (int i = 0; i < sz; i++) (ans += val[i]) %= mod;
        return ans;
    }
} gao;

/*

*/
struct Edge
{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};
struct Dinic
{
    int n, m, s, t;     //结点数，边数（包括反向弧），源点编号和汇点编号
    vector<Edge> edges; //边表。edge[e]和edge[e^1]互为反向弧
    vector<int> G[maxn]; //邻接表，G[i][j]表示节点i的第j条边在e数组中的序号
    bool vis[maxn];     //BFS使用
    int d[maxn];         //从起点到i的距离
    int cur[maxn];     //当前弧下标
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap)
    {
        edges.pb(Edge(from, to, cap, 0));
        edges.pb(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].pb(m - 2);
        G[to].pb(m - 1);
    }
    bool BFS()
    {
        clr(vis, 0);
        clr(d, 0);
        queue<int> q;
        q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < G[x].size(); i++)
            {
                Edge& e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    ll DFS(int x, int a)
    {
        if (x == t || a == 0) return a;
        ll flow = 0, f;
        for (int& i = cur[x]; i < G[x].size(); i++)
        { //从上次考虑的弧
            Edge& e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }
    ll Maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        ll flow = 0;
        while (BFS())
        {
            clr(cur, 0);
            flow += DFS(s, INF);
        }
        return flow;
    }
} gao;

/*
A*star with spfa
*/
const int maxn = 1 << 10;
vector<PII> G[maxn], rG[maxn];
inline void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        G[i].clear();
        rG[i].clear();
    }
}
inline void add_edge(int u, int v, int w)
{
    G[u].pb(mp(v, w));
    rG[v].pb(mp(u, w));
}
int d[maxn];
bool inq[maxn];
void spfa(int s)
{
    clr(d, 0x3f);
    clr(inq, 0);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (int i = 0; i < rG[u].size(); i++)
        {
            PII& e = rG[u][i];
            int v = e.first, w = e.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                inq[v] = 1;
                q.push(v);
            }
        }
    }
}
struct HeapNode
{
    int v;
    ll g, f;
    HeapNode(int v, ll g, ll f) : v(v), g(g), f(f) {}
    bool operator<(const HeapNode& rhs) const
    {
        return rhs.f < f || (rhs.f == f && rhs.g < g);
    }
};
bool A_star(int s, int t, int k, int tt)
{
    if (s == t) k++;
    if (d[s] == INF) return false;
    priority_queue<HeapNode> q;
    int cnt = 0;
    q.push(HeapNode(s, 0, d[s]));
    while (!q.empty())
    {
        HeapNode tmp = q.top();
        q.pop();
        int u = tmp.v;
        ll g = tmp.g;
        if (u == t) cnt++;
        if (cnt == k) return tmp.g <= tt;
        for (int i = 0; i < G[u].size(); i++)
        {
            PII& e = G[u][i];
            int v = e.first, w = e.second;
            q.push(HeapNode(v, g + w, g + w + d[v]));
        }
    }
    return false;
}

/*
LCT
*/
const int maxn = 1 << 20;
struct LCT
{
    int val[maxn], sum[maxn];
    int rev[maxn], ch[maxn][2], fa[maxn];
    int stk[maxn];
    inline void init(int n)
    {
        for (int i = 1; i <= n; i++) scanf("%d", val + i);
    }
    inline bool isroot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
    inline bool get(int x) { return ch[fa[x]][1] == x; }
    void pushdown(int x)
    {
        if (!rev[x]) return;
        swap(ch[x][0], ch[x][1]);
        if (ch[x][0]) rev[ch[x][0]] ^= 1;
        if (ch[x][1]) rev[ch[x][1]] ^= 1;
        rev[x] ^= 1;
    }
    void pushup(int x)
    {
        sum[x] = val[x] + sum[ch[x][0]] + sum[ch[x][1]];
    }
    void rotate(int x)
    {
        int y = fa[x], z = fa[fa[x]], d = get(x);
        if (!isroot(y)) ch[z][get(y)] = x;
        fa[x] = z;
        ch[y][d] = ch[x][d ^ 1], fa[ch[y][d]] = y;
        ch[x][d ^ 1] = y, fa[y] = x;
        pushup(y), pushup(x);
    }
    void splay(int x)
    {
        int top = 0;
        stk[++top] = x;
        for (int i = x; !isroot(i); i = fa[i]) stk[++top] = fa[i];
        for (int i = top; i; i--) pushdown(stk[i]);
        for (int f; !isroot(x); rotate(x))
            if (!isroot(f = fa[x])) rotate(get(x) == get(f) ? f : x);
    }
    void access(int x)
    {
        int y = 0;
        for (; x; y = x, x = fa[x]) splay(x), ch[x][1] = y, pushup(x);
    }
    int find(int x)
    {
        access(x), splay(x);
        while (ch[x][0]) x = ch[x][0];
        return x;
    }
    void makeroot(int x) { access(x), splay(x), rev[x] ^= 1; }
    void link(int x, int y) { makeroot(x), fa[x] = y, splay(x); }
    void cut(int x, int y) { makeroot(x), access(y), splay(y), fa[x] = ch[y][0] = 0; }
    void update(int x, int v) { val[x] = v, access(x), splay(x); }
    int query(int x, int y)
    {
        makeroot(y), access(x), splay(x);
        return sum[x];
    }
} gao;
