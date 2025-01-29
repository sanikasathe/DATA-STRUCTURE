#include<stdio.h>

void enqueue(int[],int *,int *,int, int);
int dequeue(int[],int *,int *,int);
void display(int[],int *,int *);

void main()
{
    int num, choice = 0;
    int MAX = 20;
    int queue[20];
    int front = -1;
    int rear = -1;

    do
    {
        printf("\n Choices:");
        printf("\n1: Enqueue");
        printf("\n2: Dequeue");
        printf("\n3: Display");
        printf("\n4: Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter value to enqueue: ");
                scanf("%d", &num);
                enqueue(queue, &front, &rear, MAX, num);
                break;

            case 2:
                num = dequeue(queue, &front, &rear, MAX);
                if (front != -1) 
                    printf("\nRemoved value = %d", num);
                break;

            case 3:
                display(queue, &front, &rear);
                break;

            case 4:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.");
        }
    } while (choice != 4); 
}

void enqueue(int queue[], int *start, int *end, int MAX, int data)
{
    int front = *start;
    int rear = *end;
    if (rear == MAX - 1 && front == 0)
    {
        puts("\nQueue is full");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            queue[rear] = data;
        }
        else if (front == -1 && rear == MAX - 1)
        {
            front = 0;
            queue[front] = data;
        }
        else
        {
            queue[++rear] = data;
        }
    }
    *start = front;
    *end = rear;
}

int dequeue(int queue[], int *start, int *end, int MAX)
{
    int front = *start;
    int rear = *end;
    int var;

    if (front == -1 && rear == -1)
    {
        puts("\nQueue is empty");
        return -1; 
    }
    else
    {
        var = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        if (front == MAX)
        {
            front = 0;
        }
    }
    *start = front;
    *end = rear;
    return var;
}

void display(int queue[], int *start, int *end)
{
    int front = *start;
    int rear = *end;
    int i;

    if (front == -1 && rear == -1)
    {
        puts("\nQueue is empty");
    }
    else
    {
        printf("\nQueue elements: ");
        for (i = front; i <= rear; ++i)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}

