//to implement circular queue

#include<stdio.h>
void enqueue();
void dequeue();
void search();
void display();
int n,arr[50],FRONT,REAR,new,search_item,flag,i;
void main()
{
	FRONT=REAR=-1;
	int ch;
	printf("Enter the size of an array :");
	scanf("%d",&n);
	do
	{
	printf("\n\nMENU\n1.ENQUEUE\n2.DEQUEUE\n3.SEARCH\n4.DISPLAY\n5.EXIT\n");
	printf("Enter your choice :");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:enqueue();
		       display();
		       break;
		case 2:dequeue();
		       display();
		       break;
		case 3:search();
		       break;
		case 4:display();
		       break;
		case 5:break;
	}
	}while(ch!=5);
}
void enqueue()
{
	if((REAR+1)%n==FRONT) //if queue is full
		printf("------OVER FLOW------");
	else
	{
	printf("Enter the new item to be inserted :");
	scanf("%d",&new);
	if(FRONT==-1) //checking if queue is empty
	{
		FRONT=0;
		REAR=0;
	}
	else
	{
		REAR=(REAR+1)%n;
	}
	arr[REAR]=new; //inserting new item to the queue
	}
}
void dequeue()
{
	if(FRONT==-1)
	{
		printf("----QUEUE UNDERFLOW------");
	}
	else
	{
		printf("Element dequeued is %d",arr[FRONT]);
		if(FRONT==REAR) // if only one element exists
		{
			FRONT=-1;
			REAR=-1;
		}
		else
		{
			FRONT=(FRONT+1)%n; // if more than one item present
		}
	}
}
void search()
{
	if(FRONT==-1)
	{
		printf("------EMPTY QUEUE-----");
	}
	else
	{
		printf("Enter the item to be searched :");
		scanf("%d",&search_item);
		flag=0;
		for(i=0;i<n;i++)
		{
			if(arr[i]==search_item)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("\n%d is found at position %d",search_item,i+1);
		}
		else
		{
			printf("\n%d is not found in the queue",search_item);
		}
	}
}
void display()
{
	if(FRONT==-1)
	printf("\n-----------Queue is empty----------\n");
	else
	{
	printf("\nELEMENTS IN QUEUE ARE :\n");
	for(i=FRONT;i<=REAR%n;i++)
	{
		printf("%d",arr[i]);
		printf("\t");
	}
	}
}

