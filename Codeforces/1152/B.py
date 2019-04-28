n = int(input())
stn = str(bin(n))[2:]

# print(stn)
sz = len(stn)
for i in range(1, sz):
    if stn[i] == '0':
        break
    if i + 1 == sz and stn[i] == '1':
        print("0")
        exit()

tot = 0
ans = []
f = 0
while True:
    sz = len(stn)
    for i in range(1, sz):
        if stn[i] == '0':
            ans.append(sz - i)
            print(stn)
            stn = str(bin(int(stn, 2)^(2**(sz-i) - 1))[2:])
            print(stn)
            break
        
    for i in range(1, sz):
        # print(i,sz,stn[i])
        if stn[i] == '0':
            if i + 1 == sz:
                f = 1
            else:
                break
    
    stn = str(bin(int(stn, 2)+1)[2:])
    tot+=2
    if f == 1:
        break

print(tot)
print(*ans)

    