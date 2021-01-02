//program for implementing singly linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* link; //self referencial structure
};

struct node* head=NULL; //initial value is null

void append(void);
void add_at_begin(void);
void add_at_loc(void);
void delete(void);
void display(void);
int length();

int data;

void main()
{
	int ch,l;
	printf("---LINKED LIST OPERATIONS---\n");
	do
	{
		printf("\nMENU\n1.APPEND\n2.ADD AT BEGINNING\n3.ADD AT AFTER\n4.LENGTH\n5.DELETE\n6.DISPLAY\n7.EXIT\n");
		printf("Enter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:append();
			       display();
			       break;
			case 2:add_at_begin();
			       display();
			       break;
			case 3:add_at_loc();
			       display();
			       break;
			case 4:l=length();
			        printf("Length of List =%d",l);
			       printf("\n");
			       break;
			case 5:delete();
			       display();
			       break;
			case 6:display();
			       break;
			case 7:break;
			default:printf("Enter valid choice..!");
		}
	}while(ch!=7);
}

void append()
{
	struct node* currentnode=(struct node*)malloc(sizeof(struct node)); //creating and allocating memory for  temporary node 
	printf("Enter the Node Data :");  
	scanf("%d",&data);
	currentnode->data=data;
	currentnode->link=NULL;

	if(head==NULL) // list is empty
	{
		head=currentnode; //head points to the first node
	}
	else //list already contains node
	{
		//creating node for storing new data
		struct node* p=(struct node*)malloc(sizeof(struct node));
		p=head;
		while(p->link!=NULL) //if next node is present
			{
				p=p->link; //p value changed to link of next node
			}
		p->link=currentnode; //address of current node linked to the previous node
	}
}

void add_at_begin()
{
	struct node* currentnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the Node Data :");
	scanf("%d",&data);
	currentnode->data=data;
	currentnode->link=NULL;

	if(head==NULL)
	{
		head=currentnode;
	}
	else
	{
		//struct node* p=(struct node*)malloc(sizeof(struct node));
	
		currentnode->link=head;
		head=currentnode;

	}
}

void add_at_loc()
{
	struct node* temp;//creating new node
        struct node* p;  //point to prev node
        int len,loc,i=1;
        printf("Enter the Position :");
        scanf("%d",&loc);
       len=length();
         temp=(struct node*)malloc(sizeof(struct node));
                printf("Enter the Node Data at position %d :",loc);
                scanf("%d",&data);
                temp->data=data;
                temp->link=NULL;
        if((loc>len+1)||(loc<=0))//invalid location 
        {
                printf("Invalid Location.!");
                printf("\nNOTE-->Length of list = %d",len);
		printf("\n");
        }
      else if(loc==1)
        {
                temp->link=head;
                head=temp;
        } 
        else
        {
                p=head;

             while(i<loc-1) //traversing untill location reaches
                {
                      p=p->link; //move to next node
	              i++;
                }
                temp->link=p->link; //link loc+1 to loc
                p->link=temp;
	}
}

int length()
{
	int count=0;
	if(head==NULL)
	{
		count=0;
	}
	struct node*temp;
	temp=head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	return count;
	printf("\n");
	printf("Length of List =%d",count);
	printf("\n");
}

void delete()
{
	struct node* temp=NULL;
	struct node* p=NULL;
	int data;
	if(head==NULL)
	{
		printf("EMPTY LIST\n");
		return;
	}
	printf("Enter item to be deleted :");
        scanf("%d",&data);

	if(head->data==data) //item found at first node
	{
		if(head->link!=NULL) //list contain more than one node
		{
			head=head->link;
			return;
		}
		else        //list contain only one node
		{
			head=NULL;
			printf("List is empty\n");
			return;
		}
	}

	//item not found in fisrt node and link contain only one node
	
	else if(head->data!=data && head->link==NULL)  
	{
		printf("%d not found in the list",data);
		printf("\n");
		return;
	}
	temp=head;
	while(temp->link!=NULL && temp->data!=data)
	{
		p=temp;
		temp=temp->link;
	}
	if(temp->data==data)
	{
		p->link=p->link->link;
		printf("%d is succefully deleted",data);
		printf("\n");
		free(temp);
	}
	else
	{
		printf("%d not found in the list",data);
		printf("\n");
	}
}
void display()
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp=head;
	if(temp==NULL) // if list is empty
	{
		printf("No Data To Display\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d--->",temp->data);
			temp=temp->link; //assigning link of next node to temp
		}
		printf("\n\n");
	}
}

