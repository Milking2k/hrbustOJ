n = int(input())
a = list(map(int, input().split()))
a.insert(0, a[1])

cnt = 0
ans = []
for i in range(1, n + 1):
    if a[i] == a[i - 1]:
        cnt += 1
    else:
        ans.append(cnt)
        cnt = 1

ans.append(cnt)
ret = 0
for i in range(1, len(ans)):
    ret = max(ret, min(ans[i], ans[i - 1]))
    
print(ret*2)