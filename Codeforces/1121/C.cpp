#include<bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
const int N = 1007;

int n, k, finishedCount;
int a[N];

double nowCount = 0.0;

int roundDown(double x) {
    // printf("test: %d\n", ((int)(x * 1000) % 10));
    if(((int)(x * 1000) % 10) < 4) {

        return (int)(x*100);
    }
    return (int)(x*100) + 1;
}

int main()
{
    // double cur;
    // while(cin >> cur) {
    //     cout << roundDown(cur) << endl;
    // }
    cin >> n >> k;
    finishedCount = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int npos = 1;
    int qnsz = min(k, n);
    priority_queue<PII, vector<PII>, greater<PII> > q; // {差值，原值}
    for (npos = 1; npos <= qnsz; ++npos) {
        q.push({a[npos], a[npos]});
    }

    int ans = 0;
    bool finished = false;
    while (!finished)
    {
        PII npair = q.top();
        double nper = (npair.second - npair.first) * 1.0 / npair.second;
        if (roundDown(nper) < roundDown(nowCount)) {
            q.pop();
            for (auto cur : q) {
                
            }

            if(npos <= n)
                q.push({a[npos++], 0});

            ans++;
            nowCount = (++finishedCount) * 1.0 / n;
        }
    }

    return 0;
}