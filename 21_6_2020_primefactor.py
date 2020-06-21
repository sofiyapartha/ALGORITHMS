import math
n=int(input())
factor=[]
while n%2==0:
    factor.append(2)
    n=n//2

for i in range(3,int(math.sqrt(n))+1,2):
    while n%i==0:
        factor.append(i)
        n=n//i
num=set(factor)
for i in num:
    print(i,factor.count(i))