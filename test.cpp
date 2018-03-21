#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  while(getline(cin,s))
  {
    int cont = 1;
    for(int i=s.length()-1;i>=0;i--)
    {
      if (cont && s[i] == '0'){
        continue;
      }else{
        cont =0;
      }
      if (!cont)
      {
        cout << s[i];
      }
    }
    cout << endl;
  }
  return 0;
}