/*
输入多项式系数，输出多项式方程
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f

int n;
int a;

int main(int argc, char const *argv[])
{
	// freopen("in.txt","r",stdin);
	while(~scanf("%d",&n))
	{
		for(int i=n;i>=0;i--){
        cin>>a;
        if(a){
            if(i!=n&&a>0)cout<<"+";
            if(abs(a)>1||i==0)cout<<a;
            if(a==-1&&i)cout<<"-";
            if(i>1)cout<<"x^"<<i;
            if(i==1)cout<<"x";
        }
    	}
	}

	return 0;
}

/*

#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;

#define ll long long int
#define INF 0x3f3f3f3f





int main(int argc, char const *argv[])
{
	freopen("in.txt","r",stdin);



	return 0;
}

*/