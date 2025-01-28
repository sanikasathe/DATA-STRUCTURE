#include<stdio.h>
int enqueue(int quearr[],int size,int*rear,int front,int data)
{
	if((*rear+1)%size == front)
	{
		return 0;
	}
	else
	{
		quearr[*rear] = data;
		*rear = (*rear+1)%size;
		return 1;
	}
}

int dequeue(int quearr[],int size,int*front,int rear,int *val)
{
	if(*front == rear)
	{
		return 0;
	}
	else{
		*val = quearr[*front];
		*front = (*front+1)%size;
		return 1;
	}
}
int main()
{
	int quearr[100];
	int size,i,choice,data,status;
//	int i=0;
	int front = 0;
	int rear = 0;
	printf("enter the size:");
	scanf("%d",&size);
	
	printf("enter the elements:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&quearr[i]);
		rear = i+1;
	}
	
	
	printf("\n1.enqueue \n2.dequeue \n");
	
	printf("enter your choice:");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1 : printf("enter the element for enqueue:");
				 scanf("%d",&data);
				 
				 status = enqueue(quearr,size,&rear,front,data);
				 if(status == 1)
				 {
				 	printf("The data is enqueued successfully\n");
				 }
				 break;
				 
		case 2 : status = dequeue(quearr,size,&front,rear,&data);
				 if(status == 1)
				 {
				 	printf("The data is dequeued successfully\n");
				 	printf("the dequeued data is:%d",data);
				 }	
				 break;	 
	}
	
}
