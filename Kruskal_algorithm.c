#include<stdio.h>	
#include<limits.h>
int parent[1000];

int find(int i)
{
	if(parent[i])
		i=parent[i];
	return i;
}

int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}


int main()
{
	int n,n1,v1,v2,co;
	printf("Enter number of vertices   : ");
	scanf("%d",&n);
	int i,j,cost[n][n];
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=9999;
		}
		
	int ne=1,min,total_cost=0,a,b;
	while(ne<n)
	{
		min=INT_MAX;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					a=i;b=j;
				}
			}
		}
		int u=find(a);
		int v=find(b);
		if(uni(u,v))
		{
			printf("%d to %d is %d\n",a,b,min);
			total_cost+=min;
			ne++;
		}
		cost[a][b]=cost[b][a]=9999;
		
		
	}
	printf("Total cost : %d\n",total_cost);
	
}
