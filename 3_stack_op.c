//program for stack operation

#include<stdio.h>
void push(void);
void pop(void);
void display(void);
int i,size,ch,top,new,arr[100];
int main()
{
	top=-1;
	printf("STACK OPERATION\n");
	printf("----------------\n");
	printf("Enter the size of the stack :");
	scanf("%d",&size);
	do
	{
	printf("\nMENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
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
		case 3:display();
		       break;
		case 4:break;
	}
	}while(ch!=4);
}
void push()
{
  if(top>=size-1)
  {
	  printf("STACK OVERFLOW..!!\n");
  }
  else
  {
	  printf("Enter the new element to be pushed :");
	  scanf("%d",&new);
	  top++;
	  arr[top]=new;
   }
}
void pop()
{
	if(top<=-1)
	{
		printf("STACK UNDERFLOW..!!\n");
	}
	else
	{
		printf("Element popped is %d \n",arr[top]);
		top--;
	}
}
void display()
{
	if(top>=0)
	{
	printf("STACK ELEMENTS ARE LISTED BELOW :\n");
        for(i=top;i>=0;i--)
	{
	printf("%d\n",arr[i]);
	}
        }
        else
        {
	printf("EMPTY STACK..!NO MORE ELEMENTS");
        }
}


