#include<bits/stdc++.h>
using namespace std;

int main()
{
    static int y, b, r;
    cin >> y >> b >> r;
    while(b){
        if(y>=b-1 && b+1 <= r){
            cout << 3 * b << endl;
            break;
        }
        else {
            b--;
        }
    }

    return 0;
}