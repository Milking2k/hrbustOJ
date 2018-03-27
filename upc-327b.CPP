#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(int month)
{
	return (month % 4 == 0 && month % 100 != 0) || (month % 400 == 0);
}

int main(int argc, char const *argv[])
{
	int start, end;  
    cin >> start >> end; 
  	int ans=0;
    for (int i = start / 10000; i <= end / 10000; i++)  
    {  
        int month = (i % 10) * 10 + (i / 10)%10;  
        int day = ((i / 100)%10)*10 + (i / 1000);  
        switch (month)  
        {  
	        case 1: case 3: case 5: case 7: case 8: case 10: case 12:  
	            if (day <= 31) ans++;break;  
	        case 4:case 6:case 9:case 11:  
		        if (day <= 30) ans++;break;  
	       	case 2:  
		        if (isLeapYear(i)) 
		        {
		        	if (day <= 29)ans++;  
		            else if (day <= 28)ans++;  
		        }break;  
        }  
    }  
	printf("%d\n", ans); 
	return 0;
}