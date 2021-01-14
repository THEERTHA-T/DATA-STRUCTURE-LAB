//program to implement doubly linked list

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* head=NULL;
struct node* last=NULL;

void add_at_begin(void);
void append(void);
void add_at_loc(void);
void delete_at_begin(void);
void delete_at_end(void);
void delete_at_loc(void);
void search(void);
void display(void);
void back_disp(void);

int main()
{
	int ch;
	printf("\n---DOUBLY LINKED LIST OPERATIONS---\n");
	do
	{
		printf("\n\nMENU\n1.ADD_AT BEGINING\n2.APPEND\n3.ADD_AT_LOC\n4.DELETE_AT_BEGIN\n5.DELETE_AT_END\n6.DELETE_AT_LOC\n7.SEARCH\n8.FORWARD_DISPLAY\n9.BACKWARD_DISPLAY\n10.EXIT\n");
		printf("Enter Your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:add_at_begin();
			       display();
			       break;
			case 2:append();
			       display();
			       break;
			case 3:add_at_loc();
			       display();
			       break;
			case 4:delete_at_begin();
			       display();
			       break;
			case 5:delete_at_end();
			       display();
			       break;
			case 6:delete_at_loc();
			       display();
			       break;
			case 7:search();
			       break;
			case 8:display();
			       break;
			case 9:back_disp();
			       break;
			case 10:printf("EXITING..!\n");
			       break;
			default:printf("INVALID CHOICE\n");
		}
	}while(ch!=10);
}


void add_at_begin(void)
{
	int data;
	struct node* newnode=(struct node*)malloc(sizeof(struct node)); //create new node for storing data
	printf("Enter Node Data :");
	scanf("%d",&data);
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=head; //where head contains the first node
	if(head==NULL)    //initially list is empty
	{
		head=newnode;  //set head and last node to first node
		last=newnode;  
	}
	else
	{
		head->left=newnode;
		newnode->right=head; 
		head=newnode;
	}
	printf("\n---%d Inserted Successfully---\n",data);
}


void append()
{
	int data;
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter Node Data :");
	scanf("%d",&data);
	newnode->data=data;
	newnode->left=last;
	newnode->right=NULL;
	if(last==NULL)
	{
		head=newnode;
		last=newnode;
	}
	else
	{
		last->right=newnode;
		last=newnode;
	}
        printf("\n---%d Inserted Successfully---\n",data);

}


void add_at_loc()
{
	int i;
	int data,pos;
	struct node *newnode, *temp;
	printf("Enter Position of Data :");
	scanf("%d",&pos);
	temp = head;
	newnode = (struct node*)malloc(sizeof(struct node));
	for(i=1;i<pos-1;i++) //traverse untill position is found
	{
		if(temp==NULL)
		{
			break;
		}
		temp=temp->right;
	}
	if(pos==1)
	{
		add_at_begin();
		return;
	}
	else if(temp==last)
	{
		append();
		return;
	}
	else if(temp!=NULL)
	{
		printf("Enter Node Data:");
		scanf("%d",&data);
		newnode->data=data;
		newnode->right=temp->right;
		(temp->right)->left=newnode;
		newnode->left=temp;
		temp->right=newnode;
	        printf("\n---%d Inserted Successfully---\n",data);
		return;
	}
	printf("\n---Enter Valid Position---");
}



void delete_at_begin()
{
	struct node* temp;
	temp=head; //temp pointing to first node
	if(head==NULL) // no item present
	{
		printf("No data to Delete\n");
		return;
	}
	else
	{
		printf("\n---%d Deleted Successfully---",head->data); //delete first item
		printf("\n");
		head=head->right;  //update head to next node
		free(temp); //delete first node from the list
		if(head!=NULL)
		{
			head->left=NULL;
		}
		else
		{ //node consisted only one node
			printf("List Empty.!");
			last=NULL;  //last node and fisrt node is NULL
		}
	}	
}


void delete_at_end()
{
	struct node* temp;
	temp=last; //temp pointing to last node
	if(head==NULL)
	{
		printf("No Data to Delete\n");
		return;
	}
	else
	{
		printf("\n---%d Deleted Successfully---\n",last->data);
		printf("\n");
		last=last->left;
		if(last!=NULL)
		{
			last->right=NULL;
		}
		else
		{
			head=NULL;
	                
		}
		free(temp);
	}
}


void delete_at_loc()
{
	struct node *temp;
	int i,pos;
	printf("Enter Position of Item to Delete :");
	scanf("%d",&pos);
	temp=head;
	for(i=1;i<pos&&temp!=NULL;i++)  //traversing untill position reaches
	{
		temp=temp->right;
	}
	if(pos==1)      //if first position
	{
		delete_at_begin();
	}
	else if(temp==last) //if last position
	{
		delete_at_end();
	}

	else if(temp!=NULL)
	{
                printf("\n---%d Deleted Successfully---\n",temp->data);
		temp->left->right=temp->right;
		temp->right->left=temp->left;
		free(temp); //remove node
	}
	else
	{
		printf("/n---Enter valid position--");
	}

}


void search()
{
	if(head==NULL)
	{
		printf("\nEMPTY LIST");
	}
	else
	{
		struct node* temp;
		int ser;
		printf("Enter element to be searched :");
		scanf("%d",&ser);
		temp=head;
		while(temp!=NULL)
		{
			if(temp->data==ser)
			{
				printf("\n%d is found in the list",ser);
				printf("\n");
				return;
			}
			temp=temp->right;
		}
			printf("\n%d is not found in the list",ser);
			printf("\n");
	}
}


void display()
{
	if(head == NULL)
		printf("\nLinked List is Empty!!");
	else
	{
		printf("\n");
		struct node *link = head;
		while(link->right != NULL)
		{
			printf("%d<-->", link->data);
			link = link->right;
		}
		printf("%d", link->data);
	}

}


void back_disp()
{
	printf("\n\nBACKWARD DISPLAY\n");
	if(last == NULL)
		printf("\nLinked List is Empty!!");
	else
	{
		struct node *link = last;
		while(link->left != NULL){
			printf("%d<-->", link->data);
			link = link->left;
		}
		printf("%d", link->data);
	}
}


