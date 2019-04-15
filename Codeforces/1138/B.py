n = int(input())
lc = map(int, list(input()))
la = map(int, list(input()))
artists = zip(lc,la)


na,nb,nc,nd = [],[],[],[] # 0,0 01 10 11
for i, artist in enumerate(artists):
    if sum(artist) == 2:
        nd.append(i + 1)
    elif sum(artist) == 0:
        na.append(i + 1)
    elif artist[0] == 1:
        nc.append(i + 1)
    else:
        nb.append(i + 1)

# print(na,nb,nc,nd)

# d = (nd + nb - c - d) / 2
# a = n/2 - b - c - d

tempn = n / 2
flag = False
a,b,c,d = 0,0,0,0
for i in range(len(nc) + 1):
    for j in range(len(nd) + 1):
        b = len(nd) + len(nb) - 2 * j - i
        if not 0 <= b <= len(nb):
            continue

        a = (tempn - i - j - b)
        if 0 <= a <= len(na):  # even
            a, b, c, d = int(a), int(b), int(c), int(d)
            # print(a,b,c,d)
            ans = []
            for k in range(a):
                ans.append(na[k])
            for k in range(b):
                ans.append(nb[k])
            for k in range(i):
                ans.append(nc[k])
            for k in range(j):
                ans.append(nd[k])
            print(*ans)
            flag = True
            break

    if flag:
        break

if flag == False:
    print(-1)
        
