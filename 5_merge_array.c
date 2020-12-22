//merging two array and sorting

#include<stdio.h>
int main()
{
	int n1,n2,arr1[20],arr2[20],arr3[50],temp,i,j,k;
	
	//unsorted array1
	
	printf("Enter the size of ARRAY 1 :");
	scanf("%d",&n1);
	printf("Enter the elements of ARRAY 1:\n");
	for(i=0;i<n1;i++)
	{
		scanf("%d",&arr1[i]);
	}
	
	//unsorted array2
	
	printf("Enter the size of ARRAY 2 :");
	scanf("%d",&n2);
	printf("Enter the elements of ARRAY 2 :\n");
	for(j=0;j<n2;j++)
	{
		scanf("%d",&arr2[j]);
	}
	printf("-----ARRAY 1-----\n");
	 for(i=0;i<n1;i++)
        {       
                printf("%d",arr1[i]);
                printf("\t");
        } 
        printf("\n\n-----ARRAY 2-----\n");
         for(j=0;j<n2;j++)
        {
                printf("%d",arr2[j]);
                printf("\t");
        }
	printf("\n");

	//merging unsorted arrays and storing in new array
	
	printf("\nMERGED ARRAY BEFORE SORTING\n ");
	for(k=0;k<n1;k++)
	{
		arr3[k]=arr1[k];	
	}
	for(k=0;k<n2;k++)
	{
		arr3[n1+k]=arr2[k];
	}
        int t=n1+n2;   //total size of merged array
	for(i=0;i<t;i++)
        {
		printf("%d",arr3[i]);
		printf("\t");
	}	

	//sorting merged array
	
	printf("\n");
	for(i=0;i<t;i++)
	{
		for(j=i+1;j<t;j++)
		{
			if(arr3[i]>arr3[j])
			{
				temp=arr3[i];
				arr3[i]=arr3[j];
				arr3[j]=temp;
			}
		}
	}

	printf("\nMERGED ARRAY AFTER SORTING\n");
	for(i=0;i<t;i++)
	{
		printf("%d",arr3[i]);
		printf("\t");
	}	
  	printf("\n");	
}
