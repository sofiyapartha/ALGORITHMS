#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main()
{
	int n,i,j;
	printf("Enter number of vertices : ");
	scanf("%d",&n);
	int cost[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=9999;
		}
	}
	int ne=1;
	int vis[n],min,a,b,total_cost=0;
	for(i=0;i<n;i++)
		vis[i]=0;
	vis[0]=1;
	while(ne<n)
	{
		min=INT_MAX;
		for(i=0;i<n;i++)
		{
		
			if(vis[i])
			{
				for(j=0;j<n;j++)
				{
					if(cost[i][j]<min)
					{
						min=cost[i][j];
						a=i;
						b=j;
					}
				}
			}
		}
		if(vis[b]==0)
		{
			printf("%d to %d cost is %d\n",a,b,min);
			total_cost+=min;
			vis[b]=1;
			ne++;
		}
		cost[a][b]=cost[b][a]=9999;
		
	}
	printf("Total Minimum Cost is %d\n",total_cost);
}
