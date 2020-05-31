#include<stdio.h>
int n,adj[100][100],parent[100];

int find(int k)
{
	if(parent[k]==-1)
		return k;
	return find(parent[k]);
}

void unio(int x,int y)
{
	int u=find(x);
	int v=find(y);
	if(u!=v)
		parent[u]=v;
}

int iscycle()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(adj[i][j]==1)
			{
				int u=find(i);
				int v=find(j);
				if(u==v)
					return 1;	
				unio(u,v);
			}
		}
	}
	return 0;
}

int main()
{
	printf("TO DETECT CYCLE IN AN DIRECTED GRAPH \n");
	printf("Enter number Of Vertices : ");
	scanf("%d",&n);
	int ch=1,v1,v2;
	for(int i=0;i<n;i++)
		parent[i]=-1;
	while(ch)
	{
		printf("Enter Vertex 1 and Vertex 2 : ");
		scanf("%d%d",&v1,&v2);
		adj[v1][v2]=1;
		printf("Enter 1 to continue : ");
		scanf("%d",&ch);
	}
	iscycle()?printf("Cycle Found\n"):printf("Cycle Not Found\n");
}
