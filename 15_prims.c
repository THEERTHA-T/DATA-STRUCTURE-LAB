#include<stdio.h>
#include<stdlib.h>
#define INF  9999
#define MAX 20
 
int P[MAX][MAX],MST[MAX][MAX],n;
 
void prims(void);
 
int main()
{
	int i,j;
	printf("\n----PRIMS ALGORITHM----\n\n");
	printf("Enter num of vertices:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&P[i][j]);
	
	prims();
}
void prims()
{
	int cost[MAX][MAX];
	int u,v,min,distance[MAX],source[MAX];
	int visited[MAX],count,i,min_cost,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(P[i][j]==0)
				cost[i][j]=INF;
			else
				cost[i][j]=P[i][j];
				MST[i][j]=0;
		}
		
	distance[0]=0;
	visited[0]=1;
	
	for(i=1;i<n;i++)
	{
		distance[i]=cost[0][i];
		source[i]=0;
		visited[i]=0;
	}
	
	min_cost=0;		//cost of spanning tree
	count=n-1;		//no. of edges to be added
	
	while(count>0)
	{
		//find the vertex at minimum distance from the tree
		min=INF;
		for(i=1;i<n;i++)
			if(visited[i]==0&&distance[i]<min)
			{
				v=i;
				min=distance[i];
			}
			
		u=source[v];
		
		//insert the edge in spanning tree
		MST[u][v]=distance[v];
		MST[v][u]=distance[v];
		count--;
		visited[v]=1;
		
		//updated the distance[] array
		for(i=1;i<n;i++)
			if(visited[i]==0&&cost[i][v]<distance[i])
			{
				distance[i]=cost[i][v];
				source[i]=v;
			}
		
		min_cost=min_cost+cost[u][v];
	}
       printf("\nspanning tree matrix:\n");

        for(i=0;i<n;i++)
        {
                printf("\n");
                for(j=0;j<n;j++)
                        printf("%d\t",MST[i][j]);
        }

        printf("\n\nTotal cost of spanning tree=%d",min_cost);
        printf("\n");

	

}
