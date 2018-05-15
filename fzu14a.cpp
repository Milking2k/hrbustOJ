#include<iostream>  
using namespace std;  
int main(){  
    int x,y,z;  
    while(~scanf("%d%d%d",&x,&y,&z)){  
        int sum=0;  
        sum+=x*3+y*2+z*6;  
        if(sum>=60) printf("I passed the exam.\n%d\n",sum);  
        else printf("Exam was too hard.\n%d\n",sum);  
    }  
}  