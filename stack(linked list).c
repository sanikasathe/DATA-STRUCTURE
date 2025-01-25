#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct Node* next;
} ;


struct node* createNode(int data) 
{
    struct node* newNode;
	newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int push(struct node** tptr, int data) {
    struct node* tmp;
    tmp = (struct node*)sizeof(struct node);
    if(tmp == NULL)
    {
    	return 0;
	}
	else{
		tmp->data = data;
		tmp->next = *tptr;
		*tptr = tmp;
		return 1;
		
	}
}

struct node* pop(struct node** tptr)
{
	struct node*tmp;
	tmp = (struct node*)sizeof(struct node);
    if (*tptr == NULL)
	 {
        return NULL;
    }
    tmp = *tptr;
    *tptr = tmp->next;
    return tmp;
}

int main() {
    struct node* top;
    top = craeteNode(1);
    top->next = craeteNode(2);
    top->next->next = createNode(3);
    int choice, status;
    int data;
    struct node*retnode;

    printf("\n1. PUSH \n2. POP \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            status = push(&top, data);
            if (status == 1)
			{
                printf("Data pushed successfully\n");
            }
            break;

        case 2:
            retnode = pop(&top);
            if (retnode == NULL) {
                printf("Stack is empty\n");
            } else {
                printf("Popped data: %d\n", retnode->data);
                free(retnode);
            }
            break;
    }


    return 0;
}
