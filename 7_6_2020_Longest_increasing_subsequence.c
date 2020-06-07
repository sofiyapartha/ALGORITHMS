#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i,a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int dp[n],j;
	dp[0]=1;
	for(i=1;i<n;i++)
	{
		dp[i]=1;
		for(j=0;j<i;j++)
		{
			if(a[i]>a[j] && dp[i]<dp[j]+1)
				dp[i]=dp[j]+1;
		}
	}
	int max=-9999;
	for(i=0;i<n;i++)
	{
		if(dp[i]>max)
			max=dp[i];
	}
	printf("%d",max);
}
