n,k = map(int, input().split())
a = [[] * k] * n
for i in range(n):
    a[i] = list(map(int, input().split()))

b = [[] * k] * n
for i in range(n):
    b[i] = list(map(int, input().split()))
flag = True

tempa = []
tempb = []
for i in range(n + k):
    tempa.clear()
    tempb.clear()
    if flag == False:
        break
    for j in range(i + 1):
        if (i - j > n - 1) or (j > k - 1):
            continue
        # print("xy:",x,y)
        tempa.append(a[i-j][j])
        tempb.append(b[i-j][j])
    tempa.sort()
    tempb.sort()
    sz = len(tempa)
    
    for j in range(sz):
        if flag and tempa[j] != tempb[j]:
            # print(tempa, tempb)
            flag = False
            break

if flag:
    print("YES")
else:
    print("NO")
    

