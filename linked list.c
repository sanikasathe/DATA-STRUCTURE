#include<stdio.h>
#include<stdlib.h>
void attachBegin();
int attachMiddle();
void attachEnd();
int detachBegin();
int detachMiddle();
int detachEnd();
int search();
void traverse();
struct node
{
	int data;
	struct node *next;
};

struct node *CreateNode()
{
	struct node *t;
	t=(struct node*)malloc(sizeof(struct node));
	return t;
}

void InitNode(struct node *n)
{
	int val;
	printf("\nenter number :");
	scanf("%d",&val);
	n->data=val;
	n->next=NULL;

}
int main()
{
	int ch,ch2,ch3;
	int ans,value,status;
	struct node *head=NULL;
	struct node *fnode,*nnode;
	
	do
	{
		printf("1.Create node\n2.Add node\n3.Delete node\n.4.Search node\n5.Display all nodes\n6.exit\n");
		printf("Enter choice :");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:fnode=CreateNode();
    			   InitNode(fnode);
	               head=fnode;
				   break;
				   
			case 2:printf("Where you want to add-\n");
			       printf("1.Add at start\n2.Add at middle\n3.Add at End\n");
			       printf("Enter choice :");
			       scanf("%d",&ch2);
			       // Attach Node
			       switch(ch2)
			       {
			       		case 1:nnode=CreateNode();
                               InitNode(nnode);
                               nnode->next=fnode;
						       attachBegin(&head,nnode);
						       break;
			       		case 2:printf("Enter after which number you want to add :");
							   scanf("%d",&value);
    						   nnode=CreateNode();
    						   InitNode(nnode);
   							   attachMiddle(&head,nnode,value);
						       break;
			       		case 3:nnode=CreateNode();
                               InitNode(nnode);
						       attachEnd(&head,nnode);
						       
				   }
			       break;
			case 3:printf("Where you want to delete-\n");
			       printf("1.Delete at start\n2.Delete at middle\n3.Delete at End\n");
			       printf("Enter choice :");
			       scanf("%d",&ch3);
			       // Detach Node
			       switch(ch3)
			       {
			       		case 1:status=detachBegin(&head);
    			   			   if(status==1)
    	 		   	  		        printf("detach begin successful\n");
     			    		   else
				      				printf("Not detached\n");	
						       break;
			       		case 2:printf("Enter number you want to delete :");
    						   scanf("%d",&value);
    						   status=detachMiddle(&head,value);
    						   if(status==1)
    								printf("detach middle successful\n");
    						   else
									printf("Not detached\n");	
						   	   break;
			       		case 3:status=detachEnd(&head);
    			   			   if(status==1)
    	 		   	  		        printf("detach end successful\n");
     			    		   else
				      				printf("Not detached\n");
				   }
			
			       break;
			case 4:printf("enter value to search :");
    			   scanf("%d",&value);
   				   status=search(&head,value);
    			   printf("%d is at %d location",value,status);
			       break;
			case 5:traverse(head);  //  Traverse all node
		}
		printf("\nDo you want to do again (YES-1/NO-0) :");
		scanf("%d",&ans);
	}while(ans==1);
}

void attachBegin(struct node **hptr,struct node *n)
{
	struct node *a;
	
	if(*hptr == NULL)    // linked list is empty
		*hptr=n;
	else
	{
		a=*hptr;
		n->next=a;
		*hptr=n;
	}	
}

int attachMiddle(struct node **hptr,struct node *tmp,int value)
{
	struct node *tn;
	if(*hptr == NULL)    // linked list is empty
		return 0;
	else
	{
		tn=*hptr;
		while( tn->next != NULL)
		{
		
			if( tn->data == value)
			{
				tmp->next=tn->next;
				tn->next=tmp;
				return 1;
			}
		tn=tn->next;
		}
	}
	return 0;
}

void attachEnd(struct node **hptr,struct node *n)
{
	struct node *tn;
	
	if(*hptr==NULL)   // linked list is empty
		*hptr=n;
	else
	{
		tn=*hptr;
        while(tn->next != NULL)
        	tn=tn->next;
        tn->next=n;
	}	
}

int detachBegin(struct node **hptr)
{
	struct node *tmp;
	if(*hptr != NULL)   // linked list is not empty
	{
		tmp=*hptr;
		*hptr=tmp->next;
		free(tmp);
		return 1;		
	}
	else
		return 0;
}

int detachMiddle(struct node **hptr,int value)
{
	struct node *tmp,*prev;
	if(*hptr != NULL)   // linked list is not empty
	{
		tmp=*hptr;
		if(tmp->next == NULL)
		{
			if(tmp->data == value)
				*hptr=NULL;
				return 1;
		}
		else
		{
			prev=tmp;
			tmp=tmp->next;
			while(tmp-> next != NULL)
			{
				if(tmp->data == value)
				{
					prev->next=tmp->next;
					free(tmp);
					return 1;
				}
				tmp=tmp->next;
				prev=prev->next;
			}
		}
	}
	return 0;
}

int detachEnd(struct node **hptr)
{
	struct node *tmp,*prev;
	if(*hptr != NULL)   // linked list is not empty
	{
		tmp=*hptr;
		if(tmp->next == NULL)
			*hptr=NULL;
		else
		{
			prev=tmp;
			tmp=tmp->next;
			while(tmp->next != NULL)
			{
				tmp=tmp->next;
				prev=prev->next;
			}
			prev->next=NULL;
			free(tmp);
			return 1;
		}
	}
	else
		return 0;

}

int search(struct node **hptr,int value)
{
	struct node *tmp;
	if(*hptr != NULL)
	{
		tmp=*hptr;
		while(tmp->next != NULL)
		{
			if(tmp->data == value)
				return tmp;
		}	
	}
	return 0;
}

void traverse(struct node *dis)
{
	while(dis!=NULL)
	{
		printf("%d is stored at %d location\n",dis->data,dis->next);
		dis=dis->next;
	}			
}
