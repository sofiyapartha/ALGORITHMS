#include<stdio.h>

float find_fractional_knapsack(int n,int val[],int wei[],int cap)
{
	float final=0,cur_wei=0;
	int i;
	for( i=0;i<n;i++)
	{
		if(wei[i]<=cap)
		{
			cap-=wei[i];
			final+=val[i];	
		}	
		else
		{
			final+=(float)val[i]*(float)cap/(float)wei[i];
			break;
		}
	}
	return final;
}

int main()
{
	int n,i,j;
	printf("Enter number of items  : ");
	scanf("%d",&n);
	int wei[n],val[i],cap;
	float profit[n];
	printf("Enter n items : ");
	for( i=0;i<n;i++)
	{
		scanf("%d %d",&val[i],&wei[i]);
		profit[i]=(float)val[i]/(float)wei[i];
	}
	printf("Enter  capacity : ");
	scanf("%d",&cap);
	for( i=0;i<n-1;i++)
	{
		for( j=0;j<n-i-1;j++)
		{
			if(profit[j]<profit[j+1])
			{
				float t=profit[j];
				profit[j]=profit[j+1];
				profit[j+1]=t;
				int t1=val[j];
				val[j]=val[j+1];
				val[j+1]=t1;
				t1=wei[j];
				wei[j]=wei[j+1];
				wei[j+1]=t1;
				
			}
		}
		
	}
	printf("Maximun value in knapsack is  : %f\n",find_fractional_knapsack(n,val,wei,cap));
}
