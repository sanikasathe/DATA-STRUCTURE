#include<stdio.h>
int insert(int data,int pos,int lar[],int lsz,int *lpos);
int shiftDown(int ar[],int spos,int *lpos);
int del(int pos,int lar[],int *lpos);
int shiftUp(int lar[],int pos,int *lpos);
int search(int ar[],int pos,int lpos);
void traverse(int ar[],int lpos);
int main()
{
	int listar[10]={2,4,5,6,7,8,9};
	int size=10;
	int last=6;
	int status,i;
	int data,pos;
    int ch,ans;
    printf("List :\n");
    for (i=0;i<last+1;i++)
		printf("%d\t",listar[i]);
		
		
	do
	{
		printf("\n1.Insert\n2.Delete\n3.Search\n4.Traverse\n5.Exit\n");
		printf("Enter choice :");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:printf("\nEnter data and postion :");
	               scanf("%d %d",&data,&pos);	
	               pos=pos-1;    
	               status=insert(data,pos,listar,size,&last);
	               printf("\nafter list :\n");
	               for (i=0;i<last+1;i++)
		           printf("%d\t",listar[i]);
		           printf("\n");
		           break;
			case 2:printf("\nEnter position you want to delete :");
	               scanf("%d",&pos);
	               pos=pos-1;		
	               status=del(pos,listar,&last);
	               for (i=0;i<last+1;i++)
		           printf("%d\t",listar[i]);
		           printf("\n");
		           break;
			case 3:printf("Enter postion :");
	               scanf("%d",&pos);
	               data=search(listar,pos,last);
	               printf("\n%d data is at %d postion\n",data,pos);
	               break;
			case 4:traverse(listar,last);
				   printf("\n");
			       break;
			default:printf("You have exited");
			       break;
		}

	}while(ch<5);	
		
}
int insert(int data,int pos,int lar[],int lsz,int *lpos)
{
	if(*lpos==-1)
	{
		if(pos==0)
		{
			lar[pos]=data;
			(*lpos)++;
		}
		else
			return 0;
	}
	else
	{
		if(*lpos<lsz-1)
		{
			if(pos==*lpos+1)
			{
				lar[pos]=data;
				(*lpos)++;
			}
			else
			{
				if(pos<*lpos)
				{
					shiftDown(lar,pos,lpos);
					lar[pos]=data;
					(*lpos)++;
				}
				else
					return 0;
			}
		}
	}
}
int shiftDown(int ar[],int spos,int *lpos)
{
	int cur_pos;
	cur_pos=*lpos;
	
	while(cur_pos>=spos)
	{
		ar[cur_pos+1]=ar[cur_pos];
		cur_pos--;
	}
}
int del(int pos,int lar[],int *lpos)
{
	if(*lpos==-1)
	{
		return 0;
	}
	else
	{
		if(pos==*lpos)
		{
			(*lpos)--;
			return 1;
		}
		else
		{
			if(pos<*lpos)
			{
				shiftUp(lar,pos,lpos);
				(*lpos)--;
				return 1;
			}
			else
				return 0;
	    }
	}
}
int shiftUp(int lar[],int pos,int *lpos)
{
	int cur_pos;
	cur_pos=pos;
	
	while(cur_pos<=*lpos)
	{
		lar[cur_pos]=lar[cur_pos+1];
		cur_pos++;
	}
}
int search(int ar[],int pos,int lpos)
{
	int cur_pos;
	
	if(lpos!=0)
	{
		cur_pos=0;
		while(cur_pos<=lpos)
		{
			if(cur_pos==pos)
				return ar[cur_pos-1];
			cur_pos++;	
		}
	}
}
void traverse(int ar[],int lpos)
{
	int cur_pos;
	
	if(lpos!=0)
	{
		cur_pos=0;
		while(cur_pos<=lpos)
		{
			printf("%d\t",ar[cur_pos]);
			cur_pos++;
		}
	}
}
