#include<bits/stdc++.h>
char s[1000001];
int main(){
    scanf("%s",s);
    int len=strlen(s),x,i,j;

    for(x=1;x<=len/2;x++)
        if(len%x==0){
            bool ok=1;
            for(i=0;i<len&&ok;i++)
                if(s[i]!=s[i%x])ok=0;
            if(ok)break;
        }

    if(x>len/2)x=len;
    printf("%d\n",x);
    for(i=0;i<x;i++){
        printf("%d",len/x);
        for(j=0;j<len/x;j++)
            printf(" %d",i+j*x);
        putchar('\n');
    }
    return 0;
}