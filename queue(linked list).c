#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* nnode;
    nnode = (struct node*) malloc(sizeof(struct node));
    nnode->data = data;
    nnode->next = NULL;
    return nnode;
}

int enqueue(struct node** front, struct node** rear, int data) {
    struct node* tmp;
    tmp = (struct node*) malloc(sizeof(struct node));
    if (tmp == NULL) {
        return 0;
    }
    tmp->data = data;
    tmp->next = NULL;
    if (*rear == NULL) {
        *rear = tmp;
        *front = tmp;
        (*rear)->next = *front; 
        return 1;
 } else {
        (*rear)->next = tmp;
        *rear = tmp;
        (*rear)->next = *front; 
        return 1;
    }
}

struct node* dequeue(struct node** front, struct node** rear) {
    if (*front == NULL) {
        return NULL;
    } else {
        struct node* tmp = *front;
        if (*front == *rear) {
            *front = NULL;
            *rear = NULL;
        } else {
            *front = tmp->next;
            (*rear)->next = *front;
        }
        return tmp;
    }
}

void print_list(struct node* front) {
    struct node* tmp = front;
    if (tmp == NULL) {
        printf("Queue is empty\n");
        return;
 }
    printf("Queue elements: ");
    do {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    } while (tmp != front);
    printf("\n");
}

int main() {
    struct node* front = NULL;
    struct node* rear = NULL;
	int status;
    // Enqueue three initial values
    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);

    printf("Initial Queue: \n");
    print_list(front);

    int choice;
    int qdata;
    struct node* retnode;

    
        printf("\n1. Enqueue \n2. Dequeue \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

 	switch (choice) 
	{
        case 1:
            printf("Enter the data that you want to insert: ");
            scanf("%d", &qdata);
            status = enqueue(&front, &rear, qdata);
            if (status == 1)
			{
                printf("Data enqueued successfully\n");
                print_list(front);
            }
            break;

        case 2:
            retnode = dequeue(&front, &rear);
            if (retnode == NULL) {
                printf("Queue is empty\n");
            } else {
                printf("Dequeued data = %d\n", retnode->data);
                free(retnode);
            }
            break;

        default:
            printf("Invalid choice\n");
    }
    
    return 0;
}
