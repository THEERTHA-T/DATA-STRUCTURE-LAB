#include<stdio.h>
int main()
{
	int arr[10],i,n,pos,new;
	printf("Enter the size of the array :");
	scanf("%d",&n);
	printf("Enter the elements of the array :");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("ARRAY = ");
	for(i=0;i<n;i++)
                printf("%d \t",arr[i]);
        printf("\n");
	printf("Enter the position where element is to be inserted :");
	scanf("%d",&pos);
	printf("Enter the new element :");
	scanf("%d",&new);
	for(i=n-1;i>=pos-1;i--)
		arr[i+1]=arr[i];
	arr[pos-1]=new;
	   printf("RESULTANT ARRAY = ");
        for(i=0;i<=n;i++)
                printf("%d \t",arr[i]);
        printf("\n");

}
