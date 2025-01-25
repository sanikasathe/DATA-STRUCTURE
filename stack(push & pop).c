#include<stdio.h>
int push(int data,int *sttop,int sta[],int stsize)
{
	if(*sttop >= (stsize))
	{
		printf("stack is full\n");
		return 0;
	}
	else{

		(*sttop)++;
		sta[*sttop] = data;
		return 1;
	}		
}

int pop(int *sttop,int stack[],int*retdata)
{
	int val;
	if(*sttop == -1)
	{
		return 0;
	}
	else{
		val = stack[*sttop];
		(*sttop)--;
		*retdata = val;
		return 1;
	}
}	
int main()
{
	int i;
	int status;
	int stack[10];
	int top = -1;
	int size,data ;
	int popped_data;
	printf("enter the size:");
	scanf("%d",&size);
	
	printf("enter the elements in stack:");
    for(i=0;i<size;i++)
    {
    	scanf("%d",&stack[i]);
    	top = i;
    }
	int choice;
    
    printf("\n1.PUSH \n2.POP \n");
    
    printf("enter your choice:");
    scanf("%d",&choice);
        
    switch(choice)
    {
	case 1 : printf("enter the data to push:");
			 scanf("%d",&data);
			 status = push(data,&top,stack,size);
			 if(status==1)
			 {
				printf("\ndata push successfully\n");
			 }
			 break;
		 
	case 2 : status = pop(&top,stack,&popped_data);
			 if(status == 1)
			 {
				 printf("pushed data is :%d",popped_data);
			 }
			 else{
			 	printf("stack is empty\n");
			 }

		 		 
	}	
		
        
        
        
}
