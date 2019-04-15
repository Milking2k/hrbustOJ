n = int(input())
ans = n
items = []
while n:
    n -= 1
    a, b = map(int, input().split())
    items.append(b)

mx = int(input())
for item in items:
    if item < mx:
        ans -= 1
    else:
        break

print(ans)