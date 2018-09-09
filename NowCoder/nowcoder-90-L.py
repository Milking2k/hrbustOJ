import math
x = 1
a = 1
y = 1
b = 1
t = 1
t = input()
while(t):
	x,a,y,b = (int(i) for i in raw_input().split())
	ans1 = a*math.log(x)
	ans2 = b*math.log(y)
	if ans1 == ans2:
		print("Yes")
	else:
		print("No")
	t = t-1