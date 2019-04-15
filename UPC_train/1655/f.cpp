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
const int N = 1e3+7;
int T,n,m;
map<char, int> lev;
bool ufd(char ch)
{
    if(ch != '*' && ch != '+' && ch != '-' && ch != '/' && ch != '%')
        return true;
    return false;
}
string getD(string s)
{
    lev['+'] = 1;
    lev['-'] = 1;
    lev['*'] = 2;
    lev['/'] = 2;
    lev['%'] = 2;
    lev['('] = 3;
    lev[')'] = 3;
    string res("");
    stack<char> st;
    int len = s.length();
    string as = "+-*/%";
    rep(i,0,len) {
        if(isalpha(s[i])) {
            if(i > 0 && isalpha(s[i-1])){
                puts("error");
                return "";
            }
            res.push_back(s[i]);
        }
        else if (s[i] == '(')
        {
            st.push('(');
        }
        else if (s[i] == ')')
        {
            while (st.size() && st.top() != '(')
            {
                res.push_back(st.top());
                st.pop();
            }
            if (st.empty())
            { // 没有找到左括号
                puts("error");
                return "";
            }
            st.pop(); // 弹出左括号但不输出
        }
        else if(st.empty()) {
            if(ufd(s[i])) {
                puts("error");
                return "";
            }
            st.push(s[i]);
        }
        else
        {
            if(as.find(s[i],0) == string::npos) {
                puts("error");
                return "";
            }
            if(i > 0 && !isalpha(s[i-1]) && s[i-1] != ')'){
                puts("error");
                return "";
            }
            while(st.size() && lev[s[i]] >= lev[st.top()]) {
                res.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(st.size()) {
        // printf("::%c::\n", st.top());
        if(st.top() =='('){
            puts("error");
            return "";
        }
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s;
    while(getline(cin, s)){
        int index = 0;
        while((index = s.find(' ',index)) != string::npos)
            s.erase(index, 1);
        // cout << s << endl;
        string res = getD(s);
        if(res.empty()){
            // cout << res << endl;
            continue;
        }
        bool ok = 0;
        string ans("");
        stack<string> st;
        int len = res.length();
        rep(i,0,len) {
            if(isalpha(res[i]))
            {
                string t("");
                t.pb(res[i]);
                // cout << t << "_" << res[i] <<endl;
                st.push(t);
            }
            else
            {
                if(st.empty()) {
                    puts("error");
                    ok = 1;
                    break;
                }
                // cout << st.top() << endl;
                string op2(st.top());
                st.pop();
                if(st.empty()) {
                    puts("error");
                    ok = 1;
                    break;
                }
                string op1(st.top());
                st.pop();
                string temp("(" + op1 + res[i] + op2 + ')');
                // cout << temp << endl;
                st.push(temp);
            }
        }

        if(ok)
            continue;

        if(st.size()!=1) {
            puts("error");
        }
        else{
            int len = st.top().length();
            string ans = st.top();
            // cout << ans << endl;
            if(ans[0] =='('){
                ans.pop_back();
                ans.erase(ans.begin());
            }
            if(ans != s)
            {
                puts("improper");
            }
            else 
            {
                puts("proper");
            }
        }
    }
    return 0;
}
/*
*/