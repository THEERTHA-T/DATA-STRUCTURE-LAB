//Implementing Queue operations

#include<stdio.h>
void enqueue(void);
void dequeue(void);
void display(void);
int new,size,ch,i,top,rear,arr[10];
int front=-1;
int rear=-1;
void main()
{
	printf("QUEUE OPERATION\n");
	printf("----------------\n");
	printf("Enter the size of the queue :");
	scanf("%d",&size);
	do
	{
		printf("\nMENU\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT");
		printf("\nEnter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enqueue();
			       display();
			       break;
			 case 2:dequeue();
				display();
				break;
			 case 3:display();
				break;
			 case 4:break;
			 default:printf("invalid entry..!!");
		}
	}while(ch!=4);
}
void enqueue()
{
	if(rear==size-1)
	{
		printf("----------Queue Overflow----------\n");
	}
	else
	{
		if(front==-1)
		front=0;
	        printf("Enter the element to be inserted :");
	        scanf("%d",&new);
	        rear++;
	        arr[rear]=new;
	}
}
void dequeue()
{
	if(front==-1||front>rear)
	{
		printf("----------Queue Underflow-----------\n");
	return;
	}
	else
	{
	        printf("Element popped is %d",arr[front]);
		printf("\n");
                front++;
	}
}
void display()
{
	if(front==-1||front>rear)
	printf("------------Queue is empty----------\n");
	else
	{
	printf("\nELEMENTS IN QUEUE ARE :\n");
	for(i=front;i<=rear;i++)
	{
		printf("%d",arr[i]);
		printf("\n");
	}
	}
}


