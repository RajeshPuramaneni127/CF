t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split())) 
    max_val = max(p)
    idx = p.index(max_val)
    p = p[:idx+1][::-1] + p[idx+1:]
    print(*p)