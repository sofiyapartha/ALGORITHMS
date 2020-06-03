t=int(input())
while t:
    st=(input())
    n=len(st)
    r=0
    ind=0
    res=[]
    l=[[0]*(n+1)]*(n+1)
    for i in range(1,n+1):
        for j in range(i+1,n+1):
            if st[i-1]==st[j-1] and l[i-1][j-1]<(j-i):
                l[i][j]=l[i-1][j-1]+1
                if l[i][j]>r:
                    r=l[i][j]
                    ind=max(i,ind)
            else:
                l[i][j]=0
    if r>0:
        j=0
        for i in range(ind-r,ind+1):
            res.append(st[i-1])
    result=n-(2*len(res))
    if n==result:
        print("No")
    else:
        print("Yes")
    t=t-1