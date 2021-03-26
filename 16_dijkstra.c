#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define INF 99999
void dijkstra(int M[MAX][MAX],int,int);
int main()
{
	int M[MAX][MAX],n,i,j;
	int start;
	printf("\n----DIJKSTRA ALGORITHM-----\n");
	printf("\nEnter number of vertices:");
	scanf("%d",&n);
	printf("Enter the Cost adjacency matrix:");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&M[i][j]);
		}
	}
	printf("\nEnter the starting node:");
	scanf("%d",&start);
	dijkstra(M,n,start);
	return 0;
}
void dijkstra(int M[MAX][MAX],int n,int start)
{
	int cost[MAX][MAX],dist[MAX],visited[MAX],parent[MAX];
	int i,j,count,min,next;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(M[i][j]==0)//check if no edge between i and j
			{
				cost[i][j]=INF;
			}
			else //edge exist
			{
				cost[i][j]=M[i][j];
			}
		}
	}
	for(i=0;i<n;i++)
	{
		dist[i]=cost[start][i];
		parent[i]=start;
		visited[i]=0;
	}
	dist[start]=0;
	visited[start]=1;
	count=1;//initialise with 1
	while(count<n-1) //traversing through the nodes
	{
		min=INF;
		for(i=0;i<n;i++)//get the next node
		{
			if(dist[i]<min && !visited[i])
			{
				min=dist[i];
				next=i;
			}
		}
		visited[next]=1;
		for(i=0;i<n;i++)
		{
			if(!visited[i])
			{
				if((min+cost[next][i])<dist[i])
				{
					dist[i]=min+cost[next][i];
					parent[i]=next;
				}
			}
		}
		count++;
	}

	for(i=0;i<n;i++)
	{
		if(i!=start)
		{
			printf("\nThe shortest distance from %d to  %d is %d ",start,i,dist[i]);
			printf("\nThe path is %d",i);
			j=i;//to complete path
			do
			{
				j=parent[j];
				printf("<--%d",j);
			}while(j!=start);
		}
		printf("\n");
	}
}

