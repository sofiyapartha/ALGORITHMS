n=int(input())
l=list(map(int,input().split()))
m=int(input())
for i in range(m):
    ele=int(input())
    r=0
    count=0
    for i in range(n):
        r+=l[i]
        if r==ele or r>ele:
            print(i+1)
            break
    if i==n-1 and r<ele:
        print("-1")