#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct	node *left;
	struct node *right;
}*root=NULL;

struct node *insert(struct node*,int);
struct node *search(struct node*,int);
struct node *delete(struct node*,int);
struct node *max(struct node*);
void preorder(struct node*);
void inorder(struct node*);
void postorder(struct node*);


void main()
{
	int ch,item;
	printf("\n---BINARY SEARCH TREE---\n");
	do
	{
		printf("\nMENU\n1.INSERTION\n2.PREORDER TRAVERSAL\n3.INORDER TRAVERSAL\n4.POSTORDER TRAVERSAL\n5.SEARCH\n6.DELETION\n7.EXIT");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		struct node *temp;
		switch(ch)
		{
			case 1:printf("Enter data to be inserted:");
			       scanf("%d",&item);
			       root=insert(root,item);
			       printf("\n-----%d Inserted Successfully-----\n",item);
			       break;
			case 2:printf("\nPREORDER TRAVERSAL\n---------------------\n");
			       preorder(root);
			       printf("\n");
			       break;
			case 3:printf("\nINORDER TRAVERSAL\n----------------------\n");
			       inorder(root);
			       printf("\n");
			       break;
			case 4:printf("\nPOSTORDER TRAVERSAL\n--------------------\n");
			       postorder(root);
			       printf("\n");
			       break;
			case 5:printf("Enter item to be searched:");
			       scanf("%d",&item);
			       temp=search(root,item);
			       if(temp!=NULL){
				       printf("\nItem found\n");}
			       else {
				       printf("\nItem is not found\n");}
			       break;
			case 6:printf("Enter item to be deleted:");
			       scanf("%d",&item);
			       temp=delete(root,item);
			       break;
			case 7:printf("\nEXITING..!!\n");
			       break;
			default:printf("\nInvalid Choice");
		}
	}while(ch!=7);
}

struct node *insert(struct node* root,int item)
{
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node));
		root->left=NULL;
		root->data=item;
		root->right=NULL;
		return root;
	}
	else
	{
		if(item>root->data)
			root->right=insert(root->right,item);
		else
			root->left=insert(root->left,item);
		return root;
	}
}

void preorder(struct node *p) //DLR
{
	if(root==NULL)
	{
		printf("\nTREE EMPTY\n");
		return;
	}
	printf("%d--->",p->data); //print data part
	if(p->left!=NULL)
		preorder(p->left); //print left child
	if(p->right!=NULL)
		preorder(p->right); //print right child
}

void inorder(struct node *p) //LDR
{
	if(root==NULL)
	{
		printf("\nTREE EMPTY\n");
		return;
	}
	if(p->left!=NULL)
		inorder(p->left); //print left child
	printf("%d--->",p->data); //print data part
	if(p->right!=NULL)
		inorder(p->right); //print right child
}

void postorder(struct node *p) //LRD
{
	if(root==NULL)
	{
		printf("\nTREE EMPTY\n");
		return;
	}
	if(p->left!=NULL)
		postorder(p->left); //print left child
	if(p->right!=NULL)
		postorder(p->right); //print right child
	printf("%d--->",p->data); //print data part
}

struct node *search(struct node *root,int item)
{
	if(root == NULL || root->data == item)
		return root;
	if(item>root->data)
	{
		return search(root->right, item);
	}
	else
	{
		return search(root->left,item);
	}
}

struct node *delete(struct node *root,int item)
{
	if(root==NULL)
		return root;
	if(item<root->data) //item smaller than root node , goto left subtree
	{
		root->left=delete(root->left,item);
	}
	else if(item>root->data) //item greater than root node ,goto right subtree
	{
		root->right=delete(root->right,item);
	}
	else
	{
		struct node *ptr;
		if(root->left==NULL) //have right child
		{
			ptr=root->right;
			free(root);
			return ptr;
		}
		else if(root->right==NULL) //have left child
		{
			ptr=root->left;
			free(root);
			return ptr;
		}
		else
		{
			ptr=max(root->left);
			root->data=ptr->data;
			root->left=delete(root->left,ptr->data);
		}
	}
	return root;
}

struct node *max(struct node *root)
{
	if(root->right != NULL)
		return max(root->right);
	return root;
}




