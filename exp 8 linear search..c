#include<stdio.h>
int linearsearch(int target,int size,int a[])
{
	int i;
	for(i=0;i<size;i++)
	{
		if(a[i]==target)
		{
			return i;
		}
		
		
		
	}
}
int main()
{
	
	int i,size,target,status,a[size];
	printf("enter size");
	scanf("%d",&size);
	printf("enter elements");
	for(i=0;i<size;i++)
	{
		scanf("%d",a[i]);
	}
	printf("enter element for search");
	scanf("%d",&target);
	status=linearsearch(target,size,a);
	printf("linear search is %d",status);
	if(status)
	{
		printf("search found");
			
	}
	else
	printf("search not found");
}
