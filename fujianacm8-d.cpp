#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
const int maxn=1000005;
char a[maxn],b[maxn];
int Next[maxn];
char c[maxn];
int l1,l2;
void getNext() {
    int j,k;
    j=0;k=-1;Next[0]=-1;
    while(j<l2) {
        if(k==-1 || b[j]==b[k])
            Next[++j]=++k;
        else
            k=Next[k];
    }
}
int kmpindex() {
    int i=0,j=0;
    getNext();
    while(i<l1 && j<l2) {
        if(j==-1 || a[i]==b[j]) {
            i++,j++;
        }
        else {
            j=Next[j];
        }
    }
    if(j==l2) return i-l2;
    else return -1;
}

int kmp_count() {
    int ans=0;
    int i,j=0;
    if(l1==1&&l2==1) {
        if(a[0]==b[0]) return 1;
        else return 0;
    }
    getNext();
    //cout<<"23423"<<endl;
    for(i=0;i<l1;i++) {
        while(j>0 && a[i]!=b[j])
            j=Next[j];
        if(a[i]==b[j])
            j++;
        if(j==l2){
            ans++;
            j=Next[j];
        }
    }
    return ans;
}




int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        cin>>a;
        cin>>b;
        l1=strlen(a);
        l2=strlen(b);
        if(l2==1 && b[0]=='0') {
            puts("Alice");
            continue;
        }
        if(l2>l1) {
            puts("Bob");
            continue;
        }
        int ans=kmpindex();
        for(int i=0;i<l2;i++) {
            c[i]=b[i];
        }
        for(int i=0;i<l2;i++) {
            b[i]=c[l2-1-i];
        }
        int ans1=kmpindex();
        if(ans!=-1)ans++;
        if(ans1!=-1)ans1++;
        if(ans!=-1||ans1!=-1) {
            puts("Alice");
        }
        else {
            puts("Bob");
            continue;
        }
        //cout<<ans<<" "<<ans1<<endl;
    }
}