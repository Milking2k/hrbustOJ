#include<bits/stdc++.h>
using namespace std;
    string multiply(string num1, string num2) {
        string res(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; --j) {
                int temp = (res[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                carry = temp / 10;
                res[i + j + 1] = temp % 10 + '0';
            }
            cout << res << "_";
            res[i] += carry;
            cout << res << endl;
        }
        for (int i = 0; i < num1.size() + num2.size(); ++i) {
            if(res[i]!='0') return res.substr(i);
        }
        return "0";
    }
int main()
{
    // string num2("456");
    // string strs("123");
    // cout << multiply(strs,num2) ;
    vector<int> sss={1,2,3};
    sss.insert(sss.begin(), 0);
    for(auto ss : sss) {
        cout << ss << " ";
    }
    return 0;
}
