#include<stdio.h>
#include<math.h>

int pro(int n,int a[],int k)
{
	int i,j,count=0,p=pow(2,n);
	for(i=0;i<p;i++)
	{
		int mul=1;
		for(j=0;j<n;j++)
		{
			if((i & (1<<j))>0)
				mul*=a[j];
				
		}
		if(mul<k)
			count++;
	}
	return count-1;
	
}

int main()
{
	int k,n;
	printf("Enter n value : ");
	scanf("%d",&n);
	int i,a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter k value  : ");
	scanf("%d",&k);
	printf("%d",pro(n,a,k));
}
