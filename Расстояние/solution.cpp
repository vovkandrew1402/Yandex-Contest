n, k = list(map(int, input().split(' ')))
a = map(int, input().split(' '))
 
b = sorted([(v, i) for i, v in enumerate(a)], key = lambda x: x[0])
c = [x[0] for x in b]
 
left, right, s = 0, k, sum(c[1:k+1]) - k * c[0] 
d = [s]
for i in range(n-1):
    s += (c[i] - c[i+1]) * ((right - i) - (i - left + 1))
    while right < n-1:
        delta = (c[right+1] - c[i+1]) - (c[i+1] - c[left])
        if delta < 0:
            left += 1
            right += 1
            s += delta
        else: break
           
    d.append(s) 
    
res=[0] * n
for i in range(n):
       res[b[i][1]] = d[i]
print(*res)