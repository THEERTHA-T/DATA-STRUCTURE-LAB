#include<stdio.h>
#include<stdlib.h>

int setU[20],sizeU,setA[20],sizeA,setB[20],sizeB,bitStringA[20],bitStringB[20],bitStringUnion[20],bitStringIntersection[20],bitStringDifference[20];
int flag=0;
void gen_set(int arr[],int size);
void printAllSets();
void printSet(int arr[],int size);
void generate_bitstring();
void generateBitString(int arr[],int size,int bitStringArray[]);
int search(int arr[],int arrSize,int elem);
int checkBitStringStatus();
void setUnion(int arr1[],int arr2[]);
void setIntersection(int arr1[],int arr2[]);
void setDifference(int arr1[],int arr2[]);
void printSetOperationResult(int arr[]);
void printBitStringAsSet(int arr[]);
int checkBitStringStatus();
void main()
{    
	int ch;
	do
	{
		printf("\n1.Enter Universal Set\n2.Enter Set A\n3.Enter Set B\n4.Generate Bit Strings\n5.Union\n6.Intersection\n7.Difference\n8.Print Sets\n9.Exit");
		printf("\nEnter Your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter Size of Universal Set :");
				scanf("%d",&sizeU);
				gen_set(setU,sizeU);
				break;
			case 2:
				printf("Enter size of Set A :");
				scanf("%d",&sizeA);
				gen_set(setA,sizeA);
				break;
			case 3:
				printf("Enter Set B Size:");
				scanf("%d",&sizeB);
				gen_set(setB,sizeB);
				break;
			case 4:
				printf("Generating bit strings\n");
				generate_bitstring();
				break;
			case 5:
				printf("Set union\n");
				if(checkBitStringStatus()==1)
				{
					setUnion(bitStringA,bitStringB);
					printSetOperationResult(bitStringUnion);
				}
				break;
			case 6:
				printf("Set Intersection\n");
				if(checkBitStringStatus()==1)
				{
					setIntersection(bitStringA,bitStringB);
					printSetOperationResult(bitStringIntersection);
				}
				break;
			case 7:
				printf("Set Difference\n");
				if(checkBitStringStatus()==1)
				{
					setDifference(bitStringA,bitStringB);
					printSetOperationResult(bitStringDifference);
				}
				break;
			case 8:
				printAllSets();
				break;
			case 9:break;
		}
	}while(ch!=9);
}

void gen_set(int arr[],int setSize)
{
	printf("\nEnter set items :\n");
	for(int i=0;i<setSize;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("SET = ");
	printf("{");
	for(int i=0;i<setSize;i++)
	{
		printf("%d",arr[i]);
		if(i!=setSize-1)
		{
			printf(",");
		}
	}
	printf("}\n");


}


void printSetOperationResult(int arr[])
{    
	printf("\nUnion Operation (bit string):");
	printSet(arr,sizeU);
	printf("\nOperation Result:");
	printBitStringAsSet(arr);
}

void printBitStringAsSet(int arr[])
{
	int isFirstOutputDoneFlag=0;
	printf("{");
	for(int i=0;i<sizeU;i++)
	{
		if(arr[i]==1)
		{
			if(i!=0 && isFirstOutputDoneFlag==1)
			{
				printf(",");
			}
			printf("%d",setU[i]);
			isFirstOutputDoneFlag=1;
		}       
	}
	printf("}");
}

void setUnion(int arr1[],int arr2[])
{
	for(int i=0;i<sizeU;i++)
	{        
		bitStringUnion[i]=arr1[i]|arr2[i];
	}
}

void setIntersection(int arr1[],int arr2[])
{
	for(int i=0;i<sizeU;i++)
	{        
		bitStringIntersection[i]=arr1[i]&arr2[i];
	}
}
void setDifference(int arr1[],int arr2[])
{
	for(int i=0;i<sizeU;i++)
	{ 
		printf("%d",!arr2[i]) ;     
		bitStringDifference[i]=arr1[i]&(!arr2[i]);
	}
}
int checkBitStringStatus()
{
	if(flag==0)
	{
		printf("\n Generate Bit String first!");
		return 0;
	}
	return 1;
}

void printAllSets()
{   
	printf("\nUniversal Set:");
	printSet(setU,sizeU);
	printf("Set A:");
	printSet(setA,sizeA);
	printf("Set B:");
	printSet(setB,sizeB);
}

void printSet(int arr[],int size)
{
	printf("{");
	for(int i=0;i<size;i++)
	{
		printf("%d",arr[i]);
		if(i!=size-1)
		{
			printf(",");
		}
	}
	printf("}\n");
}

void generate_bitstring()
{
	for(int i=0;i<sizeU;i++)
	{
		bitStringA[i]=0;
		bitStringB[i]=0;
		bitStringUnion[i]=0;
		bitStringIntersection[i]=0;
		bitStringDifference[i]=0;
	}
	generateBitString(setA,sizeA,bitStringA);
	generateBitString(setB,sizeB,bitStringB);
	printf("\nSet A Bit String representation : ");
	printSet(bitStringA,sizeU);
	printf("\nSet B Bit String representation : ");
	printSet(bitStringB,sizeU);
	flag=1;
}

void generateBitString(int arr[],int size,int bitStringArray[])
{
	for(int i=0;i<size;i++)
	{
		int pos=search(setU,sizeU,arr[i]);
		if(pos>=0)
		{
			bitStringArray[pos]=1;
		}        
	}
}

int search(int arr[],int arrSize,int elem)
{
	for(int i=0;i<arrSize;i++)
	{
		if(arr[i]==elem)
			return i;
	}
	return -1;
}
