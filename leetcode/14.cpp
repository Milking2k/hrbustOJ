#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    if(strs.size()==0 || strs[0].size()==0) return"";
    if(strs.size()==1) return strs[0];
    int len = strs.size();

    size_t maxLen = 0x3f3f3f3f;
    for(auto &str:strs){
        maxLen = min(str.size(), maxLen);
    }

    string temp = strs[0];
    int retLen = 0;
    for (int i = 0; i < maxLen; ++i) {
        int flag = false;
        char now = temp[i];
        for (int j = 1; j < len; ++j){
            if(strs[j][i] != now) return temp.substr(0,retLen);
        }
        retLen++;
    }
    return temp.substr(0, maxLen);
}
int main()
{
    vector<string> strs = {"flower","fl","flight"};
    cout << longestCommonPrefix(strs) ;
    return 0;
}
