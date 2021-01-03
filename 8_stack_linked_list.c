// implementing stack using linked list

#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int data;
	struct stack* link;
};

struct stack* top=NULL;

void push(void);
void pop(void);
void search(void);
void display();

int main()
{
	int ch;
	printf("STACK USING LINKED LIST\n");
	do
	{
		printf("\nMENU\n1.PUSH OPERATION\n2.POP OPERATION\n3.SEARCH\n4.TRAVERSE\n5.EXIT\n");
		printf("Enter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
			       display();
			       break;
			case 2:pop();
			       display();
			       break;
			case 3:search();
			       display();
			       break;
			case 4:display();
			       break;
			case 5:printf("Exited..!\n");
			       break;
			default:printf("Invalid Choice");
		}
	}while(ch!=5);
}

void push()
{
	int data;
	struct stack*temp=(struct stack*)malloc(sizeof(struct stack)); //creating new node
	printf("Enter Node Data :");
	scanf("%d",&data);
	temp->data=data; 
	if(top==NULL)
	{
		top=temp;
		temp->link=NULL;
	}
	else
	{
		temp->link=top; //point to the previous node
		top=temp;	//point to the last node
	}
}

void pop()
{
	struct stack* temp;
	if(top==NULL)
	{
	//	printf("No Nodes To Delete.\n");
	}
	else
	{
		temp=top; // last element in the stack
		printf("Element Popped is %d",temp->data);
		printf("\n");
		top=top->link;
		temp->link=NULL;
		free(temp); //delete node
	}
}


void search()
{
	if(top==NULL)
	{
		printf("\nEMPTY STACK");
	}
	else
	{
		struct stack* temp;
		int ser;
		printf("Enter element to be searched :");
		scanf("%d",&ser);
		temp=top;
		while(temp!=NULL)
		{
			if(temp->data==ser)
			{
				printf("%d is found in the stack",ser);
				printf("\n");
				return;
			}
			temp=temp->link;
		}
			printf("%d is not found in the stack",ser);
			printf("\n");
	}
}
void display()
{
	struct stack* temp;
	if(top==NULL)
	{
		printf("\nNo Elements To Display\n---STACK EMPTY---\n");
	}
	else
	{
		printf("STACK ELEMENTS ARE\n");
		temp=top;
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->link;
		}
	}
}

		
