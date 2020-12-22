#include<stdio.h>
int main()
{
	int arr[100],n,i,pos;
	printf("ARRAY DELETION\n\n");
	printf("Enter the size of the array :");
	scanf("%d",&n);
	printf("Enter the elements of the array:");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("ARRAY\n");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
	printf("Enter the position of element to be deleted :");
	scanf("%d",&pos);
	if(pos<0||pos>n)
	{
		printf("INVALID POSITION");
	}
	else
	{
		for(i=pos-1;i<n-1;i++)
		{
			arr[i]=arr[i+1];
		}
		n--;
	printf("RESULTANT ARRAY = ");
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
}
}

