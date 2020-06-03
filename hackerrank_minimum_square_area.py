t=int(input())
while t:
    n=int(input())
    l=[]
    l1=[]
    for i in range(n):
        a,b=map(int,input().split())
        l.append(a)
        l1.append(b)
    u=abs(max(l)-min(l))
    v=abs(max(l1)-min(l1))
    print(max(u,v)**2)
    t=t-1