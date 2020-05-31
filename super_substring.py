def shortestSuperstring(A):
        def overlap(s,t):
            for i in range(len(s)):
                w=s[i:]
                l=len(w)
                if w==t[:l]:
                    return s+t[l:]
            return s+t
        A=sorted(A,key=len)
        list1=[]
        res=A[0]
        A=set(A[1:])
        while len(A):
            for i in A:
                c1=overlap(res,i)
                c2=overlap(i,res)
                if len(c1)<len(c2):
                    c=c1
                else:
                    c=c2
                list1.append((c,i))
            x=sorted(list1,key=lambda y:len(y[0]))
            A.remove(x[0][1])
            res=x[0][0]
            list1=[]
        return res
print(shortestSuperstring(["catg","ctaagt","gcta","ttca","atgcatc"]))